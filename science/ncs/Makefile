# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	ncs
PORTVERSION=	2.0.4
PORTREVISION=	9
CATEGORIES=	science parallel
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/code_saturne/Releases/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Kernel

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt4-core>=0:${PORTSDIR}/devel/py-qt4	\
		cs_preprocess:${PORTSDIR}/science/ecs	\
		pyrcc4:${PORTSDIR}/textproc/py-qt4-xml
LIB_DEPENDS=	libfvm.so:${PORTSDIR}/science/fvm	\
		libmei.so:${PORTSDIR}/science/mei
RUN_DEPENDS=	xmgrace:${PORTSDIR}/math/grace	\
		bash:${PORTSDIR}/shells/bash	\
		xterm:${PORTSDIR}/x11/xterm	\
		cs_preprocess:${PORTSDIR}/science/ecs

USES=		fortran gettext gmake iconv libtool shebangfix zip
USE_GNOME=	libxml2
USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SHEBANG_FILES=	bin/runcase.in
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MPI_LIBS="${MPI_LIBS}" \
		PYEXE="${PYTHON_CMD}"
MAKE_ENV=	NOM_ARCH=${OPSYS} CS_MPI_PATH=${MPI_HOME}/bin	\
		PTHREAD_LIBS=${PTHREAD_LIBS} TERM=${TERM}	\
		MPI_HOME=${MPI_HOME} MPI_LIBS="${MPI_LIBS}"
USE_LDCONFIG=	yes
NEED_ROOT=	yes

FORTRANLIBDIR=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``
FORTRANLIBDIR2=	`${DIRNAME} \\`${FC} -print-libgcc-file-name\\``/../../../

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

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

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	tex:build
BUILD_DEPENDS+=	fig2dev:${PORTSDIR}/print/transfig
ALL_TARGET=	all pdf
INSTALL_TARGET=	install install-pdf
DOCS=		AUTHORS COMPATIBILITY ChangeLog README
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libatlas.so) && !defined(WITH_BLAS)
WITH_ATLAS=	yes
.endif
.if defined(WITH_ATLAS) && !defined(WITHOUT_ATLAS)
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
BLAS_LIB=	-lf77blas
.elif !defined(WITHOUT_BLAS)
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas
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

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:C|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
