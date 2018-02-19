# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	queequeg
PORTVERSION=	0.91
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny English grammar checker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	wn:textproc/wordnet \
		${PYTHON_SITELIBDIR}/cdbmodule.so:databases/py-cdb
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cdbmodule.so:databases/py-cdb

USES=		python:2.7 shebangfix
SHEBANG_FILES=	*.py misc/*.py qq
ALL_TARGET=	dict
MAKE_ARGS=	WORDNETDICT="${LOCALBASE}/share/WordNet" \
		PYTHON="${PYTHON_CMD}"
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/qq ${STAGEDIR}${DATADIR}
	${LN} -shf ${DATADIR}/qq ${STAGEDIR}${PREFIX}/bin/qq
	${INSTALL_DATA} ${WRKSRC}/*.py ${WRKSRC}/dict.cdb ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/htdocs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
