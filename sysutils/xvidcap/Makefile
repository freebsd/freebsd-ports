# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=		xvidcap
PORTVERSION=		1.1.7
PORTREVISION=		11
PORTEPOCH=		1
CATEGORIES=		sysutils multimedia
MASTER_SITES=		SF

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Capture your X display to individual frames or MPEG video

LICENSE=		GPLv3

BUILD_DEPENDS=		xml2po:textproc/gnome-doc-utils	\
			scrollkeeper-config:textproc/rarian
LIB_DEPENDS=		libdbus-1.so:devel/dbus			\
			libfreetype.so:print/freetype2		\
			libswscale.so:multimedia/ffmpeg		\
			libdbus-glib-1.so:devel/dbus-glib	\
			libfontconfig.so:x11-fonts/fontconfig	\
			libmp3lame.so:audio/lame
RUN_DEPENDS=		animate:graphics/ImageMagick6	\
			gimp:graphics/gimp-app

USES=			gettext gmake gnome localbase pkgconfig xorg

USE_GNOME=		cairo gdkpixbuf2 glib20 libglade2 intltool
USE_XORG=		x11 xext xmu ice xfixes xdamage
INSTALLS_OMF=		yes
MANLANG=		"" de es it

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

.include <bsd.port.mk>
