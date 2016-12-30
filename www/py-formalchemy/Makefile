# Created by: ghostonthewire <ghostonthewire at gmail dot com>
# $FreeBSD$

PORTNAME=	formalchemy
PORTVERSION=	1.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
#MASTER_SITES=	https://github.com/FormAlchemy/formalchemy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ghostonthewire@gmail.com
COMMENT=	Toolkit for creating HTML form elements

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	FormAlchemy

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0.4.5:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.4:textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.6.4:www/py-webhelpers
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
