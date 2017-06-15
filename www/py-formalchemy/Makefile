# Created by: ghostonthewire <ghostonthewire at gmail dot com>
# $FreeBSD$

PORTNAME=	formalchemy
PORTVERSION=	1.5.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FormAlchemy-${DISTVERSION}

MAINTAINER=	ghostonthewire@gmail.com
COMMENT=	Toolkit for creating HTML form elements

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0:textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.4.5:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.4:textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.6.4:www/py-webhelpers \
		${PYTHON_PKGNAMEPREFIX}webob>=1.6.3:www/py-webob

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
