# $FreeBSD$

PORTNAME=	votca
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CSG and XTP: libraries for atomistic simulations

LICENSE=	APACHE20

RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		libsz.so:science/szip \
		libxc.so:science/libxc

USES=		cmake eigen:3 perl5 pkgconfig python:run shebangfix
SHEBANG_GLOB=	*.sh *.pl *.py
SHEBANG_FILES=	csg/scripts/csg_call.in csg/scripts/csg_inverse.in tools/scripts/votca_compare.in \
		xtp/scripts/xtp_update_mapfile.in xtp/scripts/xtp_basisset.in xtp/scripts/xtp_makeauxbasis.in xtp/share/benchmark/xtp_benchmark.in
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_TUPLE=	\
		votca:tools:c34ee0244cd2e6c8772ce239b3045294d911736d:votca_tools/tools \
		votca:csg:6bb24ff260c87d1cf1b89d91dc12901eb462d974:votca_csg/csg \
		votca:csgapps:a26503c0aaa10b024a59180d15dde9c7e11256a4:votca_csgapps/csgapps \
		votca:xtp:24260506ccb4de0e82add46ab1cd43b9e8130807:votca_xtp/xtp \
		votca:csg-tutorials:dd8df99ce7548e2ad7c819fcd8e617946d532493:votca_csg_tutorials/csg-tutorials \
		votca:csg-manual:85fbc7e8a7469db31eb3597f9c651d51a4ef5d2b:votca_csg_manual/csg-manual \
		votca:xtp-tutorials:a7a608b5752db59f6d94482ff5ace36e7faa21aa:votca_xtp_tutorials/xtp-tutorials

CMAKE_ON=	BUILD_XTP

.include <bsd.port.mk>
