# Created by: Bartlomiej Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iocage
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	FreeBSD jail manager written in Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.lzma>=0.0.6:archivers/py-backports.lzma \
		${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.10.0:misc/py-tqdm \
		ca_root_nss>0:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}tabletext>=0.1:textproc/py-tabletext \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_PROJECT=	${PORTNAME}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
