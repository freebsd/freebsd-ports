# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkada
PORTVERSION=	3.14.2
PORTREVISION=	3
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada graphical toolkit based on Gtk3 components

LICENSE=	GPLv3

BUILD_DEPENDS=	gprbuild:devel/gprbuild
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libdrm.so:graphics/libdrm \
		libatk-bridge-2.0.so:accessibility/at-spi2-atk \
		libepoxy.so:graphics/libepoxy \
		libpng.so:graphics/png \
		libffi.so:devel/libffi \
		libpcre.so:devel/pcre \
		libexpat.so:textproc/expat2 \
		libatspi.so:accessibility/at-spi2-core \
		libgraphite2.so:graphics/graphite2 \
		libdbus-1.so:devel/dbus

USES=		ada:run gl gmake gnome iconv:wchar_t perl5 pkgconfig xorg
USE_PERL5=	build
USE_GNOME=	gtk30 cairo gdkpixbuf2
USE_XORG=	ice sm xxf86vm xcb xdmcp xau x11 pixman xfixes xdamage \
		xcomposite xi xext xcursor xrandr xinerama xrender
USE_GL=		gl egl gbm glu
USE_GITHUB=	yes
GH_ACCOUNT=	AdaCore
GH_PROJECT=	gtkada
GH_TAGNAME=	1688bb8

GNU_CONFIGURE=	yes
ALL_TARGET=	tools static relocatable
PORTDOCS=	gtkada_ug
LDFLAGS+=	-L${LOCALBASE}/lib

MAKE_ARGS=	PROCESSORS=${MAKE_JOBS_NUMBER}

CONFLICTS_INSTALL=	gtkada-*

CONFIGURE_ARGS+=	--with-GL=auto \
			--with-GL-prefix=${PREFIX} \
			--enable-shared \
			--enable-static

OPTIONS_DEFINE=		DOCS NLS DEBUG

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_ALL_TARGET=	docs
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
DEBUG_CONFIGURE_ON=	--enable-build=Debug
DEBUG_CONFIGURE_OFF=	--enable-build=Production

do-build:
#	This target is recreated because -j cannot be set, but
#	MAKE_JOBS_SAFE=yes is needed for PROCESSORS value
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gtkada-dialog
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/gtkada/gtkada_ug/_sources

.include <bsd.port.mk>
