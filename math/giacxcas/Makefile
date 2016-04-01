# Created by: Frederic Han <han@math.jussieu.fr>
# $FreeBSD$

PORTNAME=	giacxcas
PORTVERSION=	1.1.0
PORTREVISION=	10
CATEGORIES=	math
MASTER_SITES=	http://www-fourier.ujf-grenoble.fr/~parisse/giac/ \
		http://www.math.jussieu.fr/~han/xcas/sources/v2/
DISTFILES=	fltk-giac.tar.gz CoCoALib-0.9950.tgz giac-${PORTVERSION}.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Computer algebra system by Bernard Parisse

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/lib/libntl.a:math/ntl
LIB_DEPENDS=	libgmp.so:math/gmp \
		libpng.so:graphics/png \
		libpari.so:math/pari \
		libmpfr.so:math/mpfr \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack

NO_CDROM=	French documentation is for non-commercial use only

GNU_CONFIGURE=	yes
USES=		desktop-file-utils gettext gmake jpeg libtool shebangfix
USE_GL=		gl
USE_XORG=	x11 xcursor xft xi
USE_TEX=	latex:build dvipsk:build
USE_LDCONFIG=	yes
# Warning:  don't remove the USE_GCC without a runtime test *after* make install
USE_GCC=	yes
DOCSDIR=	${PREFIX}/share/doc/giac
PORTDOCS=	*
DATADIR=	${PREFIX}/share/giac
PORTDATA=	*
SHEBANG_FILES=	src/pgiac
INSTALL_TARGET=	install-strip

CONFIGURE_ENV=	X_LIBS=-lX11
CPPFLAGS+=	-I${FLTKDEV-GIAC} -I${COCOALIB-GIAC}/include -I${LOCALBASE}/include
LDFLAGS+=	-L${FLTKDEV-GIAC}/lib -L${COCOALIB-GIAC}/lib -L${LOCALBASE}/lib
CXXFLAGS+=	-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/giac-${PORTVERSION}
FLTKDEV-GIAC=	${WRKDIR}/fltk-1.3.0
COCOALIB-GIAC=	${WRKDIR}/CoCoALib-0.9950

INFO=		giac_es giac_us

.include <bsd.port.options.mk>

#NB: built of giacxcas with USE_GCC and nlt is successfull if the ntl port is also
#    installed  with USE_GCC
.if ${OSVERSION} >= 1000000
CONFIGURE_ARGS+=	--disable-ntl
.endif

post-patch:
	@${GREP} -Rl --null /bin/bash ${COCOALIB-GIAC} | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|'
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' \
		${WRKSRC}/xcas.applications ${WRKSRC}/xcas.desktop
.if ${OSVERSION} >= 1000000
	@${REINPLACE_CMD} -e 's|friend class Fl_Group;|friend class Fl_Group;friend class Fl_X;|' \
		${FLTKDEV-GIAC}/FL/Fl_Widget.H
.endif

pre-configure:
	cd ${COCOALIB-GIAC} && \
	./configure --with-libgmp=${LOCALBASE}/lib/libgmp.a --with-cxx=${CXX}&& \
	${MAKE_CMD} library && \
	cd ${FLTKDEV-GIAC} && \
	./configure --prefix=${FLTKDEV-GIAC} \
	&& cd src && ${MAKE}

.include <bsd.port.mk>
