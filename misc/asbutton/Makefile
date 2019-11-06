# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asbutton
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	misc windowmaker afterstep
MASTER_SITES=	AFTERSTEP/apps/asbutton/ \
		http://tigr.net/afterstep/download/asbutton/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays 4 or 9 buttons to run apps of your choice

LICENSE=	GPLv2

USES=		xorg
USE_XORG=	x11 xpm
ALL_TARGET=	asbutton
MAKE_ARGS=	INCLUDES="-I${LOCALBASE}/include/X11 -I${LOCALBASE}/include" \
		LIBINC="-L${LOCALBASE}/lib" LIBS="-lm -lX11 -lXpm -lXext" \
		CCFLAGS="${CFLAGS}"

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|gcc |$${CC} |' ${WRKSRC}/Makefile

post-build:
	@${LN} -sf .asbuttonrc ${WRKSRC}/asbuttonrc

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} asbutton \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/icons && ${INSTALL_DATA} *.xpm \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} asbuttonrc \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
