# Ports collection makefile for:	openmpi
# Date created:				August 22, 2005
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

# TODO:
#  - etc/*.sample support

PORTNAME=	openmpi
DISTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.1/downloads/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A High Performance Message Passing Library

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${UNIQUENAME}

PLIST_SUB+=	MPIBASE=${MPIBASE}
PLIST_SUB+=	MPIDIR=${MPIDIR}

SUB_FILES+=	pkg-message
SUB_LIST+=	MPIDIR=${MPIDIR}

PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${MPIDIR} ${CONFIGURE_TARGET}

USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib/openmpi

MAN1=		mpiexec.1 mpirun.1 orterun.1
MANPREFIX=	${TARGETDIR}/${MPIDIR}

.include <bsd.port.pre.mk>

WANT_FORTRAN=yes #dummy but future use
BUILD_DEPENDS+= gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
CONFIGURE_ENV+=	F77=${F77} FC=${FC}
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if exists(${LOCALBASE}/lib/libtorque.so)
WITH_TORQUE=	yes
.endif

.if defined(WITH_TORQUE)
LIB_DEPENDS+=	torque.0:${PORTSDIR}/sysutils/torque
CONFIGURE_ARGS+=	--with-tm=${LOCALBASE}
PLIST_SUB+=	TORQUE=""
.else
PLIST_SUB+=	TORQUE="@comment "
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

#######################################################################
# The following targets are for the port maintainer.  Use at your own #
# risk, no user-serviceable parts inside.                             #
#######################################################################
build-plist: Makefile
	${RM} -f pkg-plist
	${FIND} ${PREFIX}/${MPIDIR}/* -type f | \
	    ${SED} -e 's|${PREFIX}/${MPIDIR}|%%MPIDIR%%|' | \
	    ${SORT} >> pkg-plist
	${FIND} ${PREFIX}/${MPIDIR}/* -type l | \
	    ${SED} -e 's|${PREFIX}/${MPIDIR}|%%MPIDIR%%|' | \
	    ${SORT} >> pkg-plist
	${FIND} ${PREFIX}/${MPIDIR}/* -type d | \
	    ${SED} -e 's|${PREFIX}/${MPIDIR}|@dirrm %%MPIDIR%%|' | \
	    ${SORT} -r >> pkg-plist
	${ECHO} "@dirrmtry %%MPIDIR%%" \
	    >> pkg-plist
	${ECHO} "@dirrmtry %D/%%MPIBASE%%" \
	    >> pkg-plist

.include <bsd.port.post.mk>
