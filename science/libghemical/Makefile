# New ports collection makefile for: libghemical
# Date created:			July 3, 2006
# Whom:				Nakata Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libghemical
PORTVERSION=	2.00
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
CONFIGURE_ARGS=	--enable-mopac7 --enable-mpqc --enable-openbabel \
		--with-blas="-L${LOCALBASE}/lib -lf77blas -lcblas -latlas" \
		--with-lapack=-lalapack

USE_AUTOTOOLS=	autoconf:259
PLIST_SUB=	LIBGHEMICAL_VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKDIR}/${DISTNAME} ; ${AUTOCONF}

.include <bsd.port.post.mk>
