# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	requests1
PORTVERSION=	1.2.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP library written in Python for human beings (Version 1.x)

LICENSE=	ISCL

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

CONFLICTS_INSTALL=	py*-requests-*

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} test_requests.py

.include <bsd.port.mk>
