# ex:ts=8
# Ports collection makefile for:  Splitvt
# Date created:			  Fri Oct 4, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	splitvt
PORTVERSION=	1.6.6
CATEGORIES=	misc
MASTER_SITES=	http://www.devolution.com/~slouken/projects/splitvt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Run two shells in a split window/terminal

HAS_CONFIGURE=	yes
ALL_TARGET=
MAN1=		splitvt.1

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/config.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
