# Ports collection makefile for:  tomsfastmath
# Date created:			  05 Aug 2005
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	tomsfastmath
PORTVERSION=	0.10
CATEGORIES=	math
MASTER_SITES=	http://tfm.libtomcrypt.com/files/ \
		http://www.atarininja.org/~wxs/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
DISTNAME=	tfm-${PORTVERSION}

MAINTAINER=	wxs@atarininja.org
COMMENT=	Portable fixed precision math library for fast exponentiations

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	default

PLIST_FILES=	include/tfm.h lib/libtfm.a

NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON_ia64=	fails to compile

.include <bsd.port.mk>
