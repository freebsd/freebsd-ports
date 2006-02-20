# Ports collection makefile for:  libtommath
# Date created:			  05 Aug 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	libtommath
PORTVERSION=	0.38
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cperciva/libtom
DISTNAME=	ltm-${PORTVERSION}

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Comprehensive, modular and portable mathematical routines

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	default

PLIST_FILES=	include/tommath.h include/tommath_class.h \
		include/tommath_superclass.h lib/libtommath.a

.include <bsd.port.mk>
