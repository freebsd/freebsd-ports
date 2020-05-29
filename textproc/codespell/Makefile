# $FreeBSD$

PORTNAME=	codespell
PORTVERSION=	1.17.1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code spelling checker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.4+
USE_PYTHON=	autoplist concurrent distutils

USE_GITHUB=	yes
GH_ACCOUNT=	codespell-project

NO_ARCH=	yes

SUB_FILES+=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
