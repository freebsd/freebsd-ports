PORTNAME=	octave-forge-rtree
DISTVERSION=	0.8.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${EXTRACT_DIR}/COPYING

USES=		octave

BUILD_DEPENDS+=	gtar:archivers/gtar
LIB_DEPENDS+=	libjansson.so:devel/jansson

USE_GITLAB=	yes
GL_ACCOUNT=	jjg
GL_PROJECT=	librtree-octave
GL_COMMIT=	6456b2ebb38528ea6861019b4b85699796ba91fa

CFLAGS+=	-I${PREFIX}/include -L${PREFIX}/lib

OCTAVE_SRC=	${OCTAVE_PKGNAME}-${DISTVERSION}
EXTRACT_DIR=	${WRKDIR}/${GL_PROJECT}-${GL_COMMIT}

post-patch:
	${REINPLACE_CMD} s/^tar/gtar/ ${EXTRACT_DIR}/src/pkg/bin/pkg-build
	cd ${EXTRACT_DIR} && ${SETENV} ${CONFIGURE_ENV} CFLAGS="${CFLAGS}" ./configure
	cd ${EXTRACT_DIR} && ${SETENV} ${MAKE_ENV} ${GMAKE} package
	cd ${EXTRACT_DIR} && ${SETENV} ${MAKE_ENV} ${GMAKE} spotless
	${TAR} xvf ${EXTRACT_DIR}/src/pkg/versions/${OCTAVE_SRC}.tar.gz -C ${WRKDIR}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
