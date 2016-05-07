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

USES=		gmake pkgconfig libtool
USE_CSTD=	gnu89
USE_XORG=	x11 xext xt sm ice
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG='${GTK_CONFIG}' GLIB_CONFIG='${GLIB_CONFIG}'
CONFIGURE_ARGS=	--disable-beep_media_player_plugin --disable-new-plugin
PATCH_STRIP=	-p1
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS ChangeLog TODO

OPTIONS_DEFINE=	MSEC XFT DOCS
MSEC_DESC=	Use milliseconds timeout (breaks compatibility!)
XFT_DESC=	Unofficial Xft support

OPTIONS_SUB=	yes

MSEC_EXTRA_PATCHES=	${FILESDIR}/extra-patch-msec-timeout
MSEC_VARS=	DELAY_UNITS=milliseconds
MSEC_VARS_OFF=	DELAY_UNITS=seconds

XFT_EXTRA_PATCHES=	${FILESDIR}/extra-patch-xft
XFT_USE=		GNOME=pango XORG=xft

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
