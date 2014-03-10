# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ros-geometry
PORTVERSION=	1.4.2
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	https://code.ros.org/svn/release/download/stacks/${STACKNAME}/${STACKNAME}-${PORTVERSION}/:rel \
		http://pr.willowgarage.com/downloads/:pr \
		https://code.ros.org/svn/release/download/thirdparty/eigen/:tp
DISTFILES=	geometry-${PORTVERSION}.tar.bz2:rel \
		bullet-2.76-patched2.tar.gz:pr \
		eigen-3.0prebeta3.tar.bz2:tp kdl-32171.tar.gz:pr
DIST_SUBDIR=	ros
EXTRACT_ONLY=	geometry-${PORTVERSION}.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robot Operating System - geometric and math libraries

#LICENSE_COMB=	multi
#LICENSE=	BSD LGPL* Zlib # which LGPL and Zlib not defined yet

DEPRECATED=	Depends on expiring devel/ros_comm
EXPIRATION_DATE=	2014-03-28
STACKNAME=	${PORTNAME:S/ros-//}
WRKSRC=		${WRKDIR}/${STACKNAME}-${PORTVERSION}

BUILD_DEPENDS=	rosmake:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/ros-common_msgs \
		chrpath:${PORTSDIR}/devel/chrpath \
		cppunit-config:${PORTSDIR}/devel/cppunit \
		${PYTHON_SITELIBDIR}/sipconfig.py:${PORTSDIR}/devel/py-sip
RUN_DEPENDS=	roscore:${PORTSDIR}/devel/ros \
		${LOCALBASE}/ros/stacks/ros_comm/stack.xml:${PORTSDIR}/devel/ros_comm \
		${LOCALBASE}/ros/stacks/common_msgs/stack.xml:${PORTSDIR}/devel/ros-common_msgs
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GL=		glut

# rosmake does its own threading
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPATH=${LOCALBASE}/include \
		LIBRARY_PATH=${LOCALBASE}/lib \
		MAKE=${LOCALBASE}/bin/gmake \
		ROS_ROOT=${LOCALBASE}/ros/ros \
		ROS_PACKAGE_PATH=${LOCALBASE}/ros/stacks/common_msgs:${LOCALBASE}/ros/stacks/ros_comm:${WRKSRC} \
		PYTHONPATH=${LOCALBASE}/ros/ros/core/roslib/src

MAKE_ARGS=	-i --no-rosdep --status-rate=0 --disable-logging

NO_STAGE=	yes
post-extract:
# move 3rd-party distfiles into place
	${MKDIR} ${WRKSRC}/bullet/build
	${CP} ${_DISTDIR}/bullet-2.76-patched2.tar.gz ${WRKSRC}/bullet/build
	${MKDIR} ${WRKSRC}/eigen/build
	${CP} ${_DISTDIR}/eigen-3.0prebeta3.tar.bz2 ${WRKSRC}/eigen/build
	${MKDIR} ${WRKSRC}/kdl/build
	${CP} ${_DISTDIR}/kdl-32171.tar.gz ${WRKSRC}/kdl/build
	# already extract and mark as such because we have to patch it (clang)
	# fixed in bullet 2.77
	(cd ${WRKSRC}/bullet/build ; \
	 ${TAR} -xf bullet-2.76-patched2.tar.gz ; \
	 ${TOUCH} bullet_svn/unpacked)

do-build:
	(cd ${WRKSRC} ; ${MAKE_ENV} ${LOCALBASE}/bin/rosmake ${MAKE_ARGS})

do-install:
	${MKDIR} ${PREFIX}/ros/stacks/${STACKNAME}
# update .pc file
	${REINPLACE_CMD} -E -e "s|${WRKSRC}|${PREFIX}/ros/stacks/${STACKNAME}|" \
	    ${WRKSRC}/kdl/lib/pkgconfig/orocos-kdl.pc
	${INSTALL_DATA} ${WRKSRC}/kdl/lib/pkgconfig/orocos-kdl.pc ${PREFIX}/libdata/pkgconfig
# delete files explicitly because negation in find (for COPYTREE_SHARE) is bogus
.for d in angles bullet eigen eigen_conversions kdl tf tf_conversions
	${FIND} ${WRKSRC}/${d} -name build -type d -or -name \*.bak -type f \
	    -or -name .svnignore -type f -or -name .cvsignore -type f \
	    -or -name \*.orig -type f -or -name \*.pc -type f \
	    -or -name \*.md5sum -type f -or -name installed -type f \
	    -or -name wiped -type f| ${XARGS} ${RM} -rf
	(cd ${WRKSRC} ; ${COPYTREE_SHARE} ${d} ${PREFIX}/ros/stacks/${STACKNAME})
.endfor
.for f in CMakeLists.txt Makefile stack.xml rosdep.yaml
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/ros/stacks/${STACKNAME}
.endfor

# strip ELF programs and make them executable
.for f in tf/bin/change_notifier tf/bin/static_transform_publisher \
    tf/bin/tf_echo tf/bin/tf_monitor tf/test/btTest tf/test/testBroadcaster
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor
# strip and symlink ELF libaries
.for f in bullet/lib/libBulletCollision.so.2.76 \
    bullet/lib/libBulletDynamics.so.2.76 bullet/lib/libBulletSoftBody.so.2.76 \
    bullet/lib/libLinearMath.so.2.76 \
    eigen_conversions/lib/libeigen_conversions.so \
    kdl/lib/liborocos-kdl.so.1.0.99 kdl/lib/PyKDL.so tf/lib/_tf.so \
    tf/lib/libtf.so tf_conversions/lib/libtf_conversions.so
	${STRIP_CMD} ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LOCALBASE}/bin/chrpath -d ${PREFIX}/ros/stacks/${STACKNAME}/${f}
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor
# symbolic links
.for f in bullet/lib/libBulletCollision.so bullet/lib/libBulletDynamics.so \
    bullet/lib/libBulletSoftBody.so bullet/lib/libLinearMath.so \
    kdl/lib/liborocos-kdl.so kdl/lib/liborocos-kdl.so.1.0
	${LN} -s ${PREFIX}/ros/stacks/${STACKNAME}/${f} ${PREFIX}/lib
.endfor
# make scripts executable
.for f in eigen/scripts/e2_to_eigen2support.sh \
    eigen/scripts/recursive_eigen2_port.sh \
    tf/scripts/python_benchmark.py \
    tf/scripts/tf_remap tf/scripts/view_frames \
    tf/test/test_datatype_conversion.py
	${CHMOD} 0555 ${PREFIX}/ros/stacks/${STACKNAME}/${f}
.endfor

post-install:
	${PYTHON_CMD} -O -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/
	${PYTHON_CMD} -mcompileall ${PREFIX}/ros/stacks/${STACKNAME}/

.include <bsd.port.mk>
