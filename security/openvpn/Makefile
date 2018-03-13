# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=		openvpn
DISTVERSION=		2.4.5
PORTREVISION?=		0
CATEGORIES=		security net
MASTER_SITES=		https://swupdate.openvpn.net/community/releases/ \
			https://build.openvpn.net/downloads/releases/

MAINTAINER=		mandree@FreeBSD.org
COMMENT?=		Secure IP/Ethernet tunnel daemon

LICENSE=		GPLv2

CONFLICTS_INSTALL?=	openvpn-2.[!4].* openvpn-[!2].* openvpn-beta-[0-9]* openvpn-devel-[0-9]* openvpn-mbedtls-[0-9]*

GNU_CONFIGURE=		yes
USES=			cpe libtool pkgconfig shebangfix tar:xz
SHEBANG_FILES=		sample/sample-scripts/verify-cn \
			sample/sample-scripts/auth-pam.pl \
			sample/sample-scripts/ucn.pl
CONFIGURE_ARGS+=	--enable-strict
# avoid picking up CMAKE, we don't have cmocka in the tarballs..
CONFIGURE_ENV+=		ac_cv_prog_CMAKE= CMAKE=

# let OpenVPN's configure script pick up the requisite libraries,
# but do not break the plugin build if an older version is installed
CPPFLAGS+=		-I${WRKSRC}/include -I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

# set PLUGIN_LIBDIR so that unqualified plugin paths are found:
CPPFLAGS+=		-DPLUGIN_LIBDIR=\\\"${PREFIX}/lib/openvpn/plugins\\\"

OPTIONS_DEFINE=		PKCS11 EASYRSA DOCS EXAMPLES X509ALTUSERNAME \
			TEST LZ4 SMALL TUNNELBLICK
OPTIONS_DEFAULT=	EASYRSA OPENSSL TEST LZ4
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL MBEDTLS
PKCS11_DESC=		Use security/pkcs11-helper
EASYRSA_DESC=		Install security/easy-rsa RSA helper package
MBEDTLS_DESC=		SSL/TLS via mbedTLS
TUNNELBLICK_DESC=	Tunnelblick XOR scramble patch (READ HELP!)
X509ALTUSERNAME_DESC=	Enable --x509-username-field (OpenSSL only)
SMALL_DESC=		Build a smaller executable with fewer features

EASYRSA_RUN_DEPENDS=	easy-rsa>=0:security/easy-rsa

PKCS11_LIB_DEPENDS=	libpkcs11-helper.so:security/pkcs11-helper
PKCS11_CONFIGURE_ENABLE=	pkcs11
PKCS11_PREVENTS=	MBEDTLS
PKCS11_PREVENTS_MSG=	OpenVPN cannot use pkcs11-helper with mbedTLS. Disable PKCS11, or use OpenSSL instead

TUNNELBLICK_EXTRA_PATCHES=	${FILESDIR}/extra-tunnelblick-openvpn_xorpatch

X509ALTUSERNAME_CONFIGURE_ENABLE=	x509-alt-username

X509ALTUSERNAME_PREVENTS=	MBEDTLS
X509ALTUSERNAME_PREVENTS_MSG=	OpenVPN ${DISTVERSION} cannot use --x509-username-field with mbedTLS. Disable X509ALTUSERNAME, or use OpenSSL instead

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-crypto-library=openssl

LZ4_CONFIGURE_OFF=	--disable-lz4

SMALL_CONFIGURE_ON=	--enable-small

MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MBEDTLS_CONFIGURE_ON=	--with-crypto-library=mbedtls

USE_RC_SUBR=		openvpn
USE_LDCONFIG=		${PREFIX}/lib

SUB_FILES=		pkg-message openvpn-client

.ifdef (LOG_OPENVPN)
CFLAGS+=		-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

LIB_DEPENDS+=		liblzo2.so:archivers/lzo2

LZ4_LIB_DEPENDS+=	liblz4.so:archivers/liblz4

PORTDOCS=		*
PORTEXAMPLES=		*

TEST_ALL_TARGET=	check
TEST_TEST_TARGET_OFF=	check

# XXX Please remove this compatibility wrapper after 2017Q2 is branched.
.ifdef(WITHOUT_CHECK)
WARNING+=	"${.CURDIR}: WITHOUT_CHECK is deprecated, please use WITHOUT=TEST or OPTIONS_UNSET=TEST."
WITHOUT+=	TEST
.endif

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
_tlslibs=libmbedtls libmbedx509 libmbedcrypto
.else
# OpenSSL
_tlslibs=libssl libcrypto
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
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/pull-resolv-conf/client.up ${STAGEDIR}${PREFIX}/libexec/openvpn-client.up
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/pull-resolv-conf/client.down ${STAGEDIR}${PREFIX}/libexec/openvpn-client.down
	@${REINPLACE_CMD} 's|resolvconf -p -a|resolvconf -a|' ${STAGEDIR}${PREFIX}/libexec/openvpn-client.up
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

.include <bsd.port.mk>
