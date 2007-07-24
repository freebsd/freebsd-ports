# New ports collection Makefile for: liblr
# Date created:                      May 14 2007
# Whom:                              Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liblr
PORTVERSION=	1.00
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/liblinear/oldfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	A library for Large Regularized Logistic Regression

OPTIONS=	OCFLAGS "Use optimized CFLAGS" On

USE_ZIP=	yes

MAKE_ENV=	CC="${CC}" CXXC="${CXX}"

TXT_DOCS=	COPYRIGHT README

.if !defined(NOPORTDOCS)
PORTDOCS=	${TXT_DOCS}
.endif

PLIST_FILES=	bin/lr-train bin/lr-predict

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OCFLAGS)
# same as LIBIR itself
CFLAGS=		-Wall -O3
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lr-train ${TARGETDIR}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/lr-predict ${TARGETDIR}/bin/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	for f in ${TXT_DOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif

.include <bsd.port.post.mk>
