# NOTE: please keep zeitgeist in sysutils/qzeitgeist in sync

PORTNAME=	zeitgeist
DISTVERSION=	1.0.4
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Event logging framework
WWW=		https://wiki.gnome.org/Projects/Zeitgeist

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	dee-tool:devel/dee \
		rapper:textproc/raptor2 \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.1.1:textproc/py-rdflib@${PY_FLAVOR}
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:devel/py-dbus@${PY_FLAVOR}

USES=		autoreconf gettext gmake gnome libtool localbase:ldflags pathfix pkgconfig \
		python sqlite tar:xz vala:build
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_TAGNAME=	8b89364c077b46734d193c5b8a80f83b0fc917dd
USE_GNOME=	cairo gdkpixbuf glib20 intlhack \
		introspection:build
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-fts --disable-telepathy \
		--disable-downloads-monitor

INSTALL_TARGET=	install-strip

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	DATAHUB
OPTIONS_DEFAULT=DATAHUB

DATAHUB_DESC=	Passive loggers for Zeitgeist

DATAHUB_LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib
DATAHUB_USE=	gnome=gtk30
DATAHUB_CONFIGURE_ENABLE=	datahub

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
