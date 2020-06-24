# $FreeBSD$

PORTNAME=	votca
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CSG and XTP: libraries for atomistic simulations

LICENSE=	APACHE20

BROKEN_i386=	undefined reference to `__atomic_load'

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libfftw3.so:math/fftw3 \
		libhdf5.so:science/hdf5 \
		libsz.so:science/szip \
		libxc.so:science/libxc

USES=		cmake compiler:c++14-lang eigen:3 perl5 pkgconfig python:run \
		shebangfix
SHEBANG_GLOB=	*.sh *.pl *.py
SHEBANG_FILES=	csg/scripts/csg_call.in csg/scripts/csg_inverse.in tools/scripts/votca_compare.in \
		xtp/scripts/xtp_update_mapfile.in xtp/scripts/xtp_basisset.in xtp/scripts/xtp_makeauxbasis.in xtp/share/benchmark/xtp_benchmark.in \
		csg-manual/scripts/tex2eps
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_TUPLE=	\
		votca:tools:232b1300228f0ead9d1b28059b216b0dc3628e13:votca_tools/tools \
		votca:csg:8fc39bd2afdfc28da1d453e00df7ca69a6b29778:votca_csg/csg \
		votca:csgapps:cc763698019343dce934bcfe7442cfad7e2b50e8:votca_csgapps/csgapps \
		votca:xtp:760fc1f32fca869c1ca2760c03f26e554ca1e1a6:votca_xtp/xtp \
		votca:csg-tutorials:8b4ca1d8c932d747aad2aaa611db906745117f8b:votca_csg_tutorials/csg-tutorials \
		votca:csg-manual:5bd9339bc5a986071dbdacaf69698c1559b22972:votca_csg_manual/csg-manual \
		votca:xtp-tutorials:8c8255b0a830ed9d8a61855554afab430a667a8e:votca_xtp_tutorials/xtp-tutorials \

CMAKE_ON=	BUILD_XTP

OPTIONS_DEFINE=		APPS DOCS
OPTIONS_DEFAULT=	APPS
OPTIONS_SUB=		yes

APPS_DESC=		Build applications
APPS_CMAKE_BOOL=	BUILD_CSGAPPS

DOCS_CMAKE_BOOL=	BUILD_CSG_MANUAL
DOCS_BUILD_DEPENDS=	txt2tags:textproc/txt2tags
DOCS_USE=		TEX=latex,dvipsk:build

.include <bsd.port.mk>
