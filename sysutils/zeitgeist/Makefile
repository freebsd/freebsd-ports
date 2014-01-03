# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zeitgeist
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}/${PORTVERSION}/+download/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Event logging framework - engine

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		rapper:${PORTSDIR}/textproc/raptor2 \
		${PYTHON_SITELIBDIR}/rdflib/__init__.py:${PORTSDIR}/textproc/py-rdflib
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		${PYTHON_SITELIBDIR}/dbus/__init__.py:${PORTSDIR}/devel/py-dbus

USE_GNOME=	gnomehack intlhack pygobject
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
USES=		gmake gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	zeitgeist-daemon.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python|${PYTHON_CMD}|g' \
		${WRKSRC}/extra/rdfxml2py

.include <bsd.port.mk>
