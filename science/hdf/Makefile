# New ports collection makefile for:	HDF_lib
# Date created:		17 November 1996
# Whom:			mi
#
# $FreeBSD$
#

PORTNAME=	hdf
PORTVERSION=	4.2r1
CATEGORIES=	science archivers graphics
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/HDF/HDF/HDF${PORTVERSION}/src/
DISTNAME=	HDF${PORTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

BUILD_DEPENDS=	${LOCALBASE}/bin/libtool15:${PORTSDIR}/devel/libtool15
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		sz.2:${PORTSDIR}/science/szip

CONFLICTS=	netcdf-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-jpeg="${LOCALBASE}" \
		--with-szlib="${LOCALBASE}"
USE_REINPLACE=	yes

MAN1=		hdf.1 hdfunpac.1 ncdump.1 ncgen.1
MANCOMPRESSED=	no

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		"Does not compile on !i386 and !alpha"
.endif

post-patch:
	${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
		${WRKSRC}/hdf/src/Makefile.in ${WRKSRC}/mfhdf/libsrc/Makefile.in

test: build
	cd ${WRKSRC}/hdf/test && ${MAKE} check

.include <bsd.port.post.mk>
