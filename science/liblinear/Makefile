# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	liblinear
PORTVERSION=	1.94
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/liblinear/ \
		http://www.csie.ntu.edu.tw/~cjlin/liblinear/oldfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A library for Large Linear Classification

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

USES=		zip

TXT_DOCS=	COPYRIGHT README

PLIST_FILES=	bin/train bin/predict

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	${TXT_DOCS}
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
# same as LIBLINEAR itself
CFLAGS=		-Wall -O3
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/train ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/predict ${STAGEDIR}${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DOCSDIR}; \
	done
.endif

.include <bsd.port.post.mk>
