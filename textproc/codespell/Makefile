PORTNAME=	codespell
PORTVERSION=	2.2.1
CATEGORIES=	textproc
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code spelling checker
WWW=		https://github.com/codespell-project/codespell

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils noflavors

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
