# New ports collection makefile for:	ncs
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ncs
DISTVERSION=	1.3.f
CATEGORIES=	science parallel
MASTER_SITES=	http://www.edf.fr/html/RetD/livraison_saturne_${REL_DATE}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Kernel

LIB_DEPENDS=	fvm.0:${PORTSDIR}/science/fvm
RUN_DEPENDS=	xmgrace:${PORTSDIR}/math/grace	\
		ecs:${PORTSDIR}/science/ecs

REL_DATE=	070305

USE_GNOME=	libxml2
USE_PYTHON=	yes
BUILD_WRKSRC=	${WRKSRC}/bin
MAKE_ENV=	NOM_ARCH=${OPSYS} CS_HOME=${WRKSRC} CS_MPI_PATH=${MPI_HOME}/bin	\
		PTHREAD_LIBS=${PTHREAD_LIBS} TERM=${TERM}			\
		MPI_HOME=${MPI_HOME} MPI_LIBS="${MPI_LIBS}"

WANT_FORTRAN=	yes	#dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
RUN_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42
FORTRANLIBDIR=	`${DIRNAME} \\`gfortran42 -print-libgcc-file-name\\``
FORTRANLIBDIR2=	`${DIRNAME} \\`gfortran42 -print-libgcc-file-name\\``/../../../
MAKE_ENV+=	FC="${FC}" F77="${F77}" FFLAGS="${FFLAGS}"

.if defined(PACKAGE_BUILDING)
TERM=		vt100	# Force for pointyhat to override su
.else
TERM?=		vt100	# Default value needed for tput in jail or tinderbox
.endif

PATHCS=		${PREFIX}/Saturne
CS_HOME=	${PATHCS}/Noyau/ncs
ECS_HOME=	${PATHCS}/Enveloppe/ecs
PLIST_SUB=	CS_HOME=Saturne/Noyau/ncs ECS_HOME=Saturne/Enveloppe/ecs

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_DIRS=	data include src users
BIN_SCRIPTS=	autovalid compiler_version cree_sat gracehst grp info_cs	\
		lance_install rang_mpi.sh verifmail
BIN_DATAS=	Makefile SaturneGUI autovalid.xml cs_profile lance lance.help	\
		macros_FreeBSD.mk

.if defined(WITH_LAM)
MPI_HOME=	${LOCALBASE}
BUILD_DEPENDS+=	${MPI_HOME}/lib/liblam.a:${PORTSDIR}/net/lam
RUN_DEPENDS+=	${MPI_HOME}/bin/lamboot:${PORTSDIR}/net/lam
MPI_LIBS=	-lmpi -llam
.elif defined(WITH_OPENMPI)
MPI_HOME=	${LOCALBASE}/mpi/openmpi
BUILD_DEPENDS+=	${MPI_HOME}/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${MPI_HOME}/bin/mpirun:${PORTSDIR}/net/openmpi
MPI_LIBS=	-lmpi -lorte -lopal
.else
MPI_HOME=	${LOCALBASE}/mpich2
BUILD_DEPENDS+=	${MPI_HOME}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${MPI_HOME}/bin/mpirun:${PORTSDIR}/net/mpich2
MPI_LIBS=	-lmpich
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	pdftex:${PORTSDIR}/print/teTeX-base
DOCS=		AUTHORS COMPATIBILITY Changelog TODO
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas_r.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS) && !defined(WITHOUT_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS_LIB=	-lcblas -lf77blas -latlas -L${FORTRANLIBDIR} -L${FORTRANLIBDIR2} -lgfortranbegin -lgfortran
.elif !defined(WITHOUT_BLAS)
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS_LIB=	-lblas
.endif

.if exists(${X11BASE}/bin/acroread)
RUN_DEPENDS+=	acroread:${PORTSDIR}/print/acroreadwrapper
.else
RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf
.endif

.if exists(${LOCALBASE}/apps/homard/homard)
WITH_HOMARD=	yes
.endif
.if defined(WITH_HOMARD)
RUN_DEPENDS+=	${LOCALBASE}/apps/homard/homard:${PORTSDIR}/french/homard
.endif

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "By default ncs is built with MPICH2, but you can set WITH_LAM or WITH_OPENMPI"
	@${ECHO_MSG} "if you prefer."
	@${ECHO_MSG}
	@${ECHO_MSG} "By default ncs is built with BLAS, unless ATLAS is installed, but you can set"
	@${ECHO_MSG} "WITHOUT_BLAS or WITHOUT_ATLAS if you prefer."
	@${ECHO_MSG}

pre-patch:
	${CP} -p ${WRKSRC}/bin/macros_Linux.mk ${WRKSRC}/bin/macros_FreeBSD.mk

do-configure:
	${RM} ${WRKSRC}/src/base_1/gradco.F.orig
	${REINPLACE_CMD} -e 's|%%PATHCS%%|${PATHCS}|'		\
		-e 's|%%LOCALBASE%%|${LOCALBASE}|'		\
		-e 's|%%FC%%|${FC}|'				\
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|'	\
		-e 's|%%MPI_HOME%%|${MPI_HOME}|'		\
		-e 's|%%MPI_LIBS%%|${MPI_LIBS}|'		\
		${BUILD_WRKSRC}/cs_profile
	${REINPLACE_CMD}	\
	-e 's|/home/saturne/opt/python/arch/$${NOM_ARCH}/bin/python|${PYTHON_CMD}|'	\
		${BUILD_WRKSRC}/SaturneGUI
.if !defined(WITHOUT_BLAS) && !defined(WITHOUT_ATLAS)
	${REINPLACE_CMD} -e 's|BLAS            =0|BLAS            =1|'			\
		-e 's|BLAS_INC        =|BLAS_INC        =-I${LOCALBASE}/include|'	\
		-e 's|BLAS_LDFLAGS    =|BLAS_LDFLAGS    =${BLAS_LIB}|'			\
		${BUILD_WRKSRC}/macros_FreeBSD.mk
.endif

do-build:
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./lance_install)
	@${ECHO_MSG}
	@${ECHO_MSG} "===>  Build terminated."
	@${ECHO_MSG}
	(cd ${WRKSRC}/arch/${OPSYS}; ${FIND} . -name ".readme*" | ${XARGS}	\
		${GREP} -B 10 '^Stop in ') || ${TRUE}
.if !defined(NOPORTDOCS)
	@${ECHO_MSG}
	@${ECHO_MSG} "===>  Building documentation."
	@${ECHO_MSG}
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ./lance_install DOC)
.endif

do-install:
	${FIND} ${WRKSRC}/arch/${OPSYS}/lib -name "libsaturne*" -exec	\
		${INSTALL_DATA} {} ${PREFIX}/lib \;
	${MKDIR} ${CS_HOME}/bin ${CS_HOME}/arch/${OPSYS}/lib ${ECS_HOME}/bin
	${LN} -sf ${PREFIX}/lib/libsaturne*.a ${CS_HOME}/arch/${OPSYS}/lib/
.for sd in ${SUB_DIRS}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} ${sd} ${CS_HOME})
.endfor
	${CHMOD} -R u+w ${CS_HOME}/users
	(cd ${BUILD_WRKSRC}/ && ${COPYTREE_SHARE} Autovalidation ${CS_HOME}/bin/)
	${INSTALL_SCRIPT} ${BIN_SCRIPTS:S|^|${BUILD_WRKSRC}/|} ${CS_HOME}/bin/
	${INSTALL_DATA} ${BIN_DATAS:S|^|${BUILD_WRKSRC}/|} ${CS_HOME}/bin/
	${CHMOD} u+w ${CS_HOME}/bin/lance
	${LN} -sf ${LOCALBASE}/bin/ecs ${ECS_HOME}/bin/
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${CS_HOME}/bin/Autovalidation
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${CS_HOME}/bin/Autovalidation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${CS_HOME}/doc/NOYAU/ ${CS_HOME}/doc/UTILISATION/
	${INSTALL_DATA} ${WRKSRC}/doc/NOYAU/noyau.pdf ${CS_HOME}/doc/NOYAU/
	${INSTALL_DATA} ${WRKSRC}/doc/UTILISATION/saturne.pdf ${CS_HOME}/doc/UTILISATION/
	${LN} -sf ${CS_HOME}/doc/NOYAU/noyau.pdf ${CS_HOME}/doc/UTILISATION/saturne.pdf	\
		${DOCSDIR}/
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	${LN} -sf ${LOCALBASE}/share/doc/ecs/ ${ECS_HOME}/doc
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
