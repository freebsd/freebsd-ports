# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	transifex-client
PORTVERSION=	0.10
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Command line interface for Transifex

LICENSE=	GPLv2

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

USE_GITHUB=		yes
USE_PYTHON=		-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

GH_ACCOUNT=	transifex
GH_COMMIT=	84c9dcc

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
