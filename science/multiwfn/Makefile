PORTNAME=	multiwfn
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8
CATEGORIES=	science
MASTER_SITES=	http://sobereva.com/multiwfn/misc/:main \
		https://www.dislin.de/downloads/unix/:dislin
DISTFILES=	Multiwfn_${DISTVERSION}_dev_src_Linux.zip:main \
		dislin-11.5.fbsd.64.tar.gz:dislin # (!!!) dislin is a closed-source library distributed as binary, source code is sold for $$

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multifunctional wavefunction analysis for quantum chemistry
WWW=		http://sobereva.com/multiwfn/index.html

LICENSE=	GPLv2

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	dislin is closed source only available for amd64

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas
RUN_DEPENDS=	bash:shells/bash

USES=		gl gmake fortran motif xorg
USE_GL=		gl
USE_XORG=	x11 xt

#SHEBANG_GLOB=	*.sh
#SHEBANG_FILES=	init/Multiwfn.01

#USE_GITHUB=	yes
#GH_ACCOUNT=	stecue
#GH_PROJECT=	gMultiwfn

WRKSRC=		${WRKDIR}/Multiwfn_${DISTVERSION}_dev_src_Linux

FCFLAGS+=	-ffree-line-length-none
LDFLAGS+=	-lblas -llapack -lc

ALL_TARGET=	default

BINARY_ALIAS=	ifort=gfortran12 \
		gcc=${CC}

PLIST_FILES=	bin/Multiwfn \
		bin/Multiwfn_noGUI

post-patch: # replace the dislin.a library with the FreeBSD version
	@${CP} ${WRKDIR}/dislin-11.5/fbsd_64/lib/dislin_d-11.5.a ${WRKSRC}/dislin_d-11.0.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Multiwfn ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Multiwfn_noGUI ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
