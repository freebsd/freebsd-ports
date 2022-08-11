PORTNAME=	wmcube
PORTVERSION=	0.98
PORTREVISION=	4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.tucows.com/download/linux/files/x11/dock/	\
		http://distfiles.macports.org/wmcube/	\
		http://ftp.twaren.net/BSD/OpenBSD/distfiles/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Window Maker dockapp that displays cpu load and a realtime 3D object

LICENSE=	GPLv2

USES=		xorg
USE_XORG=	x11 xext xpm

CFLAGS+=	-fcommon
OPTIONS_DEFINE=	DOCS
WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
MAKEFILE=	Makefile.FREEBSD
PORTDOCS=	CHANGES README TODO
SUB_FILES=	pkg-message
USE_CSTD=	gnu89
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmcube ${STAGEDIR}${PREFIX}/bin
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
