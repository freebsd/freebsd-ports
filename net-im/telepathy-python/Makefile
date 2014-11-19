# $FreeBSD$
#    $MCom: ports/net-im/telepathy-python/Makefile,v 1.5 2009/01/08 07:07:51 marcus Exp $

PORTNAME=	telepathy-python
PORTVERSION=	0.15.19
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for the Telepathy framework

BUILD_DEPENDS=	py2?-dbus>=0:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	py2?-dbus>=0:${PORTSDIR}/devel/py-dbus

USES=		gmake python:2
USE_GNOME=	libxslt:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
