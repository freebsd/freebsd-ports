# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=		xvidcap
PORTVERSION=		1.1.7
PORTREVISION=		3
PORTEPOCH=		1
CATEGORIES=		sysutils multimedia
MASTER_SITES=		SF

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Capture your X display to individual frames or MPEG video

LICENSE=		GPLv3

BUILD_DEPENDS=		xml2po:textproc/gnome-doc-utils	\
			scrollkeeper-config:textproc/scrollkeeper
LIB_DEPENDS=		libswscale.so:multimedia/ffmpeg	\
			libdbus-glib-1.so:devel/dbus-glib	\
			libmp3lame.so:audio/lame
RUN_DEPENDS=		animate:graphics/ImageMagick	\
			gimp:graphics/gimp-app

GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
# --export-dynamic fixes libglade problems
LDFLAGS+=		-L${LOCALBASE}/lib -Wl,--export-dynamic

USE_GNOME=		glib20 libglade2 intltool
USES=			gettext gmake pkgconfig
USE_XORG=		x11 xmu ice xfixes xdamage
INSTALLS_OMF=		yes
MANLANG=		"" de es it

.if !defined(CFLAGS) || ${CFLAGS:M-fno-strict-aliasing*} == ""
CFLAGS+=	-O2 -fno-strict-aliasing
.endif

PORTDOCS=		AUTHORS ChangeLog README
NULLDOCS=		COPYING

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} -e 's|pkgdataDATA install-xvidcapdocDATA|pkgdataDATA|'	\
		${WRKSRC}/Makefile.in
.endif
	${REINPLACE_CMD} -e 's|/bin/bash | /bin/sh|' ${WRKSRC}/ppm2mpeg.sh
	@${REINPLACE_CMD} '/^xvidcap_LDADD =/s/$$/ -lXext -lX11/' \
		${WRKSRC}/src/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${RM} ${NULLDOCS:S|^|${STAGEDIR}${DOCSDIR}/|}
.endif

.include <bsd.port.mk>
