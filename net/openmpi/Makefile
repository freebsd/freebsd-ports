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
DISTVERSION=	1.0.2
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.0/downloads/

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OSVERSION} < 503000
.if !exists(/usr/include/stdint.h)
BROKEN=         requires stdint.h
.else
IGNORE=         is not supported for FreeBSD < 5.3
.endif
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
