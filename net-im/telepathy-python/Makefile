# New ports collection makefile for:	telepathy-python
# Date created:				Apr 19 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/net-im/telepathy-python/Makefile,v 1.5 2009/01/08 07:07:51 marcus Exp $

PORTNAME=	telepathy-python
PORTVERSION=	0.15.10
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for the Telepathy framework

LIB_PC_DEPENDS=	dbus-python.pc:${PORTSDIR}/devel/py-dbus

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

BUILD_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}
RUN_DEPENDS+=	${LIB_PC_DEPENDS:C|^|${LOCALBASE}/libdata/pkgconfig/|g}

USE_PYTHON=		2.4+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
