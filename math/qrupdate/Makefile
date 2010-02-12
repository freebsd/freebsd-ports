# New ports collection makefile for:	qrupdate
# Date created:		4 August 2009
# Whom:			Robert Jenssen
#
# $FreeBSD$
#

PORTNAME=	qrupdate
PORTVERSION=	1.1.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	qrupdate/qrupdate/1.1

MAINTAINER=	robertjenssen@ozemail.com.au
COMMENT=	Fortran library for fast updates of QR and Cholesky decomposition

LIB_DEPENDS=	blas.2:${PORTSDIR}/math/blas lapack.4:${PORTSDIR}/math/lapack

FETCH_ARGS=	-p

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

USE_FORTRAN=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%FFLAGS%%+${FFLAGS}+g ; \
		s+%%PICFLAG%%+${PICFLAG}+g ; ' \
		${WRKSRC}/Makeconf

.include <bsd.port.post.mk>
