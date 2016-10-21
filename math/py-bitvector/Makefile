# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	bitvector
PORTVERSION=	3.4.4
CATEGORIES=	math python
MASTER_SITES=	https://engineering.purdue.edu/kak/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BitVector-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Pure-Python memory-efficient packed representation for bit arrays

LICENSE=	PSFL

USES=		python
USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	BitVector

PORTDOCS=	README BitVector-${PORTVERSION}.html

post-extract:
	@${RM} ${WRKSRC}/test.py

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

regression-test:
	@(cd ${WRKSRC}/TestBitVector && ${PYTHON_CMD} Test.py)

.include <bsd.port.mk>
