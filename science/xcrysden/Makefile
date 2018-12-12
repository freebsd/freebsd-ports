# $FreeBSD$

PORTNAME=	xcrysden
DISTVERSION=	1.5.60
PORTREVISION=	6
CATEGORIES=	science
MASTER_SITES=	http://www.xcrysden.org/download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystalline and molecular structure visualisation program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3
RUN_DEPENDS=	bwidget>0:x11-toolkits/bwidget \
		babel:science/openbabel \
		convert:graphics/ImageMagick6 \
		ppmtompeg:graphics/netpbm \
		xwd:x11/xwd

USES=		fortran gl gmake localbase:ldflags tcl tk
USE_GL=		gl glu
USE_XORG=	x11 xmu

BINARY_ALIAS=	make=gmake gcc=cc gfortran=gfortran${GCC_DEFAULT}

post-patch:
	@${CP} ${FILESDIR}/Make.sys ${WRKSRC}
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/Make.sys
	@${RM} -r ${WRKSRC}/external/src

post-install:
	@cd ${STAGEDIR}${PREFIX}/lib/${PORTNAME} && ${STRIP_CMD} xcrys xctclsh xsf2xsf
	@${REINPLACE_CMD} -i '' -e 's|^\.|export LD_PRELOAD=/usr/local/lib/gcc${GCC_DEFAULT}/libgcc_s.so; .|' \
		${STAGEDIR}${PREFIX}/bin/xcrysden

.include <bsd.port.mk>
