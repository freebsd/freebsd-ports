# ex:ts=8
# Ports collection makefile for:	texpower
# Date created:			Dec 30, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	texpower
PORTVERSION=	0.0.9d
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creating dynamic online presentations with LaTeX

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/texmf/tex/latex/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.sty *.cls *.cfg ${PREFIX}/share/texmf/tex/latex/${PORTNAME}

.include <bsd.port.mk>
