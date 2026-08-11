PORTNAME=	scilab
DISTVERSION=	2026.1.0
CATEGORIES=	math cad java

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Scientific software package for numerical computations
WWW=		https://www.scilab.org

LICENSE=	GPLv2 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/COPYING-BSD

BUILD_DEPENDS=	bash:shells/bash \
		splint:devel/splint \
		rapidjson>0:devel/rapidjson \
		fast_float>0:math/fast_float
LIB_DEPENDS=	libpcre2-32.so:devel/pcre2 \
		libcurl.so:ftp/curl \
		libhdf5.so:science/hdf5 \
		libarpack.so:math/arpack-ng@mpich \
		libfftw3.so:math/fftw3 \
		libmatio.so:math/matio \
		libxlnt.so:textproc/xlnt \
		libarrow.so:databases/arrow \
		libamd.so:math/suitesparse-amd \
		libklu.so:math/suitesparse-klu \
		libumfpack.so:math/suitesparse-umfpack
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:c++20-lang cpe desktop-file-utils eigen:3,build \
		fortran gettext gmake gnome iconv:wchar_t libarchive libtool \
		localbase ncurses pathfix pkgconfig shared-mime-info shebangfix
USE_GNOME=	libxml2
SHEBANG_FILES=	modules/differential_equations/src/scripts/getSundials.sh \
		tools/localization/updateLocalizationModule.sh

USE_GITLAB=	yes

NO_SHLIB_REQUIRES_GLOB=	libjava.so libjvm.so libverify.so

CONFLICTS=	javamail-1*	# Difficulties getting along with jakarta-activation
CONFLICTS_INSTALL=	sundials-7*

WRKSRC_SUBDIR=	${PORTNAME}
GNU_CONFIGURE=	yes

USE_CXXSTD=	c++20	# Required for arrow
CXXFLAGS+=	-D_LIBCPP_ENABLE_CXX20_REMOVED_BINDER_TYPEDEFS
LDFLAGS+=	${ICONV_LIB}
CONFIGURE_ARGS=	--with-gfortran \
		--without-emf \
		--with-eigen-include=${LOCALBASE}/include/eigen3 \
		${ICONV_CONFIGURE_ARG}
CONFIGURE_ENV=	BLAS_LIBS="${BLASLIB}" LAPACK_LIBS="${LAPACKLIB}"

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-strip

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

OPTIONS_DEFINE=	GUI OCAML TK
OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	NETLIB OPENBLAS
OPTIONS_DEFAULT=	GUI OPENBLAS OCAML TK
OPTIONS_EXCLUDE_powerpc64=	GUI
OPTIONS_EXCLUDE_powerpc64le=	GUI
OPTIONS_SUB=	yes

NETLIB_USES=	blaslapack:netlib
OPENBLAS_USES=	blaslapack:openblas

GUI_DESC=	Java-based Graphical User Interface
OCAML_DESC=	Scicos - dynamical system simulator (requires GUI)

_JAVADIR=	${LOCALBASE}/share/java
# Java dependencies:
_GUI_DEPENDS+=	${JAVALIBDIR}/flexdock.jar:devel/flexdock \
		${JAVALIBDIR}/jogl2.jar:graphics/jogamp-jogl \
		foprep:math/jeuclid \
		${JAVALIBDIR}/jhall.jar:java/javahelp \
		${JAVALIBDIR}/jrosetta-api.jar:java/jrosetta \
		${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVALIBDIR}/jgraphx.jar:java/jgraphx \
		${JAVALIBDIR}/jlatexmath.jar:math/jlatexmath \
		${JAVALIBDIR}/ecj.jar:java/eclipse-ecj \
		${JAVALIBDIR}/lucene-core-9.12.2.jar:textproc/lucene9
# Documentation, graphic export:
_GUI_DEPENDS+=	${JAVALIBDIR}/fop-core.jar:textproc/fop \
		${JAVALIBDIR}/jlatexmath-fop.jar:math/jlatexmath \
		${_JAVADIR}/batik/lib/batik-all.jar:graphics/batik \
		${JAVALIBDIR}/avalon-framework.jar:devel/avalon-framework \
		${JAVALIBDIR}/commons-io.jar:devel/apache-commons-io \
		${JAVALIBDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons
# Code quality:
_GUI_DEPENDS+=	${JAVALIBDIR}/commons-beanutils.jar:java/apache-commons-beanutils \
		${JAVALIBDIR}/commons-collections.jar:java/apache-commons-collections \
		${JAVALIBDIR}/antlr.jar:devel/antlr \
		${JAVALIBDIR}/junit4.jar:java/junit \
		${LOCALBASE}/bin/splint:devel/splint
# Documentation building:
_GUI_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/javahelp/javahelp.xsl:textproc/docbook-xsl \
		${JAVALIBDIR}/Saxon-HE.jar:textproc/saxon-he \
		${_JAVADIR}/xml-commons/xml-apis-ext.jar:textproc/xml-commons \
		xsltproc:textproc/libxslt
# Other gui deps:
_GUI_DEPENDS+=	${JAVALIBDIR}/looks.jar:devel/jgoodies-looks \
		${JAVALIBDIR}/skinlf.jar:x11-toolkits/skinlf \
		${JAVALIBDIR}/gson.jar:devel/gson \
		${JAVALIBDIR}/jcef.jar:www/jcef \
		${JAVALIBDIR}/httpcore5.jar:www/httpcore5 \
		${JAVALIBDIR}/httpclient5.jar:www/httpclient5 \
		${JAVALIBDIR}/activation.jar:devel/javax-activation \
		${JAVALIBDIR}/jakarta.activation-2.0.1.jar:devel/jakarta-activation \
		${JAVALIBDIR}/jakarta.activation-api.jar:devel/jakarta-activation-api \
		${JAVALIBDIR}/jaxb-api.jar:devel/jaxb-api \
		${JAVALIBDIR}/jaxb-impl.jar:devel/jaxb-impl \
		${JAVALIBDIR}/javax.annotation-api.jar:devel/javax.annotation-api \
		${JAVALIBDIR}/javafx.base.jar:devel/javafx-jars

# Can't use USE_ANT because it overrides do-build target
GUI_BUILD_DEPENDS=	${_GUI_DEPENDS} \
			ant:devel/apache-ant
GUI_RUN_DEPENDS=	${_GUI_DEPENDS}

GUI_ALL_TARGET=	all doc
GUI_USES=	gl java
# Failures with recent JDK: it uses LibraryPath.addPath to dynamically modify java.library.path
GUI_VARS=	JAVA_VERSION=21	\
		LDFLAGS+="-Wl,-rpath=${JAVA_HOME}/lib -Wl,-rpath=${JAVA_HOME}/lib/server"
GUI_USE=	GL=gl
GUI_CONFIGURE_ON=	--with-jdk=${JAVA_HOME} \
			--enable-build-help
GUI_CONFIGURE_OFF=	--without-gui \
			--without-javasci \
			--without-xcos \
			--disable-build-help

OCAML_IMPLIES=		GUI
OCAML_CONFIGURE_WITH=	modelica
OCAML_BUILD_DEPENDS=	ocaml:lang/ocaml \
			ocaml-num>0:math/ocaml-num \
			ocamlfind:devel/ocaml-findlib
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
OMPLIB=			""
.else
OMPLIB=			-lomp
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=int-conversion
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.if ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (rank-1 and scalar)
FFLAGS+=	-fallow-argument-mismatch
.endif

pre-patch:
	${CP} ${WRKSRC}/modules/atoms/tests/unit_tests/repositories.orig	\
		${WRKSRC}/modules/atoms/tests/unit_tests/repositories
	${MV} ${WRKSRC}/modules/cacsd/tests/unit_tests/dscr.tst.orig	\
		${WRKSRC}/modules/cacsd/tests/unit_tests/dscr.tst.orig_

pre-configure:
.for cf in librarypath.xml jvm_options.xml jvm_options.xml.inst
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g;s|%%JAVA_HOME%%|${JAVA_HOME}|g' \
			-e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/etc/${cf}
.endfor
	${REINPLACE_CMD} -e 's|%%WRKSRC%%|${WRKSRC}|g' ${WRKSRC}/etc/jvm_options.xml
	${REINPLACE_CMD} -e 's, gfortran, ${FC},' \
		${WRKSRC}/modules/dynamic_link/src/scripts/configure
.if ${COMPILER_TYPE} == clang
	${REINPLACE_CMD} -e 's|std::filesystem|std::__fs::filesystem|g' \
		${WRKSRC}/modules/fileio/src/cpp/fullpath.cpp \
		${WRKSRC}/modules/fileio/sci_gateway/cpp/sci_get_absolute_file_path.cpp
	${REINPLACE_CMD} -e 's|std::binary_function|std::__binary_function|' \
		${WRKSRC}/modules/ast/includes/types/sparseOp.hxx
	${REINPLACE_CMD} -e 's|std::unary_function|std::__unary_function|' \
		${WRKSRC}/modules/ast/src/cpp/types/sparse.cpp
.endif
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/modules/string/tests/unit_tests/strsplit.tst

pre-configure-GUI-on:
# scilab segfaults on FreeBSD with C locale
	${REINPLACE_CMD} 's,LC_ALL=C,,' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} '/ac_java_jvm_jni_lib_flags/s,\(ljvm\),\1 -pthread,' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/lib/java|${JAVALIBDIR}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/lib64/jni|${LOCALBASE}/lib/|g' ${WRKSRC}/configure
	${REINPLACE_CMD} 's,\(DEFAULT_JAR_DIR="\),\1 \
		${JAVALIBDIR} \
		${_JAVADIR} \
		${_JAVADIR}/batik/lib \
		${_JAVADIR}/fop/build \
		${_JAVADIR}/jeuclid/repo \
		${_JAVADIR}/xml-commons \
		,' ${WRKSRC}/configure
# Prefer non-versioned files to avoid excessive rebuilds. This also fixes detection of fop.
	${REINPLACE_CMD} 's|batik-all\*\.jar|batik-all.jar|g; \
			s|commons-io\*\.jar|commons-io.jar|g; \
			s|commons-logging\*\.jar|commons-logging.jar|g; \
			s|fop\*\.jar|fop.jar|g; \
			s|jlatexmath\*\.jar|jlatexmath.jar|g; \
			s|jrosetta-API.jar|jrosetta-api.jar|g; \
			s|saxon9he.jar|saxon-he-*.jar|g; \
			s|xmlgraphics-commons\*\.jar|xmlgraphics-commons.jar|g' \
			${WRKSRC}/configure
# Part of the jogamp-jogl-2.3 patch:
	${REINPLACE_CMD} -e 's|javax.media.opengl.glu.GLUnurbs|com.jogamp.opengl.glu.GLUnurbs|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|jogamp.common.os.MachineDescriptionRuntime|jogamp.common.os.MachineDataInfoRuntime|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/bin/scilab

post-configure:
	${REINPLACE_CMD} -e 's|UTF-8 .UTF-8|UTF-8 LC_ALL=C.UTF-8|'  ${WRKSRC}/Makefile

post-stage:
	${CP} ${WRKSRC}/etc/jvm_options.xml.inst	\
		${STAGEDIR}${DATADIR}/etc/jvm_options.xml

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/.atoms

post-install:
	@${FIND} ${STAGEDIR}${DATADIR}/modules -type d -empty -delete

.include <bsd.port.post.mk>
