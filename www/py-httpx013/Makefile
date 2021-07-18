# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	httpx
PORTVERSION=	0.13.3
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	013

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Next generation HTTP client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=3.0,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hstspreload>=0:www/py-hstspreload@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore>=0.9:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.0<3:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=1.3<2:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=0:devel/py-sniffio@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.13\.

.include <bsd.port.mk>
