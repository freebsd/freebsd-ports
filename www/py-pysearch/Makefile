# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	pysearch
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/pYsearch/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pYsearch-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Yahoo Search Web Services SDK for Python

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7 shebangfix
SHEBANG_FILES=	examples/profile.py \
		examples/websearch.py
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	pYsearch

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
