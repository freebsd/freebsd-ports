# ex:ts=8
# New ports collection makefile for:	gubby
# Date created:			Feb 4, 2003
# Whom:				mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	gubby
PORTVERSION=	0.3.2
CATEGORIES=	mail
MASTER_SITES=	http://sublevel3.org/~csl/gubby/dist/

MAINTAINER=	mich@freebsdcluster.org
COMMENT=	A program showing where new mail has been placed

LDFLAGS+=	-lncurses -ltermcap
CFLAGS+=	-felide-constructors -fno-default-inline

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CFLAGS} -o ${PORTNAME} -Iinclude/ ${LDFLAGS} src/gubby.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gubby ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
