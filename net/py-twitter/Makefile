# ex:ts=8
# Ports collection makefile for:	py-twitter
# Date created:			Apr 13, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twitter
PORTVERSION=	0.3
CATEGORIES=	net python
MASTER_SITES=	http://python-twitter.googlecode.com/files/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	A python wrapper around the Twitter API

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYTWITTER_EGG=	python_${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg
PLIST_SUB+=	PYTWITTER_EGG=${PYTWITTER_EGG}

.include <bsd.port.mk>
