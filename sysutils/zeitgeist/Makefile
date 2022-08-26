# NOTE: please keep zeitgeist in sysutils/qzeitgeist in sync

PORTNAME=	zeitgeist
DISTVERSION=	1.0.4
CATEGORIES=	sysutils

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Event logging framework

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	dee-tool:devel/dee \
		rapper:textproc/raptor2 \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.1.1:textproc/py-rdflib@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:devel/py-dbus@${PY_FLAVOR}

USES=		autoreconf gettext gmake gnome libtool pathfix pkgconfig python \
		sqlite tar:xz vala:build
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_COMMIT=	8b89364c077b46734d193c5b8a80f83b0fc917dd
USE_GNOME=	cairo gdkpixbuf2 glib20 intlhack \
		introspection:build
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--disable-fts --disable-telepathy \
		--disable-downloads-monitor

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DATAHUB
OPTIONS_DEFAULT=DATAHUB
DATAHUB_LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
DATAHUB_USE=	gnome=gtk30
DATAHUB_CONFIGURE_ENABLE=	datahub
DATAHUB_DESC=	Passive loggers for Zeitgeist

.include <bsd.port.mk>
