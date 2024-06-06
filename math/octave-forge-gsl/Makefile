PORTNAME=	octave-forge-gsl
PORTVERSION=	2.1.1
PORTREVISION=	16
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Individual%20Package%20Releases
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS=	libgsl.so:math/gsl

USES=		octave

LDFLAGS+=	-L${PREFIX}/lib

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
