# New ports collection makefile for: libghemical
# Date created:			July 3, 2006
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libghemical
PORTVERSION=	2.10
CATEGORIES=	science
MASTER_SITES=	http://www.uku.fi/~thassine/projects/download/ \
		http://bioinformatics.org/ghemical/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Support libraries of science/ghemical port

BUILD_DEPENDS=	${LOCALBASE}/lib/libmpqc.a:${PORTSDIR}/science/mpqc \
		openbabel:${PORTSDIR}/science/openbabel \
		mopac7:${PORTSDIR}/biology/mopac

USE_GMAKE=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=   yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.1:${PORTSDIR}/math/atlas
CONFIGURE_ARGS+=	--with-blas="-L${LOCALBASE}/lib -lf77blas -lcblas -latlas" \
			--with-lapack=-lalapack
.else
LIB_DEPENDS+=		blas.1:${PORTSDIR}/math/blas
CONFIGURE_ARGS+=	--with-blas="-L${LOCALBASE}/lib -lblas" \
			--with-lapack=-lapack
.endif
CONFIGURE_ARGS+=	--enable-mopac7 --enable-mpqc --enable-openbabel

USE_AUTOTOOLS=	autoconf:259
PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"

pre-configure:
	@cd ${WRKDIR}/${DISTNAME} ; ${AUTOCONF}

.include <bsd.port.post.mk>
