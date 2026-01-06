PORTNAME=	octave-forge-dicom
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.7.1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libgdcmCommon.so:devel/gdcm

USES=		octave autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	gnu-octave
GH_PROJECT=	octave-dicom

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
