# Created by: Bartlomiej Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iocage
PORTVERSION=	0.9.8b
PORTREVISION=	10
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	FreeBSD jail manager written in Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=2.0.0:devel/py-pytest-runner
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py-click \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.10.0:misc/py-tqdm \
		${PYTHON_PKGNAMEPREFIX}coloredlogs>0:devel/py-coloredlogs \
		ca_root_nss>0:security/ca_root_nss \
		git-lite>0:devel/git-lite \
		${PYTHON_PKGNAMEPREFIX}texttable>=0.8.7:textproc/py-texttable \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=2.0.0:devel/py-pytest-runner \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests

USE_GITHUB=	yes
GH_TAGNAME=	b8ce435094e182c96248014a0032688b2c5daee2

NO_ARCH=	yes
USES=		python:3.6
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
