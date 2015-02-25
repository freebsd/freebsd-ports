# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pystemmer
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP \
		http://snowball.tartarus.org/wrappers/
DISTNAME=	PyStemmer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Snowball Stemming Algorithms for Information Retrieval

USES=		python
USE_PYTHON=	distutils autoplist

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Stemmer.so

.include <bsd.port.mk>
