# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	xosd
PORTVERSION=	2.2.14
PORTREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	SF/libxosd/libxosd/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 on-screen-display program and library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pkgconfig xorg
USE_CSTD=	gnu89
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xext xinerama xt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-beep_media_player_plugin \
		--disable-new-plugin
CONFIGURE_ENV=	GLIB_CONFIG='${GLIB_CONFIG}' \
		GTK_CONFIG='${GTK_CONFIG}'
INSTALL_TARGET=	install-strip
PATCH_STRIP=	-p1

PORTDOCS=	AUTHORS ChangeLog TODO

OPTIONS_DEFINE=	DOCS MSEC XFT
OPTIONS_SUB=	yes

MSEC_DESC=	Use milliseconds timeout (breaks compatibility!)
XFT_DESC=	Unofficial Xft support

MSEC_EXTRA_PATCHES=	${FILESDIR}/extra-patch-msec-timeout
MSEC_VARS=		DELAY_UNITS=milliseconds
MSEC_VARS_OFF=		DELAY_UNITS=seconds

XFT_USES=		gnome
XFT_USE=		GNOME=pango \
			XORG=xft
XFT_EXTRA_PATCHES=	${FILESDIR}/extra-patch-xft

post-patch:
	@${REINPLACE_CMD} -e 's,^\(CFLAGS =\)\(.*\)$$,\1 -I..\2,' \
		${WRKSRC}/src/libxosd/Makefile.in \
		${WRKSRC}/src/xmms_plugin/Makefile.in
	@${REINPLACE_CMD} -e 's,specified time,& (${DELAY_UNITS}),' \
		${WRKSRC}/src/osd_cat.c

post-patch-XFT-on:
# unbreak against Clang
	@${REINPLACE_CMD} -e '52s,^,void xosd_xypos(xosd *osd);,' \
		${WRKSRC}/src/libxosd/xosd.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
