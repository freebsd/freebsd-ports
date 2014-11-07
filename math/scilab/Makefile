# Created by: js@jeannot.org
# $FreeBSD$

PORTNAME=	scilab
PORTVERSION=	5.5.0
PORTREVISION=	1
CATEGORIES=	math cad java
MASTER_SITES=	http://www.scilab.org/download/${PORTVERSION}/
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scientific software package for numerical computations

# A partial dependencies list can be found at:
# http://wiki.scilab.org/Dependencies_of_Scilab_5.X
LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libhdf5.so:${PORTSDIR}/science/hdf5 \
		libarpack.so:${PORTSDIR}/math/arpack \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libmatio.so:${PORTSDIR}/math/matio \
		libamd.so:${PORTSDIR}/math/suitesparse
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USES=		desktop-file-utils fortran gettext gmake iconv libtool \
		pathfix pkgconfig shared-mime-info
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gfortran \
		--without-emf \
		-disable-static-system-lib
CONFIGURE_ENV=	BLAS_LIBS="${BLAS_LIBS}" LAPACK_LIBS="${LAPACK_LIBS}"
MAKE_ENV=	LANG=en_US.UTF-8 \
		LC_ALL=en_US.UTF-8
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ATLAS GUI OCAML TK
OPTIONS_DEFAULT=	GUI OCAML TK
OPTIONS_SUB=	yes

ATLAS_DESC=	Use Atlas instead of Blas
GUI_DESC=	Graphical User Interface (Java)
OCAML_DESC=	Scicos - dynamical system simulator (requires GUI)

# Java dependencies:
_GUI_DEPENDS+=	${JAVALIBDIR}/flexdock.jar:${PORTSDIR}/devel/flexdock \
		${JAVALIBDIR}/jogl2.jar:${PORTSDIR}/graphics/jogamp-jogl \
		foprep:${PORTSDIR}/math/jeuclid \
		${JAVALIBDIR}/jhall.jar:${PORTSDIR}/java/javahelp \
		${JAVALIBDIR}/jrosetta-api.jar:${PORTSDIR}/java/jrosetta \
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/jgraphx.jar:${PORTSDIR}/java/jgraphx \
		${JAVALIBDIR}/jlatexmath.jar:${PORTSDIR}/math/jlatexmath \
		${LOCALBASE}/share/java/ecj-4.5.jar:${PORTSDIR}/lang/gcc-ecj45
# Documentation, graphic export:
_GUI_DEPENDS+=	${LOCALBASE}/share/java/fop/build/fop.jar:${PORTSDIR}/textproc/fop \
		${JAVALIBDIR}/jlatexmath-fop.jar:${PORTSDIR}/math/jlatexmath \
		${LOCALBASE}/share/java/batik/lib/batik-all.jar:${PORTSDIR}/graphics/batik \
		${JAVALIBDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework \
		${JAVALIBDIR}/commons-io.jar:${PORTSDIR}/devel/jakarta-commons-io \
		${JAVALIBDIR}/xmlgraphics-commons.jar:${PORTSDIR}/graphics/xmlgraphics-commons
# Code quality:
_GUI_DEPENDS+=	${JAVALIBDIR}/commons-beanutils.jar:${PORTSDIR}/java/jakarta-commons-beanutils \
		${JAVALIBDIR}/antlr.jar:${PORTSDIR}/devel/antlr \
		${JAVALIBDIR}/junit4.jar:${PORTSDIR}/java/junit \
		${LOCALBASE}/bin/splint:${PORTSDIR}/devel/splint
# Documentation building:
_GUI_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/javahelp/javahelp.xsl:${PORTSDIR}/textproc/docbook-xsl \
		${JAVALIBDIR}/saxon9he.jar:${PORTSDIR}/textproc/saxon-he \
		${JAVALIBDIR}/xml-apis-ext.jar:${PORTSDIR}/textproc/xml-commons \
		xsltproc:${PORTSDIR}/textproc/libxslt
# Other gui deps:
_GUI_DEPENDS+=	${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks \
		${JAVALIBDIR}/skinlf.jar:${PORTSDIR}/x11-toolkits/skinlf

# Can't use USE_ANT because it overrides do-build target
GUI_BUILD_DEPENDS=	${_GUI_DEPENDS} \
			ant:${PORTSDIR}/devel/apache-ant
GUI_RUN_DEPENDS=	${_GUI_DEPENDS}

GUI_ALL_TARGET=	all doc
GUI_USE=	GL=gl
GUI_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-bin-JAVA_HOME
GUI_CONFIGURE_ON=	--with-jdk=${JAVA_HOME} \
			--with-docbook=${LOCALBASE}/share/xsl/docbook \
			--enable-build-help
GUI_CONFIGURE_OFF=	--without-gui \
			--without-javasci \
			--without-xcos \
			--disable-build-help
CONFIGURE_ENV_OFF=	JAVADOC="${TRUE}"

OCAML_CONFIGURE_WITH=	modelica
OCAML_BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml
OCAML_RUN_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

TK_CONFIGURE_OFF=	--without-tk
TK_CONFIGURE_ON=	--with-tk-library=${LOCALBASE}/lib \
			--with-tk-include=${TK_INCLUDEDIR} \
			--with-tcl-library=${LOCALBASE}/lib \
			--with-tcl-include=${TCL_INCLUDEDIR}
TK_USES=	tk
TK_USE=		XORG=x11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libatlas.so:${PORTSDIR}/math/atlas
BLAS_LIBS=	-lf77blas
LAPACK_LIBS=	-lalapack -lcblas
.else
LIB_DEPENDS+=	liblapack.so:${PORTSDIR}/math/lapack \
		libblas.so:${PORTSDIR}/math/blas
BLAS_LIBS=	-lblas
LAPACK_LIBS=	-llapack
.endif

.if ${PORT_OPTIONS:MGUI}
USE_JAVA=	yes
# bsdjava (ie java/jdk16) doesn't have some "extra" classes that aren't in
# the standard java. namespace, but are required by scilab, such as
# javax.xml.bind.annotation.XmlSeeAlso
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes
.endif

post-patch:
	@# Configure fixes
	@${REINPLACE_CMD} -e 's|-ldl | |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lumfpack|-lumfpack -lsuitesparseconfig -lamd -lcholmod -lcolamd $$LAPACK_LIBS $$BLAS_LIBS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|TCLTK_LIBS=" -ldl"|TCLTK_LIBS=" "|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"x=" ==|"x" =|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"x" ==|"x" =|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|sparc64-\*-netbsd\*|amd64-\*-freebsd\*|' ${WRKSRC}/configure
	@# Build fixes
	@${REINPLACE_CMD} -e 's|$$(CFLAGS:-O%=)|-I${LOCALBASE}/include -L${LOCALBASE}/lib|' ${WRKSRC}/modules/elementary_functions/Makefile.in
	@${REINPLACE_CMD} -e 's|freebsd|__FreeBSD__|g' ${WRKSRC}/modules/sparse/includes/spConfig.h
	@# malloc.h -> stdlib.h conversions
	@${GREP} -lr "<malloc.h>" ${WRKSRC} \
		| ${XARGS} ${REINPLACE_CMD} -e \
		's/[<"]malloc.h[>"]/<stdlib.h>/'
	@# Run fixes
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|' ${WRKSRC}/etc/librarypath.xml
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/etc/librarypath.xml
	@${REINPLACE_CMD} -e 's, gfortran, ${FC},' ${WRKSRC}/modules/dynamic_link/src/scripts/configure
.if ${PORT_OPTIONS:MGUI}
	@# Configure fixes
	@${REINPLACE_CMD} -e 's|/usr/lib/java|${JAVALIBDIR}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/lib64/jni|${LOCALBASE}/lib/|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/batik-all.jar|${LOCALBASE}/share/java/batik/lib/batik-all.jar|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/fop.jar|${LOCALBASE}/share/java/fop/build/fop.jar|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/jeuclid-core*.jar|${LOCALBASE}/share/java/jeuclid/repo/jeuclid-core*.jar|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|jrosetta-API.jar|jrosetta-api.jar|' ${WRKSRC}/configure
	@# Run fixes
	@${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/bin/scilab
	@${REINPLACE_CMD} -e 's|/usr/share/scilab|${DATADIR}|' ${WRKSRC}/desktop/scilab.desktop
	@${REINPLACE_CMD} -e 's|/usr/share/scilab-cli|${DATADIR}|' \
		${WRKSRC}/desktop/scilab-adv-cli.desktop ${WRKSRC}/desktop/scilab-cli.desktop
.if ${OSVERSION} < 900000 && ${ARCH} == "amd64"
	@# Avoids segfault when building help
	@${REINPLACE_CMD} 's|JIT|NONE|' ${WRKSRC}/etc/jvm_options.xml
.endif
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/.atoms
	@${TOUCH} ${STAGEDIR}${DATADIR}/.atoms/.keep_me

post-install:
	@# Remove empty dirs in DATADIR/modules - they will be removed by the
	@# toolbox uninstaller otherwise if 3rd party toolboxes are used
	@${FIND} ${STAGEDIR}${DATADIR}/modules -type d -empty -delete

check test regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} \
		${MAKE_ARGS} check)

.include <bsd.port.mk>
