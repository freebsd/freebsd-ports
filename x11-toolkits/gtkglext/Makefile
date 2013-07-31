# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	gtkglext
PORTVERSION=	1.2.0
PORTREVISION=	11
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF
DIST_SUBDIR=	gnome2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL extension to GTK+

LICENSE=	GPLv2

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		drm:${PORTSDIR}/graphics/libdrm \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_XORG=	ice pixman sm x11 xau xcb xcomposite xcursor xdamage xdmcp \
		xext xfixes xi xinerama xmu xrandr xrender xt xxf86vm
USE_GL=		glu
USES=		gettext iconv pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 gtk20 pangox-compat
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|docs||' ${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DGTK_DISABLE_DEPRECATED||g ; \
		 s|-DGDK_DISABLE_DEPRECATED||g'

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/reference/gtkglext/html/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
