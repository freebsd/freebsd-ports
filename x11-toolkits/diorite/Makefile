# $FreeBSD$

PORTNAME=	diorite
PORTVERSION=	0.2.1
CATEGORIES=	x11-toolkits devel

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Utility and widget library based on GLib and GTK+ 3

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	valac:lang/vala

USE_GITHUB=	yes
GH_ACCOUNT=	tiliado

USES=		gnome pkgconfig shebangfix waf
USE_GNOME=	glib20 gtk30
USE_XORG=	x11
SHEBANG_LANG=	python3
SHEBANG_FILES=	testgen.py
# --noopt is required to prevent a crash in ipcserver.c, as
# the argument of diorite_ipc_server_process_connection_co() gets
# optimized out in diorite_ipc_server_process_connection().
CONFIGURE_ARGS=	--noopt --platform=LINUX
MAKE_ARGS=	--no-ldconfig
USE_LDCONFIG=	yes

.ifdef(WITH_DEBUG)
CONFIGURE_ARGS+=--debug
.else
CONFIGURE_ARGS+=--no-debug
.endif

pre-configure:
	@${REINPLACE_CMD} -e '/pkgconfig/ s,$${LIBDIR},${PREFIX}/libdata,' \
		${WRKSRC}/wscript

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
