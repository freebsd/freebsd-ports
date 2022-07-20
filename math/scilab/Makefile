PORTNAME=	scilab
PORTVERSION=	6.1.1
PORTREVISION=	3
CATEGORIES=	math cad java
MASTER_SITES=	https://cgit.scilab.org/scilab/snapshot/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scientific software package for numerical computations

LICENSE=	GPLv2 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/COPYING-BSD

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libhdf5.so:science/hdf5 \
		libarpack.so:math/arpack-ng \
		libfftw3.so:math/fftw3 \
		libmatio.so:math/matio \
		libamd.so:math/suitesparse-amd \
		libumfpack.so:math/suitesparse-umfpack
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++17-lang cpe desktop-file-utils eigen:3,build \
		fortran gettext gmake gnome iconv:wchar_t libtool \
		localbase ncurses pathfix pkgconfig shared-mime-info
USE_LOCALE=	en_US.UTF-8

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-gfortran \
		--without-emf \
		--with-eigen-include=${LOCALBASE}/include/eigen3 \
		${ICONV_CONFIGURE_ARG}
LDFLAGS+=	${ICONV_LIB}

CONFIGURE_ENV=	BLAS_LIBS="${BLASLIB}" LAPACK_LIBS="${LAPACKLIB}"
INSTALL_TARGET=	install-strip
WRKSRC_SUBDIR=	scilab

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=	GUI OCAML TK
OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	GUI NETLIB OCAML TK
OPTIONS_EXCLUDE_powerpc64=	GUI
OPTIONS_EXCLUDE_powerpc64le=	GUI
OPTIONS_SUB=	yes

ATLAS_USES=	blaslapack:atlas
NETLIB_USES=	blaslapack:netlib
OPENBLAS_USES=	blaslapack:openblas

GUI_DESC=	Java-based Graphical User Interface
OCAML_DESC=	Scicos - dynamical system simulator (requires GUI)

# Java dependencies:
_GUI_DEPENDS+=	${JAVALIBDIR}/flexdock.jar:devel/flexdock \
		${JAVALIBDIR}/jogl2.jar:graphics/jogamp-jogl \
		foprep:math/jeuclid \
		${JAVALIBDIR}/jhall.jar:java/javahelp \
		${JAVALIBDIR}/jrosetta-api.jar:java/jrosetta \
		${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVALIBDIR}/jgraphx.jar:java/jgraphx \
		${JAVALIBDIR}/jlatexmath.jar:math/jlatexmath \
		${LOCALBASE}/share/java/ecj-4.5.jar:lang/gcc-ecj45 \
		${JAVALIBDIR}/lucene-core-5.5.5.jar:textproc/lucene5
# Documentation, graphic export:
_GUI_DEPENDS+=	${LOCALBASE}/share/java/fop/build/fop.jar:textproc/fop \
		${JAVALIBDIR}/jlatexmath-fop.jar:math/jlatexmath \
		${LOCALBASE}/share/java/batik/lib/batik-all.jar:graphics/batik \
		${JAVALIBDIR}/avalon-framework.jar:devel/avalon-framework \
		${JAVALIBDIR}/commons-io.jar:devel/apache-commons-io \
		${JAVALIBDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons
# Code quality:
_GUI_DEPENDS+=	${JAVALIBDIR}/commons-beanutils.jar:java/apache-commons-beanutils \
		${JAVALIBDIR}/antlr.jar:devel/antlr \
		${JAVALIBDIR}/junit4.jar:java/junit \
		${LOCALBASE}/bin/splint:devel/splint
# Documentation building:
_GUI_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/javahelp/javahelp.xsl:textproc/docbook-xsl \
		${JAVALIBDIR}/saxon9he.jar:textproc/saxon-he \
		${JAVALIBDIR}/xml-apis-ext.jar:textproc/xml-commons \
		xsltproc:textproc/libxslt
# Other gui deps:
_GUI_DEPENDS+=	${JAVALIBDIR}/looks.jar:devel/jgoodies-looks \
		${JAVALIBDIR}/skinlf.jar:x11-toolkits/skinlf

# Can't use USE_ANT because it overrides do-build target
GUI_BUILD_DEPENDS=	${_GUI_DEPENDS} \
			ant:devel/apache-ant
GUI_RUN_DEPENDS=	${_GUI_DEPENDS}

GUI_ALL_TARGET=	all doc
GUI_USES=	gl
GUI_USE=	GL=gl JAVA=yes
GUI_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-bin-JAVA_HOME
GUI_CONFIGURE_ON=	--with-jdk=${JAVA_HOME} \
			--with-docbook=${LOCALBASE}/share/xsl/docbook \
			--enable-build-help
GUI_CONFIGURE_OFF=	--without-gui \
			--without-javasci \
			--without-xcos \
			--disable-build-help

OCAML_IMPLIES=		GUI
OCAML_CONFIGURE_WITH=	modelica
OCAML_BUILD_DEPENDS=	ocaml:lang/ocaml \
	${LOCALBASE}/lib/ocaml/site-lib/num/META:math/ocaml-num
OCAML_RUN_DEPENDS=	ocaml:lang/ocaml

TK_CONFIGURE_OFF=	--without-tk
TK_CONFIGURE_ON=	--with-tk-library=${LOCALBASE}/lib \
			--with-tk-include=${TK_INCLUDEDIR} \
			--with-tcl-library=${LOCALBASE}/lib \
			--with-tcl-include=${TCL_INCLUDEDIR}
TK_USES=	tk xorg
TK_USE=		XORG=x11
TK_RUN_DEPENDS=	${LOCALBASE}/lib/bwidget/init.tcl:x11-toolkits/bwidget

.if !exists(/usr/include/omp.h)
CONFIGURE_ARGS+=	--without-openmp
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (rank-1 and scalar)
FFLAGS+=	-fallow-argument-mismatch
.endif

.if ${PORT_OPTIONS:MGUI}
DEPRECATED=	Depends on expired devel/avalon-framework
EXPIRATION_DATE=2022-09-30
.endif

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${LOCALBASE},' ${WRKSRC}/etc/librarypath.xml
	@${REINPLACE_CMD} -e 's, gfortran, ${FC},' ${WRKSRC}/modules/dynamic_link/src/scripts/configure

post-patch-GUI-on:
# scilab segfaults on FreeBSD with C locale
	@${REINPLACE_CMD} 's,LC_ALL=C,,' ${WRKSRC}/Makefile.in
	@# Configure fixes
	@${REINPLACE_CMD} '/ac_java_jvm_jni_lib_flags/s,\(ljvm\),\1 -pthread,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/lib/java|${JAVALIBDIR}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/lib64/jni|${LOCALBASE}/lib/|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} 's,\(DEFAULT_JAR_DIR="\),\1 \
		${LOCALBASE}/share/java/classes \
		${LOCALBASE}/share/java/fop/build \
		${LOCALBASE}/share/java/batik/lib \
		${LOCALBASE}/share/java/jeuclid/repo ,' ${WRKSRC}/configure
# Prefer non-versioned files to avoid excessive rebuilds. This also fixes detection of fop.
	@${REINPLACE_CMD} 's|batik-all\*\.jar|batik-all.jar|g; \
			s|commons-io\*\.jar|commons-io.jar|g; \
			s|commons-logging\*\.jar|commons-logging.jar|g; \
			s|fop\*\.jar|fop.jar|g; \
			s|jlatexmath\*\.jar|jlatexmath.jar|g; \
			s|xmlgraphics-commons\*\.jar|xmlgraphics-commons.jar|g' \
			${WRKSRC}/configure
# Part of the jogamp-jogl-2.3 patch:
	@${REINPLACE_CMD} -e 's|javax.media.opengl.glu.GLUnurbs|com.jogamp.opengl.glu.GLUnurbs|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|jogamp.common.os.MachineDescriptionRuntime|jogamp.common.os.MachineDataInfoRuntime|' ${WRKSRC}/configure
	@# Run fixes
	@${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/bin/scilab

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/.atoms

post-install:
	@# Remove empty dirs in DATADIR/modules - they will be removed by the
	@# toolbox uninstaller otherwise if 3rd party toolboxes are used
	@${FIND} ${STAGEDIR}${DATADIR}/modules -type d -empty -delete

.include <bsd.port.post.mk>
