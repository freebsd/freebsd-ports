# New ports collection Makefile for: libsvm
# Date created:         Oct 28 2001
# Whom:                 Chia-Hsing Yu <davidyu@oio.cx>
#
# $FreeBSD$
#

PORTNAME=	libsvm
PORTVERSION=	2.33
CATEGORIES=	science math
MASTER_SITES=	http://www.csie.ntu.edu.tw/~cjlin/libsvm/

MAINTAINER=	davidyu@oio.cx

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/libsvm
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/libsvm
.endif

.include <bsd.port.mk>
