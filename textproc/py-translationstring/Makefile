# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	translationstring
PORTVERSION=	1.4
CATEGORIES=	textproc www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Utility library for i18n relied on by various Repoze packages

LICENSE=	BSDMV
LICENSE_NAME=	BSD Modification Variant
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py-babel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py test

.include <bsd.port.mk>
