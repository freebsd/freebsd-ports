PORTNAME=	wmCalClock
PORTVERSION=	1.26
PORTREVISION=	3
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://jmpacquet.free.fr/wmcalclock/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Another Window Maker calendar/clock dockapp
WWW=		http://jmpacquet.free.fr/wmcalclock/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		xorg
USE_XORG=	x11 xext xpm
MAKE_ENV=	OPSYS=${OPSYS}
WRKSRC=		${WRKDIR}/${DISTNAME}/Src
PLIST_FILES=	bin/wmCalClock share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	BUGS CHANGES HINTS INSTALL README TODO

OPTIONS_DEFINE=	DOCS

pre-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	cd ${WRKDIR}/${DISTNAME} && \
	    ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
