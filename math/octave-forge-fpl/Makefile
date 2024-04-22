PORTNAME=	octave-forge-fpl
PORTVERSION=	1.3.5
PORTREVISION=	19
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

RUN_DEPENDS=	dx:graphics/opendx

USES=		octave

NO_ARCH=	yes
NO_BUILD=	yes

OCTAVE_SRC=		${OCTAVE_PKGNAME}

.include <bsd.port.mk>
