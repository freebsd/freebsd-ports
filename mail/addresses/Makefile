# New ports collection makefile for:    Addresses
# Date created:         13 Nov 2004
# Whom:                 Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	addresses
PORTVERSION=	0.4.6
CATEGORIES=	mail
MASTER_SITES=	http://giesler.biz/bjoern/downloads/ \
		http://www.energyhq.es.eu.org/files/
DISTNAME=	Addresses-${PORTVERSION}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	A versatile addressbook for GNUstep

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/Addresses-${PORTVERSION}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
LDCONFIG_DIRS=	${LOCALLIBDIR}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
