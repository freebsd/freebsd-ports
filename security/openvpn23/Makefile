# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=		openvpn
DISTVERSION=		2.3.14
CATEGORIES=		security net
MASTER_SITES=		http://swupdate.openvpn.net/community/releases/ \
			http://build.openvpn.net/downloads/releases/
PKGNAMESUFFIX?=		23

MAINTAINER=		mandree@FreeBSD.org
COMMENT?=		Secure IP/Ethernet tunnel daemon

DEPRECATED=		Replaced by new upstream relesae 2.4.x
EXPIRATION_DATE=	2017-03-31

LICENSE=		GPLv2

CONFLICTS_INSTALL=	openvpn-2.[!3].* openvpn-[!2].* openvpn-beta-[0-9]* openvpn-devel-[0-9]*

GNU_CONFIGURE=		yes
USES=			cpe libtool pkgconfig shebangfix tar:xz
SHEBANG_FILES=		sample/sample-scripts/verify-cn \
			sample/sample-scripts/auth-pam.pl \
			sample/sample-scripts/ucn.pl
# avoid picking up CMAKE, we don't have cmocka anyways.
CONFIGURE_ENV+=		ac_cv_prog_CMAKE= CMAKE=

# let OpenVPN's configure script pick up the requisite libraries,
# but do not break the plugin build if an older version is installed
CPPFLAGS+=		-I${WRKSRC}/include -I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

# set PLUGIN_LIBDIR so that unqualified plugin paths are found:
CPPFLAGS+=		-DPLUGIN_LIBDIR=\\\"${PREFIX}/lib/openvpn/plugins\\\"

OPTIONS_DEFINE=		PKCS11 EASYRSA DOCS EXAMPLES X509ALTUSERNAME \
			TUNNELBLICK TEST
OPTIONS_DEFAULT=	EASYRSA OPENSSL TEST
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL POLARSSL
# The following feature is always enabled since 2.3.9 and no longer optional.
# PW_SAVE_DESC=		Interactive passwords may be read from a file
PKCS11_DESC=		Use security/pkcs11-helper
EASYRSA_DESC=		Install security/easy-rsa RSA helper package
POLARSSL_DESC=		SSL/TLS via mbedTLS 1.3.X (not 2.x)
TUNNELBLICK_DESC=	Tunnelblick XOR scramble patch (READ HELP!)
X509ALTUSERNAME_DESC=	Enable --x509-username-field (OpenSSL only)

EASYRSA_RUN_DEPENDS=	easy-rsa>=0:security/easy-rsa

PKCS11_LIB_DEPENDS=	libpkcs11-helper.so:security/pkcs11-helper
PKCS11_CONFIGURE_ENABLE=	pkcs11

TUNNELBLICK_EXTRA_PATCHES=	${FILESDIR}/extra-tunnelblick-openvpn_xorpatch

X509ALTUSERNAME_CONFIGURE_ENABLE=	x509-alt-username

X509ALTUSERNAME_PREVENTS=	POLARSSL
X509ALTUSERNAME_PREVENTS_MSG=	OpenVPN ${DISTVERSION} cannot use --x509-username-field with PolarSSL. Disable X509ALTUSERNAME, or use OpenSSL instead

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-crypto-library=openssl

# Pin the libmbedtls version because the 2.3.x port can't work with .so.10 or
# newer from the security/mbedtls package. Upstream works in progress
# for OpenVPN 2.4 to use mbedTLS 2.X.
POLARSSL_LIB_DEPENDS=	libmbedtls.so.9:security/polarssl13
POLARSSL_CONFIGURE_ON=	--with-crypto-library=polarssl

USE_RC_SUBR=		openvpn
USE_LDCONFIG=		${PREFIX}/lib

SUB_FILES=		pkg-message openvpn-client

.ifdef (LOG_OPENVPN)
CFLAGS+=		-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

LIB_DEPENDS+=		liblzo2.so:archivers/lzo2

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
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)
	${CHMOD} ${BINMODE} ${STAGEDIR}${EXAMPLESDIR}/sample-scripts/*

.include <bsd.port.mk>
