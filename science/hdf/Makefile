# New ports collection makefile for:	HDF_lib
# Date created:		17 November 1996
# Whom:			mi
#
# $FreeBSD$
#

PORTNAME=	hdf
PORTVERSION=	4.2r1
PORTREVISION=	1
CATEGORIES=	science archivers graphics
MASTER_SITES=	ftp://ftp.ncsa.uiuc.edu/HDF/HDF/HDF${PORTVERSION}/src/:src \
		ftp://ftp.ncsa.uiuc.edu/HDF/HDF/Documentation/HDF4.2r0/:doc \
		http://hdf.ncsa.uiuc.edu/doc_resource/SZIP/:doc_szip
DISTNAME=	HDF${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${SZIP_DOCFILE}:doc_szip \
		${DOCFILES:C/$/:doc/g}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		sz.2:${PORTSDIR}/science/szip

CONFLICTS=	netcdf-*

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS+=--with-jpeg="${LOCALBASE}" \
		--with-szlib="${LOCALBASE}"
DOCFILES=	HDF41r5_SpecDG.pdf \
		HDF42r0_RefMan.pdf \
		HDF42r0_UserGd.pdf
SZIP_DOCFILE=	SZIP_HDF4_2r1.pdf

MAN1=		hdf.1 hdfunpac.1 ncdump.1 ncgen.1
MANCOMPRESSED=	no

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha" && ${ARCH} != "amd64"
BROKEN=		"Does not compile on !i386, !amd64 and !alpha"
.endif

post-patch:
	${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" \
		${WRKSRC}/hdf/src/Makefile.in ${WRKSRC}/mfhdf/libsrc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES} ${SZIP_DOCFILE}
	@${INSTALL_DATA} ${DISTDIR}/${file} ${DOCSDIR}
.endfor
	@cd ${WRKSRC}/release_notes && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

test: build
	cd ${WRKSRC}/hdf/test && ${MAKE} check

.include <bsd.port.post.mk>
