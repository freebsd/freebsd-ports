PORTNAME=	octave-forge-secs2d
PORTVERSION=	0.0.8
PORTREVISION=	31
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Old%20Monolithic%20Releases/R2009-05-08
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		octave

GNU_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/${OCTAVE_SRC}

post-patch:
	${REINPLACE_CMD} -E 's/Octave_map/octave_map/g' ${WRKSRC}/src/*.cc

.include <bsd.port.mk>
