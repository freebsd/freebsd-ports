# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblinear
PORTVERSION=	2.1
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/liblinear/ \
		http://www.csie.ntu.edu.tw/~cjlin/liblinear/oldfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for Large Linear Classification

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		zip

PORTDOCS=	COPYRIGHT README

PLIST_FILES=	bin/train bin/predict

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

# same as LIBLINEAR itself
OPTIMIZED_CFLAGS_CFLAGS=		-Wall -O3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/train ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/predict ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in ${PORTDOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DOCSDIR}; \
	done

.include <bsd.port.mk>
