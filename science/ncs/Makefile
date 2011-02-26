# New ports collection makefile for:	ncs
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ncs
PORTVERSION=	1.3.3
PORTREVISION=	7
CATEGORIES=	science parallel
MASTER_SITES=	http://rd.edf.com/fichiers/fckeditor/File/EDF%20RD/Code_Saturne/Fichiers/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Kernel

LIB_DEPENDS=	fvm.0:${PORTSDIR}/science/fvm
RUN_DEPENDS=	xmgrace:${PORTSDIR}/math/grace	\
		ecs:${PORTSDIR}/science/ecs

USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/bin
MAKE_ENV=	NOM_ARCH=${OPSYS} CS_HOME=${WRKSRC} CS_MPI_PATH=${MPI_HOME}/bin	\
		PTHREAD_LIBS=${PTHREAD_LIBS} TERM=${TERM}			\
		MPI_HOME=${MPI_HOME} MPI_LIBS="${MPI_LIBS}"

USE_FORTRAN=	yes
FORTRANLIBDIR=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``
FORTRANLIBDIR2=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``/../../../

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
BIN_SCRIPTS=	autovalid check_mesh compiler_version cree_sat cs.exe gracehst	\
		grp info_cs lance_install rang_mpi.sh
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
MPI_HOME=	${LOCALBASE}
BUILD_DEPENDS+=	${MPI_HOME}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${MPI_HOME}/bin/mpirun:${PORTSDIR}/net/mpich2
MPI_LIBS=	-lmpich -lmpl ${PTHREAD_LIBS}
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	pdftex:${PORTSDIR}/print/teTeX-base	\
		fig2dev:${PORTSDIR}/print/transfig
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

.if exists(${LOCALBASE}/bin/acroread)
RUN_DEPENDS+=	acroread:${PORTSDIR}/print/acroreadwrapper
.else
RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf
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
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|'	\
		-e 's|%%FC%%|${FC}|'				\
		-e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|'	\
		-e 's|%%MPI_HOME%%|${MPI_HOME}|'		\
		-e 's|%%MPI_LIBS%%|${MPI_LIBS}|'		\
		${BUILD_WRKSRC}/cs_profile
.if defined(WITH_ATLAS)
	${REINPLACE_CMD} -e 's|BLAS            =0|BLAS            =1|'			\
		${BUILD_WRKSRC}/macros_FreeBSD.mk
.endif
.if !defined(WITHOUT_BLAS) && !defined(WITHOUT_ATLAS)
	${REINPLACE_CMD} -e 's|BLAS_LDFLAGS    =|BLAS_LDFLAGS    =${BLAS_LIB}|'		\
		-e 's|BLAS_INC        =|BLAS_INC        =-I${LOCALBASE}/include|'	\
		${BUILD_WRKSRC}/macros_FreeBSD.mk
.endif
	${REINPLACE_CMD} -e 's|make|${GMAKE}|g' ${BUILD_WRKSRC}/lance_install

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
	${MKDIR} ${CS_HOME}/bin ${CS_HOME}/arch/${OPSYS}/bin	\
		${CS_HOME}/arch/${OPSYS}/lib ${ECS_HOME}/bin
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
	${INSTALL_PROGRAM} ${WRKSRC}/arch/${OPSYS}/bin/cs13.exe	\
		${CS_HOME}/arch/${OPSYS}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${CS_HOME}/doc/THEORY/ ${CS_HOME}/doc/USER/	\
		${CS_HOME}/doc/TUTORIAL/
	${INSTALL_DATA} ${WRKSRC}/doc/THEORY/theory.pdf ${CS_HOME}/doc/THEORY/
	${INSTALL_DATA} ${WRKSRC}/doc/TUTORIAL/tutorial.pdf ${CS_HOME}/doc/TUTORIAL/
	${INSTALL_DATA} ${WRKSRC}/doc/USER/user.pdf ${CS_HOME}/doc/USER/
	${LN} -sf ${CS_HOME}/doc/THEORY/theory.pdf ${CS_HOME}/doc/TUTORIAL/tutorial.pdf	\
		${CS_HOME}/doc/USER/user.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	${LN} -sf ${LOCALBASE}/share/doc/ecs/ ${ECS_HOME}/doc
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
