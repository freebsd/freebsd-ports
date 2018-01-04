# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	Flask
PORTVERSION=	0.12.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Micro web framework

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>=0.11:www/py-werkzeug@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}itsdangerous>=0.24:security/py-itsdangerous@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=6.6:devel/py-click@${FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
