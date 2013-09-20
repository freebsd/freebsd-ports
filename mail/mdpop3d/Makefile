# Created by: Alexander Logvinov <info@logvinov.com>
# $FreeBSD$

PORTNAME=	mdpop3d
PORTVERSION=	0.97
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.corpit.ru/home/mjt/mdpop3d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple and small POP3 daemon implementation with Maildir support

PLIST_FILES=	libexec/mdpop3d
MAN8=		mdpop3d.8
MANCOMPRESSED=	no

OPTIONS_DEFINE=	PAM APOP
APOP_DESC=	Build with APOP command support (requires PAM)

NO_STAGE=	yes
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/mdpop3d.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
