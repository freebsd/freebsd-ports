PORTNAME=	octave-forge-plot
PORTVERSION=	1.1.0
PORTREVISION=	25
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

BROKEN=		does not install with octave version >= 9.1.0

USES=		octave

OCTAVE_SRC=		${OCTAVE_PKGNAME}

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
