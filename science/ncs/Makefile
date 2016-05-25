# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	ncs
PORTVERSION=	2.0.8
CATEGORIES=	science parallel
MASTER_SITES=	http://code-saturne.org/releases/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Kernel

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=0:devel/py-qt4	\
		cs_preprocess:science/ecs	\
		pyrcc4:textproc/py-qt4-xml
LIB_DEPENDS=	libfvm.so:science/fvm	\
		libmei.so:science/mei
RUN_DEPENDS=	xmgrace:math/grace	\
		bash:shells/bash	\
		xterm:x11/xterm	\
		cs_preprocess:science/ecs

USES=		fortran gettext gmake iconv libtool python shebangfix
USE_GNOME=	libxml2
SHEBANG_FILES=	bin/runcase.in
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MPI_LIBS="${MPI_LIBS}" \
		PYEXE="${PYTHON_CMD}"
CONFIGURE_ARGS=	--with-blas-libs="${BLASLIB} ${LAPACKLIB}"
MAKE_ENV=	NOM_ARCH=${OPSYS} CS_MPI_PATH=${MPI_HOME}/bin	\
		PTHREAD_LIBS=-lpthread TERM=${TERM}	\
		MPI_HOME=${MPI_HOME} MPI_LIBS="${MPI_LIBS}"
USE_LDCONFIG=	yes

FORTRANLIBDIR=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``
FORTRANLIBDIR2=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``/../../../

OPTIONS_DEFINE=		DOCS EXAMPLES BATCH
BATCH_DESC=		Use Torque to submit batches
BATCH_CONFIGURE_WITH=	batch=PBS
BATCH_LIB_DEPENDS=	libtorque.so:sysutils/torque

OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	REFERENCE ATLAS
OPTIONS_DEFAULT=	REFERENCE

REFERENCE_DESC=	Blas / Lapack
REFERENCE_USES=	blaslapack:netlib

ATLAS_DESC=	ATLAS
ATLAS_USES=	blaslapack:atlas

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREFERENCE}
CONFIGURE_ARGS+=	--with-blas-type=BLAS
.else
CONFIGURE_ARGS+=	--with-blas-type=ATLAS
.endif

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

.if defined(WITH_LAM)
MPI_HOME=	${LOCALBASE}
BUILD_DEPENDS+=	${MPI_HOME}/lib/liblam.a:net/lam
RUN_DEPENDS+=	${MPI_HOME}/bin/lamboot:net/lam
MPI_LIBS=	-lmpi -llam
.elif defined(WITH_OPENMPI)
MPI_HOME=	${LOCALBASE}/mpi/openmpi
BUILD_DEPENDS+=	${MPI_HOME}/bin/mpicc:net/openmpi
RUN_DEPENDS+=	${MPI_HOME}/bin/mpirun:net/openmpi
MPI_LIBS=	-lmpi -lorte -lopal
.else
MPI_HOME=	${LOCALBASE}
BUILD_DEPENDS+=	${MPI_HOME}/bin/mpicc:net/mpich2
RUN_DEPENDS+=	${MPI_HOME}/bin/mpirun:net/mpich2
MPI_LIBS=	-lmpich -lmpl -lpthread
.endif

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	tex:build
BUILD_DEPENDS+=	fig2dev:print/transfig
ALL_TARGET=	all pdf
INSTALL_TARGET=	install install-pdf
DOCS=		AUTHORS COMPATIBILITY ChangeLog README
.endif

RUN_DEPENDS+=	xpdf:graphics/xpdf

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "By default ncs is built with MPICH2, but you can set WITH_LAM or WITH_OPENMPI"
	@${ECHO_MSG} "if you prefer."
	@${ECHO_MSG}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
