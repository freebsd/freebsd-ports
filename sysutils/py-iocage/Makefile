# Created by: Bartlomiej Rutkowski <robak@FreeBSD.org>
# $FreeBSD$

PORTNAME=	iocage
PORTVERSION=	0.9.8.1
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
		${PYTHON_PKGNAMEPREFIX}requests>=2.11.1:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}pygit2>=0.24.1:devel/py-pygit2

USE_GITHUB=	yes
GH_TAGNAME=	822d006f37cf68447058f45099e630aef662ea49

NO_ARCH=	yes
USES=		python:3.6
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
