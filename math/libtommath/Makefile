# $FreeBSD$

PORTNAME=	libtommath
PORTVERSION=	0.42.0
CATEGORIES=	math
MASTER_SITES=	http://libtom.org/files/
DISTNAME=	ltm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable mathematical routines

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	default
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	include/tommath.h include/tommath_class.h \
		include/tommath_superclass.h lib/libtommath.a

.include <bsd.port.mk>
