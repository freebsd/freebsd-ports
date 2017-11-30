# Created by: Richard Gallamore <ultima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-post_office
PORTVERSION=	3.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
MASTER_SITES=	GH
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Django app to monitor and send mail asynchronously

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-jsonfield>=0:www/py-django-jsonfield@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django18>=1.8:www/py-django18@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	ui

NO_ARCH=	yes

.include <bsd.port.mk>
