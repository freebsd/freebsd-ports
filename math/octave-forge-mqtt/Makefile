PORTNAME=	octave-forge-mqtt
PORTVERSION=	0.0.3
CATEGORIES=	math
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=octave-mqtt/v${PORTVERSION}
DISTNAME=	octave-${OCTAVE_PKGNAME}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

LIB_DEPENDS+=	libpaho-mqtt3a.so:net/libpaho-mqtt3

USES=		autoreconf

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.

OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
