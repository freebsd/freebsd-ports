# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	bitvector
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BitVector-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Pure-Python memory-efficient packed representation for bit arrays

LICENSE=	PSFL

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	BitVector

PORTDOCS=	README BitVector-${PORTVERSION}.html

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/BitVector.py \
		%%PYTHON_SITELIBDIR%%/BitVector.pyc \
		%%PYTHON_SITELIBDIR%%/BitVector.pyo

post-extract:
	@${RM} -f ${WRKSRC}/test.py

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

regression-test:
	@(cd ${WRKSRC}/TestBitVector && ${PYTHON_CMD} Test.py)

.include <bsd.port.mk>
