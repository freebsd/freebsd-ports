# Created by: jmz
# $FreeBSD$

PORTNAME=	calc
PORTVERSION=	2.12.4.13
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Arbitrary precision calculator

USES=		gmake tar:bzip2 readline
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

CALCPAGER?=	more
MAKE_ENV+=	CALCPAGER="${CALCPAGER}" CAT="${CAT}" CHMOD="${CHMOD}" \
		CP="${CP}" GMAKE="${MAKE_CMD}" LN="${LN}" MKDIR="${MKDIR}" \
		MV="${MV}" RM="${RM}" SED="${SED}" TOUCH="${TOUCH}" \
		TRUE="${TRUE}"
.if !exists(/usr/lib/libreadline.so)
MAKE_ARGS=	READLINE_INCLUDE="-I${LOCALBASE}/include" \
		READLINE_LIB="-L${LOCALBASE}/lib -lreadline"
.endif

PLIST_SUB+=	VERSION=${PORTVERSION}	VER1=${PORTVERSION:R} \
		VER2=${PORTVERSION:R:R}	VER3=${PORTVERSION:R:R:R}

regression-test: build
	( cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check )

.include <bsd.port.mk>
