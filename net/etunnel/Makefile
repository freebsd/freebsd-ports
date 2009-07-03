# New ports collection makefile for:	etunnel
# Date created:		03.05.2004
# Whom:			Kostas Petrikas <expl@punktas.lt>
#
# $FreeBSD$
#

PORTNAME=	etunnel
PORTVERSION=	0.0.5
CATEGORIES=	net
MASTER_SITES=	http://www.iem.pw.edu.pl/ftp/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP/UDP connections tunneling tool via proxy or directly

ALL_TARGET=	${PORTNAME}

MAN1=	etunnel.1

post-patch:
	@${REINPLACE_CMD} -e \
	's|CC=gcc|CC?=gcc|g ; \
	s|PREFIX=|PREFIX?=|g ; \
	s|CFLAGS=|CFLAGS+=|g' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
