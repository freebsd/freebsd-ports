# ex:ts=8
# Ports collection makefile for:	xmlindent
# Date created:			Apr 1, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlindent
PORTVERSION=	0.2.5
CATEGORIES=	textproc
MASTER_SITES=	http://www.cs.helsinki.fi/u/penberg/xmlindent/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A XML stream reformatter

MAN1=	xmlindent.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlindent ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmlindent.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
