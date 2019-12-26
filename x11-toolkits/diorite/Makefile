# $FreeBSD$

PORTNAME=	diorite
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility and widget library based on GLib and GTK+ 3

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	valac:lang/vala

GH_ACCOUNT=	tiliado

# USES=waf implicity does USES=python:2.7,build but that is not sufficient
# for shebangfix to know the python version
USES=		gnome pkgconfig python:2.7,build shebangfix waf xorg
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf2 glib20 gtk30
USE_XORG=	x11
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
