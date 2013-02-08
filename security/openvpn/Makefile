# Created by: Matthias Andree <mandree@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvpn
DISTVERSION=	2.3.0
PORTREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	http://swupdate.openvpn.net/community/releases/ \
		http://build.openvpn.net/downloads/releases/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Secure IP/Ethernet tunnel daemon

LICENSE=	GPLv2

CONFLICTS_INSTALL=	openvpn-2.[!3].* openvpn-[!2].* openvpn-beta-[0-9]* openvpn-devel-[0-9]*

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_XZ=		yes
# let OpenVPN's configure script pick up the requisite libraries:
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# PolarSSL is not provided; OpenVPN does not currently compile with PolarSSL 1.2.0+
OPTIONS_DEFINE=		PW_SAVE PKCS11 EASYRSA
OPTIONS_DEFAULT=	EASYRSA
PW_SAVE_DESC=	Interactive passwords may be read from a file
PKCS11_DESC=	Use security/pkcs11-helper
EASYRSA_DESC=	Install security/easy-rsa RSA helper package

.include <bsd.port.options.mk>

# use a "stage directory" to install - much easier to sort data/share
# stuff into docs, examples, ...
_stagedir=	${WRKDIR}/instage
INSTALL_TARGET=	install DESTDIR=${_stagedir}

.if ${PORT_OPTIONS:MEASYRSA}
RUN_DEPENDS+=	easy-rsa>=0:${PORTSDIR}/security/easy-rsa
.endif

INSTALL_TARGET+=	mandir=${MANPREFIX}/man
MAN8=		openvpn.8

USE_RC_SUBR=	openvpn
USE_LDCONFIG=	${PREFIX}/lib

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.ifdef (LOG_OPENVPN)
CFLAGS+=	-DLOG_OPENVPN=${LOG_OPENVPN}
.endif

LIB_DEPENDS+=	lzo2:${PORTSDIR}/archivers/lzo2

PORTDOCS=	*
PORTEXAMPLES=	*

.if ${PORT_OPTIONS:MPKCS11}
LIB_DEPENDS+=	pkcs11-helper:${PORTSDIR}/security/pkcs11-helper
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
	${MKDIR} ${PREFIX}/lib/openvpn/plugins/ ${PREFIX}/sbin \
		 ${PREFIX}/include ${PREFIX}/man
	${INSTALL_PROGRAM} ${_stagedir}${PREFIX}/sbin/openvpn ${PREFIX}/sbin
	${INSTALL_DATA} ${_stagedir}${PREFIX}/lib/openvpn/plugins/* ${PREFIX}/lib/openvpn/plugins/
	${INSTALL_DATA} ${_stagedir}${PREFIX}/include/* ${PREFIX}/include/
	${INSTALL_MAN} ${_stagedir}${PREFIX}/man/man8/* ${MAN8PREFIX}/man/man8/
.if ${PORT_OPTIONS:MDOCS}
	-${RMDIR} ${_stagedir}${DOCSDIR}/sample
	(cd ${_stagedir}${DOCSDIR} && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
.for i in AUTHORS ChangeLog PORTS
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	(cd ${WRKSRC}/sample && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
	${CHMOD} ${BINMODE} ${EXAMPLESDIR}/sample-scripts/*
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
