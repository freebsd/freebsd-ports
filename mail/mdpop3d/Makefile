# New ports collection makefile for:	mdpop3d
# Date created:		2 July 2006
# Whom:			Alexander Logvinov <info@logvinov.com>
#
# $FreeBSD$

PORTNAME=	mdpop3d
PORTVERSION=	0.97
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.corpit.ru/home/mjt/mdpop3d/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A simple and small POP3 daemon implementation with Maildir support

MAN8=		mdpop3d.8
MANCOMPRESSED=	no

OPTIONS=	PAM   "Build with PAM support"                      	off \
		APOP  "Build with APOP command support (requires PAM)"	off

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|LIBS = -lpam -ldl|LIBS = -lpam|' \
	                                ${WRKSRC}/Makefile
.if defined(WITHOUT_PAM)
	@${REINPLACE_CMD} -e 's|LIBS = -lpam|LIBS = -lcrypt|' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|DEFS = -DUSE_PAM|#DEFS = -DUSE_PAM|' \
	                ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|OPTS = -DUSE_APOP|#OPTS = -DUSE_APOP|' \
	                ${WRKSRC}/Makefile
.endif

.if defined(WITHOUT_APOP)
	@${REINPLACE_CMD} -e 's|OPTS = -DUSE_APOP|#OPTS = -DUSE_APOP|' \
	                ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/mdpop3d.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
