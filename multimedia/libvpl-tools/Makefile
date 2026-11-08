PORTNAME=	libvpl-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0
CATEGORIES=	multimedia

MAINTAINER=	naito.yuichiro@gmail.com
COMMENT=	Intel Video Processing Library Tools
WWW=		https://www.intel.com/content/www/us/en/developer/tools/vpl/overview.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	only Intel GPUs on x86 are supported

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
# libgtkmm-4.0.so and libgtk-4.so are listed here instead of using
# USE_GNOME to avoid an extraneous dependency on libatk-1.0.so,
# which is not used in this port.
LIB_DEPENDS=	libva.so:multimedia/libva \
		libvpl.so:multimedia/libvpl \
		libdrm.so:graphics/libdrm \
		libgraphene-1.0.so:graphics/graphene \
		libvulkan.so:graphics/vulkan-loader \
		libepoxy.so:graphics/libepoxy \
		libwayland-client.so:graphics/wayland \
		libgtkmm-4.0.so:x11-toolkits/gtkmm40 \
		libgtk-4.so:x11-toolkits/gtk40

USES=		cmake:testing compiler:c++17-lang localbase:ldflags pkgconfig \
		xorg gl gnome gettext-runtime
USE_CXXSTD=	c++17
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_GL=		opengl
USE_GNOME=	glib20 gdkpixbuf pango cairo cairomm11 pangomm24
USE_LDCONFIG=	yes
USE_XORG=	x11 xcb

CMAKE_TESTING_ON=	BUILD_TESTS
DATADIR=	${PREFIX}/share/vpl

.include <bsd.port.mk>
