# New ports collection makefile for:	yabasic
# Date created:		11 Nov 1999
# Whom:			Frank Gruender
#
# $FreeBSD$
#

PORTNAME=	yabasic
PORTVERSION=	2.681
CATEGORIES=	lang
MASTER_SITES=	http://www.yabasic.de/download/

MAINTAINER=	ports@FreeBSD.org

USE_BISON=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include"
MAN1=		yabasic.1

post-patch:
	${PERL} -pi -e "s|<malloc.h>|<stdlib.h>|g" ${WRKSRC}/bison.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yabasic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yabasic.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/yabasic
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm ${PREFIX}/share/doc/yabasic
.endif

.include <bsd.port.mk>
