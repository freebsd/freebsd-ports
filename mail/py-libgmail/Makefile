# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	libgmail
DISTVERSION=	0.1.11
CATEGORIES=	mail python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to provide access to Gmail via Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mechanize>=0:www/py-mechanize@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mechanize>=0:www/py-mechanize@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
