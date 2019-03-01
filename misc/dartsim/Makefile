# $FreeBSD$

PORTNAME=	dartsim
DISTVERSIONPREFIX=	v
DISTVERSION=	6.7.3
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Animation and Robotics Toolkit

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libBulletDynamics.so:devel/bullet \
		libboost_system.so:devel/boost-libs \
		libccd.so:math/libccd \
		libconsole_bridge.so:misc/console-bridge \
		libfcl.so:math/fcl \
		libflann_cpp.so:math/flann \
		libipopt.so:math/ipopt \
		liboctomap.so:math/octomap \
		libode.so:devel/ode \
		libosg.so:graphics/osg \
		libnlopt.so:math/nlopt \
		libtinyxml2.so:textproc/tinyxml2 \
		liburdfdom_world.so:misc/urdfdom

USES=		cmake compiler:c++11-lang eigen:3 gl localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_PROJECT=	dart
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

DATADIR=	share/dart

.include <bsd.port.mk>
