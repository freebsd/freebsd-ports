# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	wmcube
PORTVERSION=	0.98
PORTREVISION=	3
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	${MASTER_SITE_TUCOWS} \
		http://dockapps.org/download.php/id/222/ \
		http://freebsd.unixfreunde.de/sources/
MASTER_SITE_SUBDIR=	x11/dock

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Window Maker dockapp that displays cpu load and a realtime 3D object

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_XORG=	xpm
MAKEFILE=	Makefile.FREEBSD
PORTDOCS=	CHANGES README TODO
SUB_FILES=	pkg-message
USE_CSTD=	gnu89
MAKE_JOBS_UNSAFE=	yes
NEED_ROOT=	yes

do-install:
	${INSTALL_PROGRAM} -m 2755 -o root -g kmem ${WRKSRC}/wmcube ${STAGEDIR}${PREFIX}/bin
.for file in *.wmc
	@${ECHO} "===>   Installing extra 3d objects in ${STAGEDIR}${PREFIX}/share/${PORTNAME}"
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/3dObjects/${file} ${STAGEDIR}${DATADIR}
.endfor
	@${ECHO} "===>   Installing README in ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}"
	@${ECHO} "===>   Please Read pkg-descr and README for usage information"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
