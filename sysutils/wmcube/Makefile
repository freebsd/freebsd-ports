PORTNAME=	wmcube
PORTVERSION=	1.0.2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Window Maker dockapp that displays cpu load and a realtime 3D object
WWW=		https://www.dockapps.net/wmcube

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		xorg
USE_CSTD=	gnu89
USE_XORG=	x11 xext xpm

MAKEFILE=	Makefile.FREEBSD
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-fcommon
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
PORTDOCS=	CHANGES README THANKS
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/wmcube.c

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/wmcube ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmcube.1 ${STAGEDIR}${PREFIX}/share/man/man1
.for file in *.wmc
	@${ECHO} "===>   Installing extra 3d objects in ${STAGEDIR}${PREFIX}/share/${PORTNAME}"
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../3D-objects/${file} ${STAGEDIR}${DATADIR}
.endfor
	@${ECHO} "===>   Installing README in ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}"
	@${ECHO} "===>   Please Read pkg-descr and README for usage information"

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/../${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
