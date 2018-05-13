# $FreeBSD$

PORTNAME=	citeproc-py-styles
DISTVERSION=	0.1.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Static resources package for citeproc-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=2.6.2:devel/py-pytest-runner@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.6.0:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
