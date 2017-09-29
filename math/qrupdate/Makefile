# Created by: Robert Jenssen
# $FreeBSD$

PORTNAME=	qrupdate
PORTVERSION=	1.1.2
PORTREVISION=	6
CATEGORIES=	math
MASTER_SITES=	SOURCEFORGE/qrupdate/qrupdate/1.2

MAINTAINER=	robertjenssen@ozemail.com.au
COMMENT=	Fortran library for fast updates of QR and Cholesky decomposition

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack

USES=		fortran gmake

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
BROKEN=		Does not compile on sparc64: assertions fail
.else
PICFLAG?=	-fpic
.endif

USE_LDCONFIG=	yes

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%FFLAGS%%+${FFLAGS}+g ; \
		s+%%PICFLAG%%+${PICFLAG}+g ; ' \
		${WRKSRC}/Makeconf

.include <bsd.port.post.mk>
