# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvpn
DISTVERSION=	2.3.2
CATEGORIES=	security net
MASTER_SITES=	http://swupdate.openvpn.net/community/releases/ \
		http://build.openvpn.net/downloads/releases/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Secure IP/Ethernet tunnel daemon

LICENSE=	GPLv2

CONFLICTS_INSTALL=	openvpn-2.[!3].* openvpn-[!2].* openvpn-beta-[0-9]* openvpn-devel-[0-9]*

GNU_CONFIGURE=	yes
USE_XZ=		yes
# let OpenVPN's configure script pick up the requisite libraries:
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		PW_SAVE PKCS11 EASYRSA
OPTIONS_DEFAULT=	EASYRSA OPENSSL
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL POLARSSL
PW_SAVE_DESC=	Interactive passwords may be read from a file
PKCS11_DESC=	Use security/pkcs11-helper
EASYRSA_DESC=	Install security/easy-rsa RSA helper package
POLARSSL_DESC=	SSL/TLS support via PolarSSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEASYRSA}
RUN_DEPENDS+=	easy-rsa>=0:${PORTSDIR}/security/easy-rsa
.endif

.if ${PORT_OPTIONS:MPOLARSSL}
LIB_DEPENDS+=	libpolarssl.so:${PORTSDIR}/security/polarssl
CONFIGURE_ARGS+=	--with-crypto-library=polarssl
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-crypto-library=openssl
.endif

.INSTALL_TARGET+=	mandir=${MANPREFIX}/man
USE_RC_SUBR=	openvpn
USE_LDCONFIG=	${PREFIX}/lib

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.ifdef (LOG_OPENVPN)
CFLAGS+=	-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

LIB_DEPENDS+=	liblzo2.so:${PORTSDIR}/archivers/lzo2

PORTDOCS=	*
PORTEXAMPLES=	*

.if ${PORT_OPTIONS:MPKCS11}
LIB_DEPENDS+=	libpkcs11-helper.so:${PORTSDIR}/security/pkcs11-helper
.else
CONFIGURE_ARGS+=	--disable-pkcs11
.endif

.if ${PORT_OPTIONS:MPW_SAVE}
CONFIGURE_ARGS+=	--enable-password-save
.else
CONFIGURE_ARGS+=	--disable-password-save
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

post-build:
	@# self-tests here
.if !defined(WITHOUT_CHECK)
	@${ECHO} ; ${ECHO} "### Note that you can skip these lengthy selftests with WITHOUT_CHECK=yes ###" ; ${ECHO}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} check
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/ ${STAGEDIR}${PREFIX}/sbin \
		 ${STAGEDIR}${PREFIX}/include ${STAGEDIR}${PREFIX}/man
	#${INSTALL_PROGRAM} ${PREFIX}/sbin/openvpn ${STAGEDIR}${PREFIX}/sbin
	#${INSTALL_DATA} ${PREFIX}/lib/openvpn/plugins/* ${STAGEDIR}${PREFIX}/lib/openvpn/plugins/
	#${INSTALL_DATA} ${PREFIX}/include/* ${STAGEDIR}${PREFIX}/include/
	#${INSTALL_MAN} ${PREFIX}/man/man8/* ${STAGEDIR}${MAN8PREFIX}/man/man8/
.if ${PORT_OPTIONS:MDOCS}
	#(cd ${DOCSDIR_REL} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/)
.for i in AUTHORS ChangeLog PORTS
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/)
	${CHMOD} ${BINMODE} ${STAGEDIR}${EXAMPLESDIR}/sample-scripts/*
.endif

.include <bsd.port.post.mk>
