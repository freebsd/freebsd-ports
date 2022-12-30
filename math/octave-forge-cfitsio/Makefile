PORTNAME=	octave-forge-cfitsio
PORTVERSION=	0.0.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=octave-cfitsio/v${PORTVERSION}
DISTNAME=	octave-${OCTAVE_PKGNAME}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

LIB_DEPENDS+=	libcfitsio.so:astro/cfitsio

USES=		autoreconf

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.

OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

GNU_CONFIGURE=	yes

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
