# New ports collection makefile for:	qtiplot-doc
# Date created:		2006-09-08
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	qtiplot-doc
PORTVERSION=	0.9
CATEGORIES=	math
MASTER_SITES=	http://soft.proindependent.com/doc/
DISTNAME=	manual-en

MAINTAINER=	makc@issp.ac.ru
COMMENT=	The QtiPlot Handbook

USE_BZIP2=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/qtiplot/manual

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR}

.include <bsd.port.mk>
