# $FreeBSD$

PORTNAME=	votca
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.3
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CSG and XTP: libraries for atomistic simulations

LICENSE=	APACHE20

BROKEN_i386=	undefined reference to `__atomic_load'

BUILD_DEPENDS=	bash:shells/bash \
		lmp:science/lammps
RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libexpat.so:textproc/expat2 \
		libfftw3.so:math/fftw3 \
		libgromacs_d.so:science/gromacs \
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
		votca:csg:efaa34c7f148c85493a3d15bf8cc800918d7111f:votca_csg/csg \
		votca:csg-manual:16d27d55248fe7d2f3d78dcb2483f723ba3e38fe:votca_csg_manual/csg-manual \
		votca:csg-tutorials:6819ffd5735cd253d55beffe1be61f0d49e6dd5e:votca_csg_tutorials/csg-tutorials \
		votca:csgapps:4e40d2b92a5d33db2d750efa1dacdf1d502e7447:votca_csgapps/csgapps \
		votca:tools:377b8487df371862de793dfe38287f4ce1cbafb8:votca_tools/tools \
		votca:xtp:5879ed8d006471d37cc0b19dcbb557eac60cf898:votca_xtp/xtp \
		votca:xtp-tutorials:b4b25d570fef22b8806e2efb2fdcc844ad8acb7e:votca_xtp_tutorials/xtp-tutorials

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
