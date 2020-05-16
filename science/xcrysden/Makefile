# $FreeBSD$

PORTNAME=	xcrysden
DISTVERSION=	1.6.2
CATEGORIES=	science
MASTER_SITES=	http://www.xcrysden.org/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystalline and molecular structure visualisation program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libgl2ps.so:print/gl2ps \
		libTogl2.0.so:graphics/togl
RUN_DEPENDS=	bwidget>0:x11-toolkits/bwidget \
		obabel:science/openbabel \
		convert:graphics/ImageMagick6 \
		ppmtompeg:graphics/netpbm \
		xwd:x11/xwd

USES=		fortran gl gmake localbase:ldflags tcl tk xorg
USE_GL=		gl glu
USE_XORG=	x11 xmu

MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX}

BINARY_ALIAS=	make=gmake gcc=cc gfortran=gfortran${GCC_DEFAULT}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-patch:
	@${CP} ${FILESDIR}/Make.sys ${WRKSRC}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Make.sys
	@${RM} -r ${WRKSRC}/external/src

post-install:
	# stagedir shouldn't be in executables
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' ${STAGEDIR}${PREFIX}/bin/*
	# remove bad symlinks
	@${RM} \
		${STAGEDIR}${PREFIX}/share/doc/xcrysden/examples/examples \
		${STAGEDIR}${PREFIX}/share/xcrysden/examples
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/xcrysden/*
	# move examples from the docs dir
	@${MV} ${STAGEDIR}${DOCSDIR}/examples ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
