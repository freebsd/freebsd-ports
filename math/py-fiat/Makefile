# $FreeBSD$

PORTNAME=	fiat
PORTVERSION=	${MMVERSION}.0
PORTREVISION=	7
CATEGORIES=	math python
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${MMVERSION}.x/release-${MMVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${MMVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	FInite element Automatic Tabulator

LICENSE=	LGPL3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scientific>=0:math/py-scientific@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

MMVERSION=	1.1

.include <bsd.port.mk>
