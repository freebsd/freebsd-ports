PORTNAME=	mdpop3d
PORTVERSION=	0.97
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.corpit.ru/home/mjt/mdpop3d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and small POP3 daemon implementation with Maildir support

PLIST_FILES=	libexec/mdpop3d man/man8/mdpop3d.8.gz

OPTIONS_DEFINE=	PAM APOP
APOP_DESC=	Build with APOP command support (requires PAM)

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|LIBS = -lpam -ldl|LIBS = -lpam|;/^CC[[:blank:]]*=/d' \
		${WRKSRC}/Makefile
.if ! ${PORT_OPTIONS:MPAM}
	@${REINPLACE_CMD} -e 's|LIBS = -lpam|LIBS = -lcrypt|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|DEFS = -DUSE_PAM|#DEFS = -DUSE_PAM|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|OPTS = -DUSE_APOP|#OPTS = -DUSE_APOP|' \
		${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MAPOP}
	@${REINPLACE_CMD} -e 's|OPTS = -DUSE_APOP|#OPTS = -DUSE_APOP|' \
		${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/mdpop3d.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
