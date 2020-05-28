# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpu-x
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Gathers information about CPU, motherboard, and more

LICENSE=	GPLv3

BUILD_DEPENDS=	nasm:devel/nasm
LIB_DEPENDS=	libcpuid.so:sysutils/libcpuid \
		libpci.so:devel/libpci \
		libstatgrab.so:devel/libstatgrab

USE_GITHUB=	yes
GH_ACCOUNT=	X0rg
GH_PROJECT=	${PORTNAME:tu}

USES=		cmake gettext ncurses pkgconfig

PORTDOCS=	ChangeLog.md README.md

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

X11_DESC=	Build GTK+3 frontend in addition to ncurses one

X11_USES=	gnome
X11_USE=	GNOME=gtk30
X11_CMAKE_OFF=	-DWITH_GTK:BOOL=OFF
X11_VARS=	GLIB_SCHEMAS=org.cpu-x.gschema.xml INSTALLS_ICONS=yes

post-patch:
	@${REINPLACE_CMD} -e 's, -Wno-unused-result,,' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '23s,^,#include <sys/wait.h>,' ${WRKSRC}/src/gui_gtk.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
