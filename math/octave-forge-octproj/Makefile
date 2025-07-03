PORTNAME=	octave-forge-octproj
PORTVERSION=	3.1.0
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/jgpallero/octproj/downloads/
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libproj.so:graphics/proj

USES=		octave

.include <bsd.port.mk>
