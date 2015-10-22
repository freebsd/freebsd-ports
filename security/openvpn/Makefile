# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=		openvpn
DISTVERSION=		2.3.8
CATEGORIES=		security net
MASTER_SITES=		http://swupdate.openvpn.net/community/releases/ \
			http://build.openvpn.net/downloads/releases/

MAINTAINER=		mandree@FreeBSD.org
COMMENT?=		Secure IP/Ethernet tunnel daemon

LICENSE=		GPLv2

CONFLICTS_INSTALL=	openvpn-2.[!3].* openvpn-[!2].* openvpn-beta-[0-9]* openvpn-devel-[0-9]*

GNU_CONFIGURE=		yes
USES=			cpe libtool pkgconfig shebangfix tar:xz
SHEBANG_FILES=		sample/sample-scripts/verify-cn \
			sample/sample-scripts/auth-pam.pl \
			sample/sample-scripts/ucn.pl

# let OpenVPN's configure script pick up the requisite libraries:
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

# set PLUGIN_LIBDIR so that unqualified plugin paths are found:
CPPFLAGS+=		-DPLUGIN_LIBDIR=\\\"${PREFIX}/lib/openvpn/plugins\\\"

OPTIONS_DEFINE=		PW_SAVE PKCS11 EASYRSA DOCS EXAMPLES X509ALTUSERNAME
OPTIONS_DEFAULT=	EASYRSA OPENSSL
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL POLARSSL
PW_SAVE_DESC=		Interactive passwords may be read from a file
PKCS11_DESC=		Use security/pkcs11-helper
EASYRSA_DESC=		Install security/easy-rsa RSA helper package
POLARSSL_DESC=		SSL/TLS support via PolarSSL 1.2
X509ALTUSERNAME_DESC=	Enable --x509-username-field (only with OpenSSL)

EASYRSA_RUN_DEPENDS=	easy-rsa>=0:${PORTSDIR}/security/easy-rsa

PKCS11_LIB_DEPENDS=	libpkcs11-helper.so:${PORTSDIR}/security/pkcs11-helper
PKCS11_CONFIGURE_ENABLE=	pkcs11

PW_SAVE_CONFIGURE_ENABLE=	password-save

X509ALTUSERNAME_CONFIGURE_ENABLE=	x509-alt-username

X509ALTUSERNAME_PREVENTS=	POLARSSL
X509ALTUSERNAME_PREVENTS_MSG=	OpenVPN ${DISTVERSION} cannot use --x509-username-field with PolarSSL. Disable X509ALTUSERNAME, or use OpenSSL instead

POLARSSL_LIB_DEPENDS=		libpolarssl.so:${PORTSDIR}/security/polarssl
POLARSSL_CONFIGURE_ON=	--with-crypto-library=polarssl
POLARSSL_USE_OFF=		openssl=yes
POLARSSL_CONFIGURE_OFF=	--with-crypto-library=openssl

USE_RC_SUBR=		openvpn
USE_LDCONFIG=		${PREFIX}/lib

SUB_FILES=		pkg-message openvpn-client

.ifdef (LOG_OPENVPN)
CFLAGS+=		-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

LIB_DEPENDS+=		liblzo2.so:${PORTSDIR}/archivers/lzo2

PORTDOCS=		*
PORTEXAMPLES=		*

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

.if !defined(WITHOUT_CHECK)
post-build:
	@# self-tests here
	@${ECHO} ; ${ECHO} "### Note that you can skip these lengthy selftests with WITHOUT_CHECK=yes ###" ; ${ECHO}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} check
.endif

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
