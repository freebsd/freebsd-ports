# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	ncs
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	science parallel
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/code_saturne/Releases/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Kernel

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4	\
		cs_preprocess:${PORTSDIR}/science/ecs	\
		pyrcc4:${PORTSDIR}/textproc/py-qt4-xml
LIB_DEPENDS=	fvm.0:${PORTSDIR}/science/fvm	\
		mei.0:${PORTSDIR}/science/mei
RUN_DEPENDS=	xmgrace:${PORTSDIR}/math/grace	\
		bash:${PORTSDIR}/shells/bash	\
		xterm:${PORTSDIR}/x11/xterm	\
		cs_preprocess:${PORTSDIR}/science/ecs

USE_ZIP=	yes
USE_GMAKE=	yes
USES=		gettext iconv
USE_GNOME=	libxml2
USE_PYTHON=	yes
USE_QT_VER=	4
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CPPFLAGS+=	-I${LOCALBASE}/include/libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MPI_LIBS="${MPI_LIBS}"
MAKE_ENV=	NOM_ARCH=${OPSYS} CS_MPI_PATH=${MPI_HOME}/bin	\
		PTHREAD_LIBS=${PTHREAD_LIBS} TERM=${TERM}	\
		MPI_HOME=${MPI_HOME} MPI_LIBS="${MPI_LIBS}"
USE_LDCONFIG=	yes

USE_FORTRAN=	yes
FORTRANLIBDIR=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``
FORTRANLIBDIR2=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``/../../../

.if defined(PACKAGE_BUILDING)
TERM=		vt100	# Force for pointyhat to override su
.else
TERM?=		vt100	# Default value needed for tput in jail or tinderbox
.endif

SUB_DIRS=	data include src users
BIN_SCRIPTS=	autovalid check_mesh compiler_version cree_sat cs.exe gracehst	\
		grp info_cs lance_install rang_mpi.sh
BIN_DATAS=	Makefile SaturneGUI autovalid.xml cs_profile lance lance.help	\
		macros_FreeBSD.mk

MAN1=		code_saturne.1 cs_solver.1

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
USE_TEX=	tex:build
BUILD_DEPENDS+=	fig2dev:${PORTSDIR}/print/transfig
ALL_TARGET=	all pdf
INSTALL_TARGET=	install install-pdf
DOCS=		AUTHORS COMPATIBILITY ChangeLog README
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS) && !defined(WITHOUT_ATLAS)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS_LIB=	-lf77blas
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

pre-configure:
	${REINPLACE_CMD} -e 's|/bin/bash| ${LOCALBASE}/bin/bash|' ${WRKSRC}/bin/runcase.in

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${DOCS:C|^|${WRKSRC}/|} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
