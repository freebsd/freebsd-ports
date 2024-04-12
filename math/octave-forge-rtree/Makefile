PORTNAME=	octave-forge-rtree
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		octave autoreconf:build

BUILD_DEPENDS+=	gtar:archivers/gtar
LIB_DEPENDS+=	libjansson.so:devel/jansson

USE_GITLAB=	yes
GL_ACCOUNT=	jjg
GL_PROJECT=	librtree-octave

CFLAGS+=	-I${PREFIX}/include -L${PREFIX}/lib

OCTAVE_SRC=	${GL_PROJECT}-${GL_COMMIT}${DISTVERSIONPREFIX}${DISTVERSION}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

BINARY_ALIAS=	tar=gtar

do-build:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} CFLAGS="${CFLAGS}" ./configure
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} package
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} spotless
	${TAR} xvf ${WRKSRC}/src/pkg/versions/${OCTAVE_DISTNAME}.tar.gz -C ${WRKSRC}
	cd ${WRKSRC}/${OCTAVE_DISTNAME}/src && \
		${SETENV} ${CONFIGURE_ENV} CFLAGS="${CFLAGS}" ./configure && \
		${SETENV} ${MAKE_ENV} CLAGS="${CFLAGS}" ${GMAKE}

pre-install:
	${RM} ${WRKSRC}/${OCTAVE_DISTNAME}/src/Makefile ${WRKSRC}/${OCTAVE_DISTNAME}/src/configure
	cd ${WRKSRC} && ${TAR} cfz ${WRKDIR}/${OCTAVE_DISTNAME}.tar.gz ${OCTAVE_DISTNAME}

.include <bsd.port.mk>
