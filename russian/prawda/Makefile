# New ports collection makefile for:	prawda
# Date created:		2004-07-28
# Whom:			Roman Bogorodskiy <bogordskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	prawda
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	russian
MASTER_SITES=	http://www.prawda.newmail.ru/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	English-Russian translator

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
CXXFLAGS+=	-I${X11BASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|ulong|unsigned long|g;;s|malloc.h|stdlib.h|g" ${WRKSRC}/src/face/video_x.cpp
	@${REINPLACE_CMD} -e "s|g++|${CXX} ${CXXFLAGS}|g" ${WRKSRC}/src/bin/makefile.exe
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/bin/makefile ${WRKSRC}/src/face/main.cpp

do-build:
	@cd ${WRKSRC}/bin && ${MAKE}

do-install:
	@cd ${WRKSRC}/bin && ${MAKE} install

.include <bsd.port.post.mk>
