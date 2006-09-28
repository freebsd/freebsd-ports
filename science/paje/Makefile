# New ports collection makefile for:    paje
# Date created:         26 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	paje
PORTVERSION=	1.4.0
CATEGORIES=	science
MASTER_SITES=	http://download.fr2.forge.objectweb.org/ \
		http://download.forge.objectweb.org/paje/ \
		http://download.zh.forge.objectweb.org/paje/ \
		http://florida.ethz.ch/ports/distfiles/
DISTNAME=	Paje_${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Generic visualization tool for GNUstep (Gantt chart and more)

WRKSRC=	${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
