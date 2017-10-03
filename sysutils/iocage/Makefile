# $FreeBSD$

PORTNAME=	iocage
PORTVERSION=	0.9.9.1
PORTREVISION=   1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	FreeBSD jail manager written in Python3

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=2.0.0:devel/py3-pytest-runner
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=6.7:devel/py3-click \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.10.0:misc/py3-tqdm \
		${PYTHON_PKGNAMEPREFIX}coloredlogs>0:devel/py3-coloredlogs \
		${PYTHON_PKGNAMEPREFIX}verboselogs>0:devel/py3-verboselogs \
		ca_root_nss>0:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}texttable>=0.8.7:textproc/py3-texttable \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=2.0.0:devel/py3-pytest-runner \
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py3-requests \
		${PYTHON_PKGNAMEPREFIX}libzfs>=1.0.2:devel/py3-libzfs \
		${PYTHON_PKGNAMEPREFIX}pygit2>=0.24.1:devel/py3-pygit2

USE_GITHUB=	yes

NO_ARCH=	yes
USES=		python:3.6
USE_PYTHON=	autoplist distutils

CONFLICTS=	py-iocage-[0-9]* iocage-[0-9]* iocage-devel-[0-9]*

.include <bsd.port.mk>
