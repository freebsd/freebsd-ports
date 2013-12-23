# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gtkglext
PORTVERSION=	1.2.0
PORTREVISION=	13
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL extension to GTK+

LICENSE=	GPLv2

LIB_DEPENDS=	libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libdrm.so:${PORTSDIR}/graphics/libdrm \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp \
		xext xfixes xi xinerama xmu xrandr xrender xt xxf86vm
USE_GL=		glu
USES=		gettext gmake iconv pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 gtk20 pangox-compat
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|docs||' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DGTK_DISABLE_DEPRECATED||g ; \
		 s|-DGDK_DISABLE_DEPRECATED||g'

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/reference/gtkglext/html/* ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
