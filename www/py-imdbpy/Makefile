# Created by: ijliao
# $FreeBSD$

PORTNAME=	imdbpy
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	SF/${PORTNAME}/IMDbPY/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IMDbPY-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Retrieve and manage the data of the IMDb movie database

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.6.1:databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy07>=0:databases/py-sqlalchemy07 \
		${PYTHON_PKGNAMEPREFIX}sqlobject>=0:databases/py-sqlobject

OPTIONS_DEFINE=	DOCS

USES=		python:2 shebangfix
SHEBANG_FILES=	docs/goodies/reduce.sh
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
