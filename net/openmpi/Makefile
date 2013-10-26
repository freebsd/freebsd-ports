# $FreeBSD$

NO_STAGE=	yes
# TODO:
#  - etc/*.sample support

PORTNAME=	openmpi
DISTVERSION=	1.6.5
PORTREVISION=	1
CATEGORIES=	net parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.6/downloads/

MAINTAINER=	danilogondolfo@gmail.com
COMMENT=	High Performance Message Passing Library

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libhwloc.so:${PORTSDIR}/devel/hwloc \
		libltdl.so:${PORTSDIR}/devel/libltdl

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USES=		gmake pkgconfig

MPIBASE?=	mpi
MPIDIR?=	${MPIBASE}/${UNIQUENAME}

PLIST_SUB+=	MPIBASE=${MPIBASE}
PLIST_SUB+=	MPIDIR=${MPIDIR}

CONFIGURE_ARGS+=	--prefix=${PREFIX}/${MPIDIR} \
			--mandir=${PREFIX}/${MPIDIR}/man \
			--program-prefix= \
			--with-hwloc=${LOCALBASE} \
			--with-libltdl=${LOCALBASE}

USE_LDCONFIG=	${PREFIX}/${MPIDIR}/lib \
		${PREFIX}/${MPIDIR}/lib/openmpi

MANPREFIX=	${PREFIX}/${MPIDIR}
.include "${.CURDIR}/Makefile.man"

OPTIONS_DEFINE=	IPV6 TORQUE
TORQUE_DESC=	Enable Torque support
OPTIONS_DEFAULT=	IPV6

IPV6_CONFIGURE_ENABLE=	ipv6
TORQUE_CONFIGURE_ON=	--with-tm=${LOCALBASE}
TORQUE_CONFIGURE_OFF=	--without-tm

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTORQUE}
LIB_DEPENDS+=	libtorque.so:${PORTSDIR}/sysutils/torque
PLIST_FILES+=	${MPIDIR}/lib/openmpi/mca_plm_tm.so \
		${MPIDIR}/lib/openmpi/mca_plm_tm.la \
		${MPIDIR}/lib/openmpi/mca_ras_tm.la \
		${MPIDIR}/lib/openmpi/mca_ras_tm.so \
		${MPIDIR}/lib/openmpi/mca_ess_tm.so \
		${MPIDIR}/lib/openmpi/mca_ess_tm.la \
		${MPIDIR}/share/openmpi/help-plm-tm.txt \
		${MPIDIR}/share/openmpi/help-ras-tm.txt
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

USE_FORTRAN=	yes

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
	    ${SED} -e 's|${PREFIX}/${MPIDIR}|%%MPIDIR%%|' \
	        -e 's|${CONFIGURE_TARGET}|%%CONFIGURE_TARGET%%|' | \
	    ${SORT} >> ${PLIST}
	${FIND} ${PREFIX}/${MPIDIR} -name man -prune -o -type l -print | \
	    ${SED} -e 's|${PREFIX}/${MPIDIR}|%%MPIDIR%%|' \
	        -e 's|${CONFIGURE_TARGET}|%%CONFIGURE_TARGET%%|' | \
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
	@echo "MLINKS+=mpic++.1 mpiCC.1" >> ${.CURDIR}/Makefile.man
	@echo "MLINKS+=ortec++.1 orteCC.1" >> ${.CURDIR}/Makefile.man
	${FIND} ${PREFIX}/${MPIDIR}/man -type f | \
	    ${SED} -e 's|.*man\([0-9LN]\)/\(.*\)|MAN\1+=\2|' -e 's/\.gz$$//' | \
	    ${SORT} >> ${.CURDIR}/Makefile.man

.include <bsd.port.mk>
