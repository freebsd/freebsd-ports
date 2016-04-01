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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}swift>0:databases/py-swift \
		${PYTHON_PKGNAMEPREFIX}webob>0:www/py-webob

USE_GITHUB=	yes
GH_ACCOUNT=	osaddon
GH_TAGNAME=	f0e3ad9

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
