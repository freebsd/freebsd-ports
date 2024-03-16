PORTNAME=	octave-forge-rtree
DISTVERSION=	0.8.0
PORTREVISION=	1
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
GL_COMMIT=	6456b2ebb38528ea6861019b4b85699796ba91fa

CFLAGS+=	-I${PREFIX}/include -L${PREFIX}/lib

OCTAVE_SRC=	${GL_PROJECT}-${GL_COMMIT}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

post-patch:
	${REINPLACE_CMD} s/^tar/gtar/ ${WRKSRC}/src/pkg/bin/pkg-build

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
