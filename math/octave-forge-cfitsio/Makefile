PORTNAME=	octave-forge-cfitsio
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=octave-cfitsio/v${PORTVERSION}
DISTNAME=	octave-${OCTAVE_PKGNAME}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libcfitsio.so:astro/cfitsio

USES=		autoreconf octave

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
