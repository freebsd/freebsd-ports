# New ports collection makefile for:	oof
# Date created:		19 June 2006
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	oof
PORTVERSION=	1.037
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://www.ctcms.nist.gov/~langer/OOFdownload/SRC/
DISTNAME=	${PORTNAME}-dist${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finite Element Analysis of Real Material Microstructures

LIB_DEPENDS+=	forms.1:${PORTSDIR}/x11-toolkits/xforms
.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS_LIBS=	-lf77blas -latlas
.else
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS_LIBS=	-lblas
.endif

USE_FORTRAN=	yes
FORTRANLIBDIR=	`${DIRNAME} \`${FC} -print-libgcc-file-name\``
FORTRANLIBDIR2=	`${DIRNAME} \`${FC} -print-libgcc-file-name\``/../../../
FORTRANLIBS=	-lgfortranbegin -lgfortran

CXXFLAGS+=	-DDONT_HAVE_STRSTREAM_H -DNEED_FDSTREAM
.ifdef WITH_THERMAL
CXXFLAGS+=	-DTHERMAL
.endif
CXXFLAGS+=	-Wno-deprecated
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cxxflags='${CXXFLAGS}'	\
		--with-libdirs=-L${LOCALBASE}/lib	\
		--with-blas="-L${LOCALBASE}/lib ${BLAS_LIBS} -L/usr/local/lib -L${FORTRANLIBDIR} -L${FORTRANLIBDIR2} ${FORTRANLIBS}"

ALL_TARGET=	all
PLIST_FILES=	bin/oof bin/ppm2oof

.ifndef WITH_THERMAL
ALL_TARGET+=	oof2abaqus
PLIST_FILES+=	bin/oof2abaqus
.endif

.include <bsd.port.pre.mk>

BROKEN=		Broken with GCC 4.2 and beyond
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2009-03-22

.if ${ARCH}==sparc64
BROKEN=		does not compile on ${ARCH}
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/XOOF/oof ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/XPPM2OOF/ppm2oof ${PREFIX}/bin
.ifndef WITH_THERMAL
	@${INSTALL_PROGRAM} ${WRKSRC}/OOF2ABAQUS/oof2abaqus ${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
