# New ports collection makefile for:	ksubeditor
# Date created:         Thu Nov 21 15:05:53 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	KSubeditor
PORTVERSION=	0.13.r1
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME:L}-${PORTVERSION:R}${PORTVERSION:E:S/^r/rc/}

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=	${WRKDIR}/${PORTNAME:L}-${PORTVERSION:R}

USE_KDELIBS_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=''

.include <bsd.port.mk>
