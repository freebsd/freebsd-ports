# New ports collection makefile for: libghemical
# Date created:			July 3, 2006
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libghemical
PORTVERSION=	2.10
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/ \
		http://bioinformatics.org/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

BUILD_DEPENDS=	openbabel:${PORTSDIR}/science/openbabel \
		mopac7:${PORTSDIR}/biology/mopac
LIB_DEPENDS+=	mpqc:${PORTSDIR}/science/mpqc \
		f2c:${PORTSDIR}/lang/f2c

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=   yes

.include <bsd.port.pre.mk>

USE_FORTRAN=	yes
CONFIGURE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS=		-lf77blas -latlas
LAPACK=		-lalapack
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
BLAS=		-lblas
LAPACK=		-llapack
.endif

CONFIGURE_ARGS+=	--enable-mopac7 --enable-mpqc --enable-openbabel --with-blas="-L${LOCALBASE}/lib ${BLAS}" -with-lapack="-L${LOCALBASE}/lib ${LAPACK}"

USE_AUTOTOOLS=	autoconf:261
PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"

.include <bsd.port.post.mk>
