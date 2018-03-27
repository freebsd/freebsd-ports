# $FreeBSD$

PORTNAME=	python-utils
PORTVERSION=	2.3.0
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Collection of small functions and classes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
