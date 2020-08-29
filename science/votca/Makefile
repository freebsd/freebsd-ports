# $FreeBSD$

PORTNAME=	votca
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
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
		votca:tools:0713d822e102b91658acedfc8cf53820acf003ca:votca_tools/tools \
		votca:csg:500e70ec26bdadc7ef7cb75af04e7832360a4e1c:votca_csg/csg \
		votca:csgapps:d1dcc87d475a8139d83da9875802c7a76da6361b:votca_csgapps/csgapps \
		votca:xtp:44fd19f597c03b4fa1fe182ef7402279323a6345:votca_xtp/xtp \
		votca:csg-tutorials:6930697a93d66cadbc14c894d43578fb8e215681:votca_csg_tutorials/csg-tutorials \
		votca:csg-manual:7ecc26766963346fe628716b9ec5376d93d1e1ff:votca_csg_manual/csg-manual \
		votca:xtp-tutorials:86499725fffc7c356fef811f7860f996d56a5548:votca_xtp_tutorials/xtp-tutorials

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
