PORTNAME=	octave-forge-dicom
PORTVERSION=	0.6.0
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BUILD_DEPENDS+=	cmake:devel/cmake-core

LIB_DEPENDS+=	libgdcmCommon.so:devel/gdcm

USES=		octave

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
