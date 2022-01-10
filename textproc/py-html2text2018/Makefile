# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>

PORTNAME=	html2text
PORTVERSION=	2018.1.9
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2018

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Convert HTML into clean plain ASCII text

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

CONFLICTS_INSTALL=	html2text py*-html2text # bin/html2text

do-test:
	@cd ${WRKSRC} && coverage run --source=html2text setup.py test -v

.include <bsd.port.mk>
