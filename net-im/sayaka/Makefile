# $FreeBSD$

PORTNAME=	sayaka
PORTVERSION=	3.2.2
CATEGORIES=	net-im

MAINTAINER=	sue@iwmt.org
COMMENT=	Command-line twitter client for SIXEL-supported terminal

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		gettext-runtime pkgconfig
USE_GNOME=	glib20 gdkpixbuf2

USE_GITHUB=	yes
GH_ACCOUNT=	isaki68k

PORTDOCS=	README.md

WRKSRC_SUBDIR=	vala

OPTIONS_DEFINE=	COLORMAP
OPTIONS_DEFAULT=COLORMAP
OPTIONS_SUB=	yes

COLORMAP_DESC=	Install colormap data for external sixel command
COLORMAP_RUN_DEPENDS=	img2sixel:graphics/libsixel
COLORMAP_FILES=	colormap16.png colormap8.png

post-patch:
	@${REINPLACE_CMD} -e '/^[a-z]/s/:$$/:	vala-make2/' \
		${WRKSRC}/Makefile

post-patch-COLORMAP-on:
	@${REINPLACE_CMD} -e '/colormapdir =/s|basedir|"${DATADIR}"|' \
		${WRKSRC}/sayaka.vala

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sayaka ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README.md ${STAGEDIR}${DOCSDIR}

do-install-COLORMAP-on:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${COLORMAP_FILES}
		${INSTALL_DATA} ${WRKSRC}/../$f ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
