# New ports collection makefile for:    etoile-bookmarkkit
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	bookmarkkit
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~%%SUBDIR%%/distfiles/
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project BookmarkKit framework

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	CollectionKit:${COLLECTIONKIT_PORT}
DEFAULT_LIBVERSION=	0.1
USE_GNUSTEP_LDCONFIG=	${SYSLIBDIR}

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/BookmarkKit

COLLECTIONKIT_PORT?=	devel/etoile-collectionkit

.include <bsd.port.mk>
