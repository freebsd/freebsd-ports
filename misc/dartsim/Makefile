# $FreeBSD$

PORTNAME=	dartsim
DISTVERSIONPREFIX=	v
DISTVERSION=	6.8.5
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Animation and Robotics Toolkit

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	clang failure: https://bugs.llvm.org/show_bug.cgi?id=41757

BUILD_DEPENDS=	pagmo2>0:science/pagmo2
LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libBulletDynamics.so:devel/bullet \
		libboost_system.so:devel/boost-libs \
		libccd.so:math/libccd \
		libconsole_bridge.so:misc/console-bridge \
		libfcl.so:math/fcl \
		libflann_cpp.so:math/flann \
		libipopt.so:math/ipopt \
		liblz4.so:archivers/liblz4 \
		liboctomap.so:math/octomap \
		libode.so:devel/ode \
		libosg.so:graphics/osg \
		libnlopt.so:math/nlopt \
		libtinyxml2.so:textproc/tinyxml2 \
		liburdfdom_world.so:misc/urdfdom

USES=		cmake compiler:c++11-lang eigen:3 gl localbase:ldflags \
		pkgconfig xorg
USE_GITHUB=	yes
GH_PROJECT=	dart
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

DATADIR=	share/dart

.include <bsd.port.mk>
