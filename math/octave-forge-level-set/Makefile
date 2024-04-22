PORTNAME=	octave-forge-level-set
PORTVERSION=	0.3.0
PORTREVISION=	19
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3

BROKEN=		does not build with octave version >= 9.1.0

USES=		compiler:c++0x octave

GNU_CONFIGURE=	yes

ALL_TARGET=	oct

OCTAVE_SRC=		${OCTAVE_PKGNAME}

.include <bsd.port.mk>
