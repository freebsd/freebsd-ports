PORTNAME=	bitvector
PORTVERSION=	3.5.0
CATEGORIES=	math python
MASTER_SITES=	PYPI \
		https://engineering.purdue.edu/kak/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	BitVector-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Pure-Python memory-efficient packed representation for bit arrays
WWW=		https://engineering.purdue.edu/kak/dist/

LICENSE=	PSFL

USES=		python

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
