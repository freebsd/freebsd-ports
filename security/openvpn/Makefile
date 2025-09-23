PORTNAME=		openvpn
DISTVERSION=		2.6.15
PORTREVISION?=		0
CATEGORIES=		security net net-vpn
MASTER_SITES=		https://swupdate.openvpn.org/community/releases/ \
			https://build.openvpn.net/downloads/releases/ \
			LOCAL/mandree

MAINTAINER=		mandree@FreeBSD.org
COMMENT?=		Secure IP/Ethernet tunnel daemon
WWW=			https://openvpn.net/community/

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/COPYRIGHT.GPL

BUILD_DEPENDS+=		cmocka>=0:sysutils/cmocka \
			rst2man:textproc/py-docutils@${PY_FLAVOR}

USES=			cpe libtool localbase:ldflags pkgconfig python:build shebangfix ssl
USE_RC_SUBR=		openvpn

SHEBANG_FILES=		sample/sample-scripts/auth-pam.pl \
			sample/sample-scripts/totpauth.py \
			sample/sample-scripts/ucn.pl \
			sample/sample-scripts/verify-cn

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=	--enable-strict --with-crypto-library=openssl
# set PLUGIN_LIBDIR so that unqualified plugin paths are found:
CONFIGURE_ENV+=		PLUGINDIR="${PREFIX}/lib/openvpn/plugins"

CONFLICTS_INSTALL?=	openvpn-devel

SUB_FILES=		pkg-message openvpn-client

USERS=			openvpn
GROUPS=			openvpn

PORTDOCS=		*
PORTEXAMPLES=		*

OPTIONS_DEFINE=		ASYNC_PUSH DCO DOCS EASYRSA EXAMPLES LZ4 LZO PKCS11 SMALL \
			TEST UNITTESTS X509ALTUSERNAME
OPTIONS_DEFAULT=	DCO EASYRSA LZ4 LZO PKCS11 TEST
OPTIONS_EXCLUDE_FreeBSD_13=	DCO # FreeBSD 14 only

ASYNC_PUSH_DESC=	Enable async-push support
DCO_DESC=		Data Channel Offload/ovpn(4) support->README.dco.md
EASYRSA_DESC=		Install security/easy-rsa RSA helper package
LZO_DESC=		LZO compression (incompatible with LibreSSL)
PKCS11_DESC=		Use security/pkcs11-helper, needs same SSL lib!
SMALL_DESC=		Build a smaller executable with fewer features
UNITTESTS_DESC=		Enable unit tests
X509ALTUSERNAME_DESC=	Enable --x509-username-field

ASYNC_PUSH_LIB_DEPENDS=	libinotify.so:devel/libinotify
ASYNC_PUSH_CONFIGURE_ENABLE=	async-push

DCO_CONFIGURE_ENABLE=	dco

EASYRSA_RUN_DEPENDS=	easy-rsa>=0:security/easy-rsa

LZ4_LIB_DEPENDS+=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_ENABLE=	lz4

LZO_LIB_DEPENDS+=	liblzo2.so:archivers/lzo2
LZO_CONFIGURE_ENABLE=	lzo

PKCS11_LIB_DEPENDS=	libpkcs11-helper.so:security/pkcs11-helper
PKCS11_CONFIGURE_ENABLE=	pkcs11

SMALL_CONFIGURE_ENABLE=	small

TEST_ALL_TARGET=	check
TEST_TEST_TARGET_OFF=	check

UNITTESTS_BUILD_DEPENDS=	cmocka>=0:sysutils/cmocka
UNITTESTS_CONFIGURE_ENABLE=	unit-tests

X509ALTUSERNAME_CONFIGURE_ENABLE=	x509-alt-username

.ifdef (LOG_OPENVPN)
CFLAGS+=		-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLZO}
IGNORE_SSL=libressl libressl-devel
IGNORE_SSL_REASON=OpenVPN does not have permission to include LZO with LibreSSL. Compile against OpenSSL, or if your setups support it, disable LZO support
.endif

.if ! ${PORT_OPTIONS:MLZ4} && ! ${PORT_OPTIONS:MLZO}
CONFIGURE_ARGS+=	--enable-comp-stub
.endif

.include <bsd.port.pre.mk>

.if !empty(PORT_OPTIONS:MLZO) && !empty(SSL_DEFAULT:Nbase:Nopenssl*)
# in-depth security net if Mk/Uses/ssl.mk changes
pre-everything::
	@${ECHO_CMD} >&2 "ERROR: OpenVPN is not licensed to combine LZO with other OpenSSL-licensed libraries than OpenSSL. Compile against OpenSSL, or if your setups support it, disable LZO support."
	@${SHELL} -c 'exit 1'
.endif

post-patch:
	${REINPLACE_CMD} -E -i '' -e 's/(user|group) nobody/\1 openvpn/' \
		-e 's/"nobody"( after init)/"openvpn" \1/' \
		${WRKSRC}/sample/sample-config-files/*.conf \
		${WRKSRC}/doc/man-sections/generic-options.rst

pre-configure:
	# just too many of sign-compare; bitwise-instead-of-logical was audited and is intentional,
	# and unused-function affects test---these are developer-side warnings, not relevant on end systems
	${REINPLACE_CMD} 's/-Wsign-compare/-Wno-unknown-warning-option -Wno-sign-compare -Wno-bitwise-instead-of-logical -Wno-unused-function/' ${WRKSRC}/configure
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
.if !empty(SSL_DEFAULT:Mlibressl*)
	@${ECHO} "### --------------------------------------------------------- ###"
	@${ECHO} "### NOTE that libressl is not primarily supported by OpenVPN  ###"
	@${ECHO} "### Do not report bugs without fixes/patches unless the issue ###"
	@${ECHO} "### can be reproduced with a released OpenSSL version.        ###"
	@${ECHO} "### --------------------------------------------------------- ###"
	@sleep 10
.endif

post-configure:
	${REINPLACE_CMD} '/^CFLAGS =/s/$$/ -fPIC/' \
	 	${WRKSRC}/src/plugins/auth-pam/Makefile \
	 	${WRKSRC}/src/plugins/down-root/Makefile

# sanity check that we don't inherit incompatible SSL libs through,
# for instance, pkcs11-helper:
_tlslibs=libssl libcrypto
post-build:
	@a=$$(LC_ALL=C ldd -f '%o\n' ${WRKSRC}/src/openvpn/openvpn \
	|	${SORT} -u) ; set -- $$(for i in ${_tlslibs} ; do ${PRINTF} '%s\n' "$$a" | ${GREP} $${i}.so | wc -l ; done | ${SORT} -u) ;\
	if test "$$*" != "1" ; then ( set -x ; ldd -a ${WRKSRC}/src/openvpn/openvpn ) ; ${PRINTF} '%s\n' "$$a" ; ${ECHO_CMD} >&2 "${.CURDIR} FAILED: either of ${_tlslibs} libraries linked multiple times" ; ${RM} ${BUILD_COOKIE} ; exit 1 ; fi

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/openvpn-plugin-auth-pam.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/openvpn-plugin-down-root.so
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/pull-resolv-conf/client.up ${STAGEDIR}${PREFIX}/libexec/openvpn-client.up
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/pull-resolv-conf/client.down ${STAGEDIR}${PREFIX}/libexec/openvpn-client.down
	${INSTALL_SCRIPT} ${WRKDIR}/openvpn-client ${STAGEDIR}${PREFIX}/sbin/openvpn-client
	${MKDIR} ${STAGEDIR}${PREFIX}/include

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for i in AUTHORS ChangeLog Changes.rst CONTRIBUTING.rst PORTS README README.ec
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.if !empty(PORT_OPTIONS:MDCO)
	${INSTALL_MAN} ${WRKSRC}/README.dco.md ${STAGEDIR}${DOCSDIR}/
.endif

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)
	${CHMOD} ${BINMODE} ${STAGEDIR}${EXAMPLESDIR}/sample-scripts/*
	${RM} ${STAGEDIR}${EXAMPLESDIR}/sample-config-files/*.orig

.include <bsd.port.post.mk>
