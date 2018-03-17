# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	html2text
PORTVERSION=	2018.1.9
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Convert HTML into clean plain ASCII text

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

CONFLICTS=	html2text

do-test:
	@cd ${WRKSRC} && coverage run --source=html2text setup.py test -v

.include <bsd.port.mk>
