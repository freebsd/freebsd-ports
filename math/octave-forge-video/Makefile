# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-video
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

USES=		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	HOME=${WRKSRC}
CPPFLAGS+=      -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
