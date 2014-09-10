# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	harminv
PORTVERSION=	1.3.1
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/harminv/

MAINTAINER=	devel@stasyan.com
COMMENT=	Solver of harmonic inversion

USES=		fortran gmake libtool
GNU_CONFIGURE=	yes
USE_GCC=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LD_LIBRARY_PATH=	-L${LOCALBASE}/lib -L/usr/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LD_LIBRARY_PATH="${LD_LIBRARY_PATH}"
USE_LDCONFIG=	yes

LIB_DEPENDS+=	libguile.so:${PORTSDIR}/lang/guile \
		libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack

post-patch:
	${REINPLACE_CMD} -e 's#%%PKGDIR%%#${PREFIX}/libdata#g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
