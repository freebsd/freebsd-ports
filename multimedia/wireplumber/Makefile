PORTNAME=	wireplumber
DISTVERSION=	0.5.8
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Session and policy manager for PipeWire
WWW=		https://pipewire.pages.freedesktop.org/wireplumber/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire

USES=		gnome localbase:ldflags lua meson pkgconfig python:build

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	pipewire

USE_GNOME=	glib20

OPTIONS_DEFINE=	DOCS DOXYGEN NLS

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			g-ir-scanner:devel/gobject-introspection \
			sphinx-build:textproc/py-sphinx \
			${PYTHON_PKGNAMEPREFIX}breathe>0:devel/py-breathe@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}
DOXYGEN_MESON_ENABLED=	doc introspection
DOXYGEN_IMPLIES=	DOCS

NLS_USES=	gettext-runtime gettext-tools

MESON_ARGS=	-D system-lua=true \
		-D systemd=disabled \
		-D elogind=disabled

SUB_FILES=	10-${PORTNAME}.conf

OPTIONS_SUB=	yes

PORTDOCS=	*

post-patch:
	${REINPLACE_CMD} -e "s|'python3'|'python${PYTHON_VER}'|" \
		${WRKSRC}/docs/meson.build

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pipewire/pipewire.conf.d
	${INSTALL_DATA} ${WRKDIR}/10-wireplumber.conf \
		${STAGEDIR}${PREFIX}/share/pipewire/pipewire.conf.d

.include <bsd.port.mk>
