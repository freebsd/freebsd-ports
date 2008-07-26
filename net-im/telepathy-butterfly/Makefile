# New ports collection makefile for:	telepathy-butterfly
# Date created:				Apr 19 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	telepathy-butterfly
PORTVERSION=	0.3.2
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MSN Connection Manager for Telepathy Framework

BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/pymsn/__init__.py:${PORTSDIR}/net-im/pymsn \
		${PYTHON_SITELIBDIR}/telepathy/__init__.py:${PORTSDIR}/net-im/telepathy-python
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymsn/__init__.py:${PORTSDIR}/net-im/pymsn \
    		${PYTHON_SITELIBDIR}/telepathy/__init__.py:${PORTSDIR}/net-im/telepathy-python

USE_PYTHON=	2.4+
HAS_CONFIGURE=	yes

.include <bsd.port.mk>
