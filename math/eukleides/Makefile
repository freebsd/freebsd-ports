# ex:ts=8
# Ports collection makefile for:	eukleides
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eukleides
PORTVERSION=	0.9.2.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/
DISTNAME=	${PORTNAME}.${PORTVERSION:R}rev${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Euclidean geometry drawing language

RUN_DEPENDS=	pstoedit:${PORTSDIR}/graphics/pstoedit \
		epstopdf:${PORTSDIR}/print/teTeX

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION:R}

USE_BISON=	yes
USE_GMAKE=	yes

MAN1=	eukleides.1
MLINKS=	eukleides.1 euk2eps.1 eukleides.1 euk2edit.1

.include <bsd.port.mk>
