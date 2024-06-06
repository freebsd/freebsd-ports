PORTNAME=	octave-forge-bioinfo
PORTVERSION=	0.1.2
PORTREVISION=	31
CATEGORIES=	math
MASTER_SITES=	SF/octave/Octave%20Forge%20Packages/Old%20Monolithic%20Releases/R2009-05-08
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

#BROKEN=		does not install with octave version >= 9.1.0

USES=		octave

GNU_CONFIGURE=	yes

WRKSRC=        ${WRKDIR}/${OCTAVE_SRC}

.include <bsd.port.mk>
