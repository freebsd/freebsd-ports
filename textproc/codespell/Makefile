PORTNAME=	codespell
PORTVERSION=	2.2.2
CATEGORIES=	textproc
MASTER_SITES=	PYPI

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code spelling checker
WWW=		https://github.com/codespell-project/codespell

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils noflavors

NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

SHEBANG_FILES=	bin/codespell

.include <bsd.port.mk>
