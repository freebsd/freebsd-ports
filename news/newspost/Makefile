# ex:ts=8
# Ports collection makefile for:  newspost
# Date created:                          Tue Jul 23, 2002
# Whom:                                  Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	newspost
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://newspost.unixcab.org/download/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Newspost is a full-featured USEnet binary autoposter

ALL_TARGET=	main
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/man1/newspost.1 ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

MAN1=		newspost.1

.include <bsd.port.mk>
