# New ports collection makefile for:    calc
# Date created:         3 October 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	calc
PORTVERSION=	2.12.4.0
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.12.4

MAINTAINER=	johans@stack.nl
COMMENT=	Arbitrary precision calculator

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		calc.1

CALCPAGER?=	more
MAKE_ENV+=	CALCPAGER="${CALCPAGER}" CAT="${CAT}" CHMOD="${CHMOD}" CP="${CP}" \
		GMAKE="${GMAKE}" LN="${LN}" MKDIR="${MKDIR}" MV="${MV}" RM="${RM}" \
		SED="${SED}" TOUCH="${TOUCH}" TRUE="${TRUE}"

PLIST_SUB+=	VERSION=${PORTVERSION}	VER1=${PORTVERSION:R} \
		VER2=${PORTVERSION:R:R}	VER3=${PORTVERSION:R:R:R}

regression-test: build
	( cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} check )

.include <bsd.port.mk>
