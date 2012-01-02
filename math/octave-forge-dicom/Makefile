# New ports collection makefile for:	octave-forge-dicom
# Date created:		26 December 2011
# Whom:			Stephen Montgomery-Smith <stephen@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	octave-forge-dicom
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LIB_DEPENDS+=	gdcmCommon:${PORTSDIR}/devel/gdcm

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${OCTAVE_PKGNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

GDCM_MAJ=	2.2
post-patch:
	${REINPLACE_CMD} s/gdcm-2.0/gdcm-${GDCM_MAJ}/ \
		${WRKSRC}/dicominfo.cpp ${WRKSRC}/dicomdict.cpp \
		${WRKSRC}/dicomread.cpp ${WRKSRC}/dicomlookup.cpp \
		${WRKSRC}/_gendicomdict.cpp ${WRKSRC}/dicomwrite.cpp

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.octave.mk"

post-build:
	${RM} -f ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.post.mk>
