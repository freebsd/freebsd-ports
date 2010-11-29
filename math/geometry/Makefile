# New ports collection makefile for: geometry
# Date created:	2010-11-22
# Whom: Rene Ladan <rene@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	geometry
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://rene-ladan.nl/pub/distfiles/ros/
DISTFILES=	geometry-${PORTVERSION}.tar.bz2 bullet-2.76-patched2.tar.gz \
		eigen2-2.0.15.tar.bz2 kdl-31715.tar.gz
DIST_SUBDIR=	ros
EXTRACT_ONLY=	geometry-${PORTVERSION}.tar.bz2

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Robot Operating System - geometric and math libraries

#LICENSE_COMB=	multi
#LICENSE=	BSD LGPL* Zlib # which LGPL and Zlib not defined yet

WRKSRC=		${WRKDIR}/${PORTNAME}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs \
		chrpath:${PORTSDIR}/devel/chrpath \
		${PYTHON_SITELIBDIR}/sipconfig.py:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/common_msgs
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/common_msgs:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

post-extract:
# move 3rd-party distfiles into place
	${MKDIR} ${WRKSRC}/bullet/build
	${CP} ${_DISTDIR}/bullet-2.76-patched2.tar.gz ${WRKSRC}/bullet/build
	${MKDIR} ${WRKSRC}/eigen/build
	${CP} ${_DISTDIR}/eigen2-2.0.15.tar.bz2 ${WRKSRC}/eigen/build
	${MKDIR} ${WRKSRC}/kdl/build
	${CP} ${_DISTDIR}/kdl-31715.tar.gz ${WRKSRC}/kdl/build

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${PORTNAME}
# update .pc file
	${REINPLACE_CMD} -E -e "s|${WRKSRC}|${PREFIX}/ros/stacks/${PORTNAME}|" \
	    ${WRKSRC}/kdl/lib/pkgconfig/orocos-kdl.pc
	${INSTALL_DATA} ${WRKSRC}/kdl/lib/pkgconfig/orocos-kdl.pc ${PREFIX}/libdata/pkgconfig
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in angles bullet eigen eigen_conversions kdl tf tf_conversions
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -type f -or -name \*.pc -type f | ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${PORTNAME})
.endfor
.for f in CMakeLists.txt Makefile stack.xml rosdep.yaml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${PORTNAME}
.endfor

# strip ELF programs and make them executable
.for f in tf/bin/change_notifier tf/bin/static_transform_publisher \
    tf/bin/tf_echo tf/bin/tf_monitor tf/test/btTest tf/test/testBroadcaster \
    tf/test/testListener tf/test/transform_listener_unittest
	${STRIP_CMD} ${PREFIX}/ros/stacks/${PORTNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${PORTNAME}/${f}
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${PORTNAME}/${f}
.endfor
# strip and symlink ELF libaries
.for f in bullet/lib/libBulletCollision.so.2.76 \
    bullet/lib/libBulletDynamics.so.2.76 bullet/lib/libBulletSoftBody.so.2.76 \
    bullet/lib/libLinearMath.so.2.76 \
    eigen_conversions/lib/libeigen_conversions.so \
    kdl/lib/liborocos-kdl.so.1.0.99 kdl/lib/PyKDL.so tf/lib/_tf.so \
    tf/lib/libtf.so tf_conversions/lib/libtf_conversions.so
	${STRIP_CMD} ${PREFIX}/ros/stacks/${PORTNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${PORTNAME}/${f}
	${LN} -s ${PREFIX}/ros/stacks/${PORTNAME}/${f} ${PREFIX}/lib
.endfor
# symbolic links
.for f in bullet/lib/libBulletCollision.so bullet/lib/libBulletDynamics.so \
    bullet/lib/libBulletSoftBody.so bullet/lib/libLinearMath.so \
    kdl/lib/liborocos-kdl.so kdl/lib/liborocos-kdl.so.1.0
	${LN} -s ${PREFIX}/ros/stacks/${PORTNAME}/${f} ${PREFIX}/lib
.endfor
# make scripts executable
.for f in tf/scripts/python_benchmark.py tf/scripts/reset_time.py \
    tf/scripts/tf_remap tf/scripts/view_frames \
    tf/test/test_datatype_conversion.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${PORTNAME}/${f}
.endfor

.include <bsd.port.mk>
