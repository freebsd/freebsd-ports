# ex:ts=8
# New ports collection makefile for:	gubby
# Date created:			Feb 4, 2003
# Whom:				mich@freebsdcluster.org
#
# $FreeBSD$
#

PORTNAME=	gubby
PORTVERSION=	0.4.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	mich@freebsdcluster.org
COMMENT=	A program showing where new mail has been placed

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

LDFLAGS+=	-lncurses -ltermcap
CFLAGS+=	-felide-constructors -fno-default-inline

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CFLAGS} -o ${PORTNAME} -Iinclude/ ${LDFLAGS} src/gubby.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gubby ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${DOCSDIR}/README
.endif

MAN1=		gubby.1
.include <bsd.port.mk>
