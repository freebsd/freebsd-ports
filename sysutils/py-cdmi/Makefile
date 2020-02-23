# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cdmi
PORTVERSION=	1.0
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	CDMI on OpenStack Swift implementation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}swift>0:databases/py-swift@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>0:www/py-webob@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	osaddon
GH_TAGNAME=	f0e3ad9

USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
