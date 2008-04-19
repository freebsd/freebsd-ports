# New ports collection makefile for:	wmbattery
# Date created:		18 Sep 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmbattery
PORTVERSION=	1.21
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.kitenet.net/programs/wmbattery/old/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window Maker dockapp that displays info about your battery

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	xpm
GNU_CONFIGURE=	yes
MAN1=		wmbattery.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
