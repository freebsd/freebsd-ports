# New ports collection Makefile for: liblr
# Date created:                      May 14 2007
# Whom:                              Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liblinear
PORTVERSION=	1.34
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/liblinear/ \
		http://www.csie.ntu.edu.tw/~cjlin/liblinear/oldfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A library for Large Linear Classification

OPTIONS=	OCFLAGS "Use optimized CFLAGS" On

USE_ZIP=	yes

TXT_DOCS=	COPYRIGHT README

.if !defined(NOPORTDOCS)
PORTDOCS=	${TXT_DOCS}
.endif

PLIST_FILES=	bin/train bin/predict

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OCFLAGS)
# same as LIBLINEAR itself
CFLAGS=		-Wall -O3
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/train ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/predict ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.post.mk>
