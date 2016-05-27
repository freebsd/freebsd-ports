# Created by: Ultima <ultima1252@gmail.com>
# $FreeBSD$

PORTNAME=	django-constance
PORTVERSION=	1.2
CATEGORIES=	www python
MASTER_SITES=	GH
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Dynamic Django settings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage \
		${PYTHON_PKGNAMEPREFIX}django-picklefield>=0:www/py-django-picklefield \
		${PYTHON_PKGNAMEPREFIX}django18>=1.7:www/py-django18

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	jazzband

.include <bsd.port.mk>
