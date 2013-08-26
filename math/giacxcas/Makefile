# Created by: Frederic Han <han@math.jussieu.fr>
# $FreeBSD$

PORTNAME=	giacxcas
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www-fourier.ujf-grenoble.fr/~parisse/giac/freebsd/ \
		http://people.math.jussieu.fr/~han/xcas/sources/
DISTFILES=	fltk-giac.tar.gz CoCoALib-0.9950.tgz giac-${PORTVERSION}.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	han@math.jussieu.fr
COMMENT=	Computer algebra system by Bernard Parisse

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/lib/libntl.a:${PORTSDIR}/math/ntl
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		pari:${PORTSDIR}/math/pari \
		mpfr:${PORTSDIR}/math/mpfr \
		gsl:${PORTSDIR}/math/gsl \
		lapack:${PORTSDIR}/math/lapack

NO_CDROM=	French documentation is for non-commercial use only

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_XORG=	xcursor xft xi
USE_TEX=	latex:build dvipsk:build
USE_LDCONFIG=	yes
USES=		gettext

DOCSDIR=	${PREFIX}/share/doc/giac
PORTDOCS=	*
DATADIR=	${PREFIX}/share/giac
PORTDATA=	*

CPPFLAGS+=	-I${FLTKDEV-GIAC} -I${COCOALIB-GIAC}/include -I${LOCALBASE}/include
LDFLAGS+=	-L${FLTKDEV-GIAC}/lib -L${COCOALIB-GIAC}/lib -L${LOCALBASE}/lib
CXXFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/giac-${PORTVERSION}
FLTKDEV-GIAC=	${WRKDIR}/fltk-1.3.0
COCOALIB-GIAC=	${WRKDIR}/CoCoALib-0.9950

INFO=		giac_es giac_us

post-patch:
	@${GREP} -Rl --null /bin/bash ${COCOALIB-GIAC} | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|'
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' \
		${WRKSRC}/xcas.applications ${WRKSRC}/xcas.desktop

pre-configure:
	cd ${COCOALIB-GIAC} && \
	./configure --with-libgmp=${LOCALBASE}/lib/libgmp.a && \
	${GMAKE} library && \
	cd ${FLTKDEV-GIAC} && \
	./configure --prefix=${FLTKDEV-GIAC} \
	&& ${MAKE}

.include <bsd.port.mk>
