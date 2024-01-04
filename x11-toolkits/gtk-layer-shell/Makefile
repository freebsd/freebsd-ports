PORTNAME=	gtk-layer-shell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
CATEGORIES=	x11-toolkits

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK3 library for the Wayland layer-shell protocol
WWW=		https://github.com/wmww/gtk-layer-shell

LICENSE=	LGPL3+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSE_LGPL.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE_MIT.txt

BUILD_DEPENDS=	wayland-protocols>=1.16:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland
TEST_DEPENDS=	evdev-proto>0:devel/evdev-proto

USES=		compiler:c11 gnome meson pkgconfig vala:build
USE_GNOME=	gtk30 introspection:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	wmww

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
