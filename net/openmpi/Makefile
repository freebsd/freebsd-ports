# Ports collection makefile for:	openmpi
# Date created:				August 22, 2005
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

# TODO:
#  - etc/*.sample support

PORTNAME=	openmpi
DISTVERSION=	1.3.3
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.3/downloads/

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

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${MPIDIR} \
			--mandir=${PREFIX}/${MPIDIR}/man \
		 	${CONFIGURE_TARGET}

USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib \
		${PREFIX}/${MPIDIR}/lib/openmpi

MANPREFIX=	${PREFIX}/${MPIDIR}
.include "${.CURDIR}/Makefile.man"

OPTIONS=	TORQUE "Enable Torque support" off \
		SGE "Enable SGE support" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

USE_FORTRAN=	yes

.if defined(WITH_SGE)
SGE_BASE?=	sge
SGE_ROOT=	${LOCALBASE}/${SGE_BASE}
SGE_ARCH=	fbsd-${ARCH}
RUN_DEPENDS+=	${SGE_ROOT}/fbsd-${ARCH}/qrsh:${PORTSDIR}/sysutils/sge62
CONFIGURE_ARGS+=	--with-sge
CONFIGURE_ENV+=	SGE_ROOT=${SGE_ROOT}
PLIST_FILES+=	${MPIDIR}/lib/openmpi/mca_ras_gridengine.la \
		${MPIDIR}/lib/openmpi/mca_ras_gridengine.so \
		${MPIDIR}/share/openmpi/help-ras-gridengine.txt
.else
CONFIGURE_ARGS+=	--without-sge
.endif

.if defined(WITH_TORQUE)
LIB_DEPENDS+=	torque.2:${PORTSDIR}/sysutils/torque
CONFIGURE_ARGS+=	--with-tm=${LOCALBASE}
PLIST_FILES+=	${MPIDIR}/lib/openmpi/mca_plm_tm.so \
		${MPIDIR}/lib/openmpi/mca_plm_tm.la \
		${MPIDIR}/lib/openmpi/mca_ras_tm.la \
		${MPIDIR}/lib/openmpi/mca_ras_tm.so \
		${MPIDIR}/share/openmpi/help-plm-tm.txt \
		${MPIDIR}/share/openmpi/help-ras-tm.txt
.else
CONFIGURE_ARGS+=	--without-tm
.endif

#######################################################################
# The following targets are for the port maintainer.  Use at your own #
# risk, no user-serviceable parts inside.                             #
#                                                                     #
# XXX: we should generate MLINKS programaticaly, but it would take    #
# some effort and there's only one entry at this time.                #
#######################################################################
build-plist:
	${RM} -f ${PLIST}
	${FIND} ${PREFIX}/${MPIDIR} -name man -prune -o -type f -print | \
	    ${SED} -e 's|${PREFIX}/${MPIDIR}|%%MPIDIR%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${PREFIX}/${MPIDIR} -name man -prune -o -type l -print | \
	    ${SED} -e 's|${PREFIX}/${MPIDIR}|%%MPIDIR%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${PREFIX}/${MPIDIR} -type d | \
	    ${EGREP} -v "${PREFIX}/${MPIDIR}$$" | \
	    ${SED} -e 's|${PREFIX}/${MPIDIR}|@dirrm %%MPIDIR%%|' | \
	    ${SORT} -r >> ${PLIST}
	${ECHO} "@dirrmtry %%MPIDIR%%" \
	    >> ${PLIST}
	${ECHO} "@dirrmtry %%MPIBASE%%" \
	    >> ${PLIST}
	@echo "# Do not edit!  Auto-generated file." > ${.CURDIR}/Makefile.man
	@echo "# See build-plist target in Makefile." >> ${.CURDIR}/Makefile.man
	@echo "#" >> ${.CURDIR}/Makefile.man
	@echo "MLINKS=mpic++.1 mpiCC.1" >> ${.CURDIR}/Makefile.man
	${FIND} ${PREFIX}/${MPIDIR}/man -type f | \
	    ${SED} -e 's|.*man\([0-9LN]\)/\(.*\)|MAN\1+=\2|' -e 's/\.gz$$//' \
	    >> ${.CURDIR}/Makefile.man

.include <bsd.port.post.mk>
