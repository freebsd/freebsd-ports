# New ports collection makefile for:	telepathy-butterfly
# Date created:				Apr 19 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/net-im/telepathy-butterfly/Makefile,v 1.3 2009/01/08 06:51:59 marcus Exp $
#

PORTNAME=	telepathy-butterfly
PORTVERSION=	0.5.0
CATEGORIES=	net-im
MASTER_SITES=	http://telepathy.freedesktop.org/releases/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MSN Connection Manager for Telepathy Framework

BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/papyon/__init__.py:${PORTSDIR}/net-im/papyon \
		${PYTHON_SITELIBDIR}/telepathy/__init__.py:${PORTSDIR}/net-im/telepathy-python
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/papyon/__init__.py:${PORTSDIR}/net-im/papyon \
    		${PYTHON_SITELIBDIR}/telepathy/__init__.py:${PORTSDIR}/net-im/telepathy-python

USE_PYTHON=	2.5+
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}

.include <bsd.port.mk>
