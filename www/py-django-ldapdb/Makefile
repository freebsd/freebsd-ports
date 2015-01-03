# Created by: Alexander Kriventsov <avk@vl.ru>
# $FreeBSD$

PORTNAME=	django-ldapdb
PORTVERSION=	0.3.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	avk@vl.ru
COMMENT=	Support for django models over LDAP

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.6.0:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}ldap2>=2.0:${PORTSDIR}/net/py-ldap2

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
