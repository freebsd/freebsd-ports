PORTNAME=	qrupdate
PORTVERSION=	1.1.2
PORTREVISION=	13
CATEGORIES=	math
MASTER_SITES=	SOURCEFORGE/qrupdate/qrupdate/1.2

MAINTAINER=	robertjenssen@ozemail.com.au
COMMENT=	Fortran library for fast updates of QR and Cholesky decomposition
WWW=		http://qrupdate.sourceforge.net/

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		fortran gmake
USE_LDCONFIG=	yes

PICFLAG?=	-fpic

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%FFLAGS%%+${FFLAGS}+g ; \
		s+%%PICFLAG%%+${PICFLAG}+g ; ' \
		${WRKSRC}/Makeconf

.include <bsd.port.mk>
