# Created by: ghostonthewire <ghostonthewire at gmail dot com>
# $FreeBSD$

PORTNAME=	formalchemy
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	FormAlchemy-${DISTVERSION}

MAINTAINER=	ghostonthewire@gmail.com
COMMENT=	Toolkit for creating HTML form elements

LICENSE=	MIT

BROKEN=		Unfetchable (google code has gone away)
DEPRECATED=	Broken, depends on expired py-sqlalchemy06
EXPIRATION_DATE=	2016-12-08

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.4.5:databases/py-sqlalchemy06 \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.4:textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.6.4:www/py-webhelpers
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
