# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	qpy
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/qpy/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generating safely-quoted html text from python code

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	autoplist distutils
USES=		python:2.7

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt

post-build:
	@${STRIP_CMD} ${WRKSRC}/build/lib.*/qpy/quoted.so

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
