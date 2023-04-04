PORTNAME=	cpu-x
PORTVERSION=	4.5.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Gathers information about CPU, motherboard, and more
WWW=		https://thetumultuousunicornofdarkness.github.io/CPU-X/

LICENSE=	GPLv3+

BUILD_DEPENDS=	nasm:devel/nasm
LIB_DEPENDS=	libcpuid.so:sysutils/libcpuid \
		libpci.so:devel/libpci \
		libstatgrab.so:devel/libstatgrab

USES=		cmake ncurses pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	TheTumultuousUnicornOfDarkness
GH_PROJECT=	${PORTNAME:tu}
CMAKE_OFF=	WITH_LIBGLFW WITH_VULKAN WITH_OPENCL

PORTDOCS=	ChangeLog.md README.md

OPTIONS_DEFINE=	DOCS NLS X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DWITH_GETTEXT:BOOL=OFF

X11_DESC=	Build GTK+3 frontend in addition to ncurses one
X11_USES=	gnome
X11_USE=	GNOME=gtk30
X11_CMAKE_OFF=	-DWITH_GTK:BOOL=OFF
X11_VARS=	GLIB_SCHEMAS=org.cpu-x.gschema.xml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
