# New ports collection makefile for:	amcl
# Date created:				15 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	amcl
PORTVERSION=	0.7.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.localhost.nu/apps/amcl/tars/ \
		http://amcl.alliances.org/tars/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}pl1

MAINTAINER=	will@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
