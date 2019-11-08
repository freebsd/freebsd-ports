# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpu-x
PORTVERSION=	3.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Gathers information about CPU, motherboard, and more

LICENSE=	GPLv3

BUILD_DEPENDS=	nasm:devel/nasm
LIB_DEPENDS=	libcpuid.so:sysutils/libcpuid \
		libpci.so:devel/libpci \
		libstatgrab.so:devel/libstatgrab \
		libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	X0rg
GH_PROJECT=	${PORTNAME:tu}

USES=		cmake gettext ncurses pkgconfig
CMAKE_ARGS=	-DWITH_LIBJSONC:BOOL=OFF

PORTDOCS=	ChangeLog README.md

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

X11_DESC=	Build GTK+3 frontend in addition to ncurses one

X11_USES=	gnome
X11_USE=	GNOME=gtk30
X11_CMAKE_OFF=	-DWITH_GTK:BOOL=OFF
X11_VARS=	INSTALLS_ICONS=yes

post-patch:
	@${REINPLACE_CMD} -e 's, -Wno-unused-result,,' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
