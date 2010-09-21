# New ports collection makefile for:	giacxcas
# Date created:		2010-08-26
# Whom:			Frederic Han <han@math.jussieu.fr>
#
# $FreeBSD$
#

PORTNAME=	giacxcas
PORTVERSION=	0.9.0
CATEGORIES=	math
MASTER_SITES=	http://people.math.jussieu.fr/~han/xcas/sources/ \
		http://www.institut.math.jussieu.fr/~han/xcas/sources/
DISTFILES=	fltkdev.tgz CoCoALib.tgz giac-${PORTVERSION}.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	han@math.jussieu.fr
COMMENT=	Computer algebra system by Bernard Parisse

BUILD_DEPENDS=	hevea:${PORTSDIR}/textproc/hevea \
		latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex\
		${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl
PATCH_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		pari:${PORTSDIR}/math/pari \
		mpfr:${PORTSDIR}/math/mpfr \
		gsl:${PORTSDIR}/math/gsl

NO_CDROM=	The french documentation is for non commercial only use

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_XORG=	xcursor xft xi
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${FLTKDEV-GIAC} -I${COCOALIB-GIAC}/include -I${LOCALBASE}/include
LDFLAGS+=	-L${FLTKDEV-GIAC}/lib -L${COCOALIB-GIAC}/lib -L${LOCALBASE}/lib
CXXFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

WRKSRC=		${WRKDIR}/giac-${PORTVERSION}
FLTKDEV-GIAC=	${WRKDIR}/fltk-1.3.x-r6916
COCOALIB-GIAC=	${WRKDIR}/CoCoALib-0.9937

INFO=		giac_es giac_us

post-patch:
	${REINPLACE_CMD} -e 's|make |${GMAKE} |g' `${GREP} -Rl 'make ' ${COCOALIB-GIAC}`;
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g' `${GREP} -Rl '/bin/bash' ${COCOALIB-GIAC}`;

pre-configure:
	cd ${COCOALIB-GIAC} && \
	./configure --with-libgmp=${LOCALBASE}/lib/libgmp.a && \
	${GMAKE} library && \
	cd ${FLTKDEV-GIAC} && \
	./configure --prefix=${FLTKDEV-GIAC} \
	&& ${MAKE}

.include <bsd.port.mk>
