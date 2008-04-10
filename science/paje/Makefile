# New ports collection makefile for:    paje
# Date created:         26 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	paje
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	science gnustep
MASTER_SITES=	http://download.fr2.forge.objectweb.org/ \
		http://download.forge.objectweb.org/paje/ \
		http://download.zh.forge.objectweb.org/paje/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	Paje_${PORTVERSION}

MAINTAINER=	gurkan@phys.ethz.ch
COMMENT=	Generic visualization tool for GNUstep (Gantt chart and more)

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
