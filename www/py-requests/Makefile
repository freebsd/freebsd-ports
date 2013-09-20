# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	requests
PORTVERSION=	1.2.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	HTTP library written in Python for human beings

LICENSE=	ISCL

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} test_requests.py

NO_STAGE=	yes
.include <bsd.port.mk>
