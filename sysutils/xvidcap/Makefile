# Created by: thierry@pompo.net

PORTNAME=		xvidcap
PORTVERSION=		1.1.7
PORTREVISION=		13
PORTEPOCH=		1
CATEGORIES=		sysutils multimedia
MASTER_SITES=		SF

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Capture your X display to individual frames or MPEG video

LICENSE=		GPLv3

LIB_DEPENDS=		libdbus-1.so:devel/dbus			\
			libfreetype.so:print/freetype2		\
			libswscale.so:multimedia/ffmpeg		\
			libdbus-glib-1.so:devel/dbus-glib	\
			libfontconfig.so:x11-fonts/fontconfig	\
			libmp3lame.so:audio/lame
RUN_DEPENDS=		gimp:graphics/gimp-app

USES=			gettext gmake gnome localbase magick:6,run pkgconfig xorg

USE_GNOME=		cairo gdkpixbuf2 glib20 libglade2 intltool
USE_XORG=		x11 xext xmu ice xfixes xdamage
MANLANG=		"" de es it
MAKE_ARGS=		omffile=""

GNU_CONFIGURE=		yes
# --export-dynamic fixes libglade problems
LDFLAGS+=		-Wl,--export-dynamic -lz

.if !defined(CFLAGS) || ${CFLAGS:M-fno-strict-aliasing*} == ""
CFLAGS+=	-O2 -fno-strict-aliasing
.endif

PORTDOCS=		AUTHORS ChangeLog README
NULLDOCS=		COPYING

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} -e 's|/bin/bash | /bin/sh|' ${WRKSRC}/ppm2mpeg.sh
	${REINPLACE_CMD} '/^xvidcap_LDADD =/s/$$/ -lXext -lX11/' \
		${WRKSRC}/src/Makefile.in
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g'	\
		${WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure-DOCS-on:
	${REINPLACE_CMD} -e 's|pkgdataDATA install-xvidcapdocDATA|pkgdataDATA|'	\
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	${RM} ${NULLDOCS:S|^|${STAGEDIR}${DOCSDIR}/|}

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/share/omf/xvidcap
	${RMDIR} ${STAGEDIR}${PREFIX}/share/omf/

.include <bsd.port.mk>
