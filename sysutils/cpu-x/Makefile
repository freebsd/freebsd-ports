PORTNAME=	cpu-x
PORTVERSION=	4.5.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Gathers information about CPU, motherboard, and more
WWW=		https://thetumultuousunicornofdarkness.github.io/CPU-X/

LICENSE=	GPLv3+

LIB_DEPENDS=	libcpuid.so:sysutils/libcpuid \
		libpci.so:devel/libpci \
		libstatgrab.so:devel/libstatgrab

USES=		cmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	TheTumultuousUnicornOfDarkness
GH_PROJECT=	${PORTNAME:tu}
CMAKE_OFF=	WITH_LIBGLFW WITH_VULKAN WITH_OPENCL

PORTDOCS=	ChangeLog.md README.md

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DWITH_GETTEXT:BOOL=OFF

FLAVORS=	gtk3 ncurses

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:S/^/${PORTNAME}-/}

.if ${FLAVOR:U} == ncurses
PKGNAMESUFFIX=	-tuionly
USES+=		ncurses
CMAKE_ARGS+=	-DWITH_GTK:BOOL=OFF
PLIST_SUB+=	X11="@comment "
.else
USES+=		gnome
USE_GNOME=	gtk30
GLIB_SCHEMAS=	org.cpu-x.gschema.xml
PLIST_SUB+=	X11=""
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386 || ${ARCH} == amd64
BUILD_DEPENDS+=	nasm:devel/nasm
.else
CMAKE_OFF+=	WITH_BANDWIDTH
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
