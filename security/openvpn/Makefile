# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=		openvpn
DISTVERSION=		2.5.0
PORTREVISION?=		0
CATEGORIES=		security net net-vpn
MASTER_SITES=		https://swupdate.openvpn.org/community/releases/ \
			https://build.openvpn.net/downloads/releases/ \
			LOCAL/mandree

MAINTAINER=		mandree@FreeBSD.org
COMMENT?=		Secure IP/Ethernet tunnel daemon

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/COPYRIGHT.GPL

USES=			cpe libtool localbase:ldflags pkgconfig shebangfix tar:xz
IGNORE_SSL=		libressl libressl-devel
USE_RC_SUBR=		openvpn

SHEBANG_FILES=		sample/sample-scripts/verify-cn \
			sample/sample-scripts/auth-pam.pl \
			sample/sample-scripts/ucn.pl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-strict
# set PLUGIN_LIBDIR so that unqualified plugin paths are found:
CONFIGURE_ENV+=		PLUGINDIR="${PREFIX}/lib/openvpn/plugins"

CONFLICTS_INSTALL?=	openvpn-2.[!5].* openvpn-[!2].* openvpn-beta-[0-9]* openvpn-devel-[0-9]* openvpn-mbedtls-[0-9]*

SUB_FILES=		pkg-message openvpn-client

PORTDOCS=		*
PORTEXAMPLES=		*

# avoid picking up CMAKE, we don't have cmocka in the tarballs.
CONFIGURE_ENV+=		ac_cv_prog_CMAKE= CMAKE=

OPTIONS_DEFINE=		PKCS11 EASYRSA DOCS EXAMPLES X509ALTUSERNAME \
			TEST LZ4 LZO SMALL TUNNELBLICK ASYNC_PUSH
OPTIONS_DEFAULT=	EASYRSA OPENSSL TEST LZ4 LZO
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL MBEDTLS
ASYNC_PUSH_DESC=	Enable async-push support
EASYRSA_DESC=		Install security/easy-rsa RSA helper package
MBEDTLS_DESC=		SSL/TLS via mbedTLS (lacks TLS v1.3)
PKCS11_DESC=		Use security/pkcs11-helper (OpenSSL only)
SMALL_DESC=		Build a smaller executable with fewer features
TUNNELBLICK_DESC=	Tunnelblick XOR scramble patch (READ HELP!)
X509ALTUSERNAME_DESC=	Enable --x509-username-field (OpenSSL only)

ASYNC_PUSH_LIB_DEPENDS=	libinotify.so:devel/libinotify
ASYNC_PUSH_CONFIGURE_ENABLE=	async-push

EASYRSA_RUN_DEPENDS=	easy-rsa>=0:security/easy-rsa

LZ4_LIB_DEPENDS+=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_ENABLE=	lz4

LZO_LIB_DEPENDS+=	liblzo2.so:archivers/lzo2
LZO_CONFIGURE_ENABLE=	lzo

MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MBEDTLS_CONFIGURE_ON=	--with-crypto-library=mbedtls

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-crypto-library=openssl

PKCS11_PREVENTS=	MBEDTLS
PKCS11_PREVENTS_MSG=	OpenVPN cannot use pkcs11-helper with mbedTLS. Disable PKCS11, or use OpenSSL instead
PKCS11_LIB_DEPENDS=	libpkcs11-helper.so:security/pkcs11-helper
PKCS11_CONFIGURE_ENABLE=	pkcs11

SMALL_CONFIGURE_ENABLE=	small

TEST_ALL_TARGET=	check
TEST_TEST_TARGET_OFF=	check

TUNNELBLICK_EXTRA_PATCHES=	${FILESDIR}/extra-tunnelblick-openvpn_xorpatch:-p1

X509ALTUSERNAME_PREVENTS=	MBEDTLS
X509ALTUSERNAME_PREVENTS_MSG=	OpenVPN ${DISTVERSION} cannot use --x509-username-field with mbedTLS. Disable X509ALTUSERNAME, or use OpenSSL instead
X509ALTUSERNAME_CONFIGURE_ENABLE=	x509-alt-username

.ifdef (LOG_OPENVPN)
CFLAGS+=		-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMBEDTLS}
_tlslibs=libmbedtls libmbedx509 libmbedcrypto
.else
# OpenSSL
_tlslibs=libssl libcrypto
.endif

.if ! ${PORT_OPTIONS:MLZ4} && ! ${PORT_OPTIONS:MLZO}
CONFIGURE_ARGS+=	--enable-comp-stub
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
	@: # workaround for 2.5.0 only XXX FIXME remove after 2.5.0
	${INSTALL_MAN} ${WRKSRC}/doc/openvpn.8 ${STAGEDIR}${MANPREFIX}/man/man8

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for i in AUTHORS ChangeLog PORTS
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)
	${CHMOD} ${BINMODE} ${STAGEDIR}${EXAMPLESDIR}/sample-scripts/*

.include <bsd.port.mk>
