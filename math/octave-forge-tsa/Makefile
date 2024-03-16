PORTNAME=	octave-forge-tsa
PORTVERSION=	4.6.3
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS+=	${OCTAVE_TARBALLS_DIR}/nan.tar.gz:math/octave-forge-nan

USES=		octave

ALL_TARGET=	octave

.include <bsd.port.mk>
