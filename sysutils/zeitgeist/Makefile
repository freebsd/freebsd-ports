# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
# NOTE: please keep zeitgeist in sysutils/qzeitgeist in sync

PORTNAME=	zeitgeist
PORTVERSION=	0.9.16
CATEGORIES=	sysutils
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}/${PORTVERSION}/+download/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Event logging framework

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	valac:lang/vala \
		dee-tool:devel/dee \
		rapper:textproc/raptor2 \
		${PYTHON_PKGNAMEPREFIX}rdflib>=4.1.1:textproc/py-rdflib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xdg/__init__.py:devel/py-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:devel/py-dbus

USE_GNOME=	intlhack glib20 introspection:build
GNU_CONFIGURE=	yes
USES=		gmake gettext pathfix python:2 pkgconfig libtool sqlite tar:xz
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

post-patch:
	@${REINPLACE_CMD} -e 's|python -|${PYTHON_CMD} -|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
