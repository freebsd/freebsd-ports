# New ports collection makefile for:	makeztxt
# Date created:		Oct 19, 2002
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	makeztxt
PORTVERSION=	1.43
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gutenpalm
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	roman@xpert.com
COMMENT=	Command line utility to create GutenPalm's zTXT format databases

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makeztxt ${LOCALBASE}/bin/

.include <bsd.port.mk>
