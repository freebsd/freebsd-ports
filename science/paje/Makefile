# New ports collection makefile for:    paje
# Date created:         26 Sep 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	paje
PORTVERSION=	1.97
PORTREVISION=	2
CATEGORIES=	science gnustep
MASTER_SITES=	http://download.forge.objectweb.org/paje/ \
		http://download.zh.forge.objectweb.org/paje/
DISTNAME=	Paje_${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Generic visualization tool for GNUstep (Gantt chart and more)

LICENSE=	LGPL21

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${GNUSTEP_LOCAL_ROOT}

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DOMAIN|#GNUSTEP_INSTALLATION_DOMAIN|' \
                ${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
