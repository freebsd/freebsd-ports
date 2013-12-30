# Created by: ijliao
# $FreeBSD$

PORTNAME=	twitter
PORTVERSION=	1.1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python wrapper around the Twitter API

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>=0:${PORTSDIR}/www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}oauth2>=0:${PORTSDIR}/net/py-oauth2 \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson

NO_STAGE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_PKGNAME=	python_twitter

.include <bsd.port.mk>
