# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmCalClock
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://jmpacquet.free.fr/wmcalclock/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Another Window Maker calendar/clock dockapp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

USE_XORG=	xpm
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
PLIST_FILES=	bin/wmCalClock
PORTDOCS=	BUGS CHANGES HINTS INSTALL README TODO

MAN1=		wmCalClock.1

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME} && \
		${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
