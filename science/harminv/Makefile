# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

PORTNAME=	harminv
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/harminv/

MAINTAINER=	devel@stasyan.com
COMMENT=	Solver of harmonic inversion

USES=		fortran gmake
GNU_CONFIGURE=	yes
USE_GCC=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LD_LIBRARY_PATH=	-L${LOCALBASE}/lib -L/usr/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LD_LIBRARY_PATH="${LD_LIBRARY_PATH}"
USE_LDCONFIG=	yes

MAN1=	harminv.1

LIB_DEPENDS+=	guile.21:${PORTSDIR}/lang/guile \
		blas.2:${PORTSDIR}/math/blas \
		lapack.4:${PORTSDIR}/math/lapack

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's#%%PKGDIR%%#${PREFIX}/libdata#g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
