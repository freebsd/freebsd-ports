PORTNAME=	wmCalClock
PORTVERSION=	1.26
PORTREVISION=	2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://jmpacquet.free.fr/wmcalclock/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Another Window Maker calendar/clock dockapp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		xorg
USE_XORG=	x11 xext xpm
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
PLIST_FILES=	bin/wmCalClock man/man1/${PORTNAME}.1.gz
PORTDOCS=	BUGS CHANGES HINTS INSTALL README TODO

OPTIONS_DEFINE=	DOCS

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	cd ${WRKDIR}/${DISTNAME} && \
	    ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
