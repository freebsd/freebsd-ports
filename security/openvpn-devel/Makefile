PORTNAME=	openvpn
DISTVERSION=	g20250629
PORTREVISION=	0  # leave in even if 0 to avoid accidental PORTEPOCH bumps
PORTEPOCH=	1
CATEGORIES=	security net net-vpn
PKGNAMESUFFIX=	-devel

MAINTAINER=	gert@greenie.muc.de
# let's use ?= in spite of portlint WARNings because this might become
# security/openvpn one day which would then have a slave port:
COMMENT?=	Secure IP/Ethernet tunnel daemon
WWW=		https://openvpn.net/community/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.GPL

BUILD_DEPENDS+=	cmocka>=0:sysutils/cmocka \
		rst2man:textproc/py-docutils@${PY_FLAVOR}
LIB_DEPENDS+=	liblzo2.so:archivers/lzo2

USES=		autoreconf cpe libtool pkgconfig python:build shebangfix tar:xz
IGNORE_SSL=	libressl libressl-devel
USE_GITLAB=	yes
GL_TAGNAME=	df4863aa0e43544ea82ab9d98966a03a95c62334
USE_RC_SUBR=	openvpn

SHEBANG_FILES=	sample/sample-scripts/auth-pam.pl \
		sample/sample-scripts/totpauth.py sample/sample-scripts/ucn.pl \
		sample/sample-scripts/verify-cn

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=		--enable-strict
# set PLUGIN_LIBDIR so that unqualified plugin paths are found:
CONFIGURE_ENV+=			PLUGINDIR="${PREFIX}/lib/openvpn/plugins"

# let OpenVPN's configure script pick up the requisite libraries,
# but do not break the plugin build if an older version is installed
.ifdef (LOG_OPENVPN)
CFLAGS+=	-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

CPPFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include \
		-DCONFIGURE_GIT_REVISION='\"${GL_TAGNAME}\"' \
		-DCONFIGURE_GIT_FLAGS=
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL?=	openvpn-2.*

SUB_FILES=	openvpn-client pkg-message

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DCO DOCS EASYRSA EXAMPLES LZ4 PKCS11 SMALL TEST \
			X509ALTUSERNAME
OPTIONS_DEFAULT=	DCO EASYRSA LZ4 OPENSSL TEST
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	MBEDTLS OPENSSL
OPTIONS_EXCLUDE_FreeBSD_13=	DCO # FreeBSD 14 only

# option descriptions and interdependencies

DCO_DESC=		Build with Data Channel Offload (ovpn(4)) support
EASYRSA_DESC=		Install security/easy-rsa RSA helper package
MBEDTLS_DESC=		SSL/TLS via mbedTLS (lacks TLS v1.3)
PKCS11_DESC=		Use security/pkcs11-helper
SMALL_DESC=		Build a smaller executable with fewer features
X509ALTUSERNAME_DESC=	Enable --x509-username-field (OpenSSL only)

# option implementations

DCO_CONFIGURE_OFF=	--disable-dco

EASYRSA_RUN_DEPENDS=	easy-rsa>=0:security/easy-rsa

LZ4_LIB_DEPENDS+=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_OFF=	--disable-lz4

MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls2
MBEDTLS_CONFIGURE_ON=	--with-crypto-library=mbedtls

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-crypto-library=openssl

PKCS11_PREVENTS=		MBEDTLS
PKCS11_PREVENTS_MSG=		OpenVPN cannot use pkcs11-helper with mbedTLS. \
				Disable PKCS11, or use OpenSSL instead
PKCS11_LIB_DEPENDS=		libpkcs11-helper.so:security/pkcs11-helper
PKCS11_CONFIGURE_ENABLE=	pkcs11

SMALL_CONFIGURE_ON=	--enable-small

TEST_ALL_TARGET=	check
TEST_TEST_TARGET_OFF=	check

X509ALTUSERNAME_PREVENTS=		MBEDTLS
X509ALTUSERNAME_PREVENTS_MSG=		OpenVPN ${DISTVERSION} cannot use \
					--x509-username-field with mbedTLS. \
					Disable X509ALTUSERNAME, or use OpenSSL \
					instead
X509ALTUSERNAME_CONFIGURE_ENABLE=	x509-alt-username

pre-configure:
.ifdef (LOG_OPENVPN)
	@${ECHO} "Building with LOG_OPENVPN=${LOG_OPENVPN}"
.else
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "      LOG_OPENVPN={Valid syslog facility, default LOG_DAEMON}"
	@${ECHO} "      EXAMPLE:  make LOG_OPENVPN=LOG_LOCAL6"
	@${ECHO} ""
.endif

post-configure:
	${REINPLACE_CMD} '/^CFLAGS =/s/$$/ -fPIC/' \
	    ${WRKSRC}/src/plugins/auth-pam/Makefile \
	    ${WRKSRC}/src/plugins/down-root/Makefile

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMBEDTLS}
_tlslibs=	libmbedtls libmbedx509 libmbedcrypto
.else
# OpenSSL
_tlslibs=	libssl libcrypto
.endif

# sanity check that we don't inherit incompatible SSL libs through,
# for instance, pkcs11-helper:
post-build:
	@a=$$(LC_ALL=C ldd -f '%o\n' ${WRKSRC}/src/openvpn/openvpn \
	|	${SORT} -u) ; set -- $$(for i in ${_tlslibs} ; do ${PRINTF} '%s\n' "$$a" | ${GREP} $${i}.so | wc -l ; done | ${SORT} -u) ;\
	if test "$$*" != "1" ; then ${ECHO_CMD} >&2 "${.CURDIR} FAILED: either of ${_tlslibs} libraries linked multiple times" ; ${PRINTF} '%s\n' "$$a"; ${RM} ${BUILD_COOKIE} ; exit 1 ; fi

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/openvpn-plugin-auth-pam.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/openvpn-plugin-down-root.so
	${INSTALL_SCRIPT} ${WRKDIR}/openvpn-client ${STAGEDIR}${PREFIX}/sbin/openvpn-client
	${MKDIR} ${STAGEDIR}${PREFIX}/include

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for i in AUTHORS ChangeLog PORTS
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)
	${CHMOD} ${BINMODE} ${STAGEDIR}${EXAMPLESDIR}/sample-scripts/*
	${RM} ${STAGEDIR}${EXAMPLESDIR}/sample-config-files/*.orig

.include <bsd.port.mk>
