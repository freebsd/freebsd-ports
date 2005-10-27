# Ports collection makefile for:	openmpi
# Date created:				August 22, 2005
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

# TODO:
#  - F90 support
#  - etc/*.sample support

PORTNAME=	openmpi
DISTVERSION=	1.0rc4
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/v${DISTVERSION:C/rc[0-9]*//}/downloads/

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A High Performance Message Passing Library

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
# Can't use until does not imply GNU_CONFIGURE or there's a sane way
# to change the prefix for configure.
#USE_LIBTOOL_VER=15

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${UNIQUENAME}

PLIST_SUB+=	MPIBASE=${MPIBASE}
PLIST_SUB+=	MPIDIR=${MPIDIR}

SUB_FILES+=	pkg-message
SUB_LIST+=	MPIDIR=${MPIDIR}

PKGMESSAGE=	${WRKDIR}/pkg-message

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${MPIDIR} ${CONFIGURE_TARGET}

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
	${ECHO} "@unexec rmdir %D/%%MPIDIR%% 2>/dev/null || true" \
	    >> pkg-plist
	${ECHO} "@unexec rmdir %D/%%MPIBASE%% 2>/dev/null || true" \
	    >> pkg-plist

.include <bsd.port.mk>
