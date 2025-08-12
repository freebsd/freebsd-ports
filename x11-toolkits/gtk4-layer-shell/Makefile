PORTNAME=	gtk4-layer-shell
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	x11-toolkits

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK4 library for the Wayland layer-shell protocol
WWW=		https://github.com/wmww/gtk4-layer-shell

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.16:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland
TEST_DEPENDS=	evdev-proto>0:devel/evdev-proto

USES=		compiler:c11 gnome meson pkgconfig vala:build
USE_GNOME=	gtk40 introspection:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	wmww
MESON_ARGS=	-Dsmoke-tests=false # Need luajit flavor of devel/lua-lgi
PLIST_SUB=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_MESON_TRUE=	docs

EXAMPLES_MESON_TRUE=	examples

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dtests=true"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
