# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	queequeg
PORTVERSION=	0.91
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny English grammar checker

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		wn:${PORTSDIR}/textproc/wordnet \
		${PYTHON_SITELIBDIR}/cdbmodule.so:${PORTSDIR}/databases/py-cdb
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_SITELIBDIR}/cdbmodule.so:${PORTSDIR}/databases/py-cdb

USE_PYTHON=	2
MAKE_ARGS=	dict WORDNETDICT="${LOCALBASE}/share/WordNet"

PORTDOCS=	address.png index-e.html index.html

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/qq ${STAGEDIR}${DATADIR}
	${LN} -shf ${DATADIR}/qq ${STAGEDIR}${PREFIX}/bin/qq
	${INSTALL_DATA} ${WRKSRC}/*.py ${WRKSRC}/dict.cdb ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/htdocs; ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
