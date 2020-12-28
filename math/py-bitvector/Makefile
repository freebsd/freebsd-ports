# $FreeBSD$

PORTNAME=	bitvector
PORTVERSION=	3.4.9
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP \
		https://engineering.purdue.edu/kak/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BitVector-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Pure-Python memory-efficient packed representation for bit arrays

LICENSE=	PSFL

USES=		python:3.6+

USE_PYTHON=	autoplist distutils
PYDISTUTILS_PKGNAME=	BitVector

NO_ARCH=	yes

PORTDOCS=	README BitVector-${PORTVERSION}.html
DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/test.py

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-test:
	@(cd ${WRKSRC}/TestBitVector && ${PYTHON_CMD} Test.py)

.include <bsd.port.mk>
