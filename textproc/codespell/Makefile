# $FreeBSD$

PORTNAME=	codespell
PORTVERSION=	2.0.0
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code spelling checker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils noflavors

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
