# Created by: js@jeannot.org
# $FreeBSD$

PORTNAME=	scilab
PORTVERSION=	5.3.3
PORTREVISION=	6
CATEGORIES=	math cad parallel java
MASTER_SITES=	http://www.scilab.org/download/${PORTVERSION}/:scilab \
		http://www.predatorlabs.net/dl/:jgraphx \
		http://www.bayofrum.net/dist/jgraphx/:jgraphx \
		SF/saxon/saxon6/${SAXON_VERSION}:saxon
DISTFILES=	${DISTNAME}-src.tar.gz:scilab
EXTRACT_ONLY=	${DISTNAME}-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scientific software package for numerical computations

EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
NO_STAGE=	yes
# A partial dependencies list can be found at:
# http://wiki.scilab.org/Dependencies_of_Scilab_5.X
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		pcre.3:${PORTSDIR}/devel/pcre


USE_FORTRAN=	yes
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS =	--with-gfortran
CONFIGURE_ENV=	ac_cv_search_pthread_join="${PTHREAD_LIBS}" \
	BLAS_LIBS="${BLAS_LIBS}" LAPACK_LIBS="${LAPACK_LIBS}"

OPTIONS_DEFINE=	ATLAS FFTW GUI HELP NLS MATIO OCAML PVM TK UMFPACK
OPTIONS_DEFAULT=	FFTW GUI HELP

ATLAS_DESC=	Use Atlas instead of Blas
GUI_DESC=	Build GUI (requires Java)
HELP_DESC=	Help Browser (Java based, requires GUI)
MATIO_DESC=	Matlab compatibility
OCAML_DESC=	Build OCaml modelica compiler (requires GUI)
PVM_DESC=	Parallel Virtual Machine support
UMFPACK_DESC=	Build with umfpack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS_LIBS=	-lf77blas
LAPACK_LIBS=	-lalapack -lcblas
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS_LIBS?=	-lblas
LAPACK_LIBS?=	-llapack
.endif

.if ! ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-build-localization
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=	--enable-build-localization
PLIST_SUB+=	NLS=""
.endif

.if ! ${PORT_OPTIONS:MTK}
CONFIGURE_ARGS+=	--without-tk
.else
USE_TK=		yes
CONFIGURE_ARGS+=	--with-tk-library=${LOCALBASE}/lib \
			--with-tk-include=${TK_INCLUDEDIR} \
			--with-tcl-library=${LOCALBASE}/lib \
			--with-tcl-include=${TCL_INCLUDEDIR}
.endif

SAXON_VERSION=	6.5.5
SAXON_DISTFILE=	saxon${SAXON_VERSION:S/./-/g}.zip
DISTFILES+=	${SAXON_DISTFILE}:saxon

.if ! ${PORT_OPTIONS:MGUI}
CONFIGURE_ARGS+=	--without-gui \
			--without-javasci \
			--without-hdf5 \
			--without-xcos \
			--disable-build-help
CONFIGURE_ENV +=	JAVADOC="${TRUE}"
PLIST_SUB+=		WITHOUT_GUI=""
.else
DISTFILES+=	${JGRAPHX_JAR}:jgraphx
JGRAPHX_VERSION=	1.4.1.0
JGRAPHX_JAR=	jgraphx-${JGRAPHX_VERSION:C/\./_/g}.jar

EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bin-JAVA_HOME

LIB_DEPENDS+=	hdf5.7:${PORTSDIR}/science/hdf5-18

GUI_DEPENDS=	${JAVALIBDIR}/flexdock.jar:${PORTSDIR}/devel/flexdock \
		${JAVALIBDIR}/jogl.jar:${PORTSDIR}/graphics/jogl \
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks \
		${JAVALIBDIR}/skinlf.jar:${PORTSDIR}/x11-toolkits/skinlf \
		${JAVALIBDIR}/jrosetta-api.jar:${PORTSDIR}/java/jrosetta \
		${JAVALIBDIR}/jhall.jar:${PORTSDIR}/java/javahelp \
		${JAVALIBDIR}/jlatexmath.jar:${PORTSDIR}/math/jlatexmath \
		fop:${PORTSDIR}/textproc/fop \
		${LOCALBASE}/share/java/batik/lib/batik-all.jar:${PORTSDIR}/graphics/batik \
		foprep:${PORTSDIR}/math/jeuclid \
		${JAVALIBDIR}/commons-io.jar:${PORTSDIR}/devel/jakarta-commons-io \
		${JAVALIBDIR}/xmlgraphics-commons.jar:${PORTSDIR}/graphics/xmlgraphics-commons \
		${JAVALIBDIR}/xml-apis-ext.jar:${PORTSDIR}/textproc/xml-commons \
		${JAVALIBDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework \
		${LOCALBASE}/share/xsl/docbook/javahelp/javahelp.xsl:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${JAVALIBDIR}/jhdf5.jar:${PORTSDIR}/science/hdf-java \
		${JAVALIBDIR}/commons-beanutils.jar:${PORTSDIR}/java/jakarta-commons-beanutils

# Can't use USE_ANT because it overrides do-build target
BUILD_DEPENDS+=	${GUI_DEPENDS} \
		ant:${PORTSDIR}/devel/apache-ant \
		swig:${PORTSDIR}/devel/swig13

RUN_DEPENDS+=	${GUI_DEPENDS}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
# bsdjava (ie java/jdk16) doesn't have some "extra" classes that aren't in
# the standard java. namespace, but are required by scilab, such as
# javax.xml.bind.annotation.XmlSeeAlso
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes
USE_XORG=	x11

CONFIGURE_ARGS+=	--with-jdk=${JAVA_HOME} \
			--with-docbook=${LOCALBASE}/share/xsl/docbook \
			--enable-build-help \
			--enable-build-swig
PLIST_SUB+=		WITHOUT_GUI="@comment "
.endif

.if ${PORT_OPTIONS:MHELP}
ALL_TARGET=	all doc
.endif

.if ! ${PORT_OPTIONS:MFFTW}
CONFIGURE_ARGS+=	--without-fftw
.else
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3
.endif

.if ! ${PORT_OPTIONS:MPVM}
CONFIGURE_ARGS+=	--without-pvm
.else
BUILD_DEPENDS+=		pvm:${PORTSDIR}/net/pvm
RUN_DEPENDS+=		pvm:${PORTSDIR}/net/pvm

CONFIGURE_ARGS+=	--with-pvm-include=${LOCALBASE}/include \
			--with-pvm-library=${LOCALBASE}/lib

CONFIGURE_ENV=	PVM_ROOT=${LOCALBASE} \
		PVMGETARCH=${LOCALBASE}/lib/pvm/lib/pvmgetarch
.endif

.if ! ${PORT_OPTIONS:MUMFPACK}
CONFIGURE_ARGS+=	--without-umfpack
.else
LIB_DEPENDS+=	amd.1:${PORTSDIR}/math/suitesparse
CONFIGURE_ARGS+=	--with-umfpack-include=${LOCALBASE}/include \
			--with-umfpack-library=${LOCALBASE}/lib
.endif

.if ! ${PORT_OPTIONS:MMATIO}
CONFIGURE_ARGS+=	--without-matio
.else
LIB_DEPENDS+=	matio.1:${PORTSDIR}/math/matio
.endif

.if ! ${PORT_OPTIONS:MOCAML}
CONFIGURE_ARGS+=	--without-modelica
PLIST_SUB+=	OCAML="@comment "
.else
BUILD_DEPENDS+=	ocaml:${PORTSDIR}/lang/ocaml
RUN_DEPENDS+=	ocaml:${PORTSDIR}/lang/ocaml
PLIST_SUB+=	OCAML=""
.endif

.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-NOPORTDOCS
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/thirdparty
	@${UNZIP_CMD} ${DISTDIR}/${SAXON_DISTFILE} saxon.jar -d ${WRKSRC}/thirdparty
.if ${PORT_OPTIONS:MGUI}
	@${CP} ${DISTDIR}/${JGRAPHX_JAR} ${WRKSRC}/thirdparty/jgraphx.jar
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
	@${REINPLACE_CMD} -e 's|exp10(|pow(10., |g' ${WRKSRC}/modules/graphics/src/c/Format.c \
		${WRKSRC}/modules/graphics/src/c/getHandleProperty/set_log_flags_property.c
	@# malloc.h -> stdlib.h conversions
	@${GREP} -lr "<malloc.h>" ${WRKSRC} \
		| ${XARGS} ${REINPLACE_CMD} -e \
		's/[<"]malloc.h[>"]/<stdlib.h>/'
	@# Install fixes
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
	@# Run fixes
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|' ${WRKSRC}/etc/librarypath.xml
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/etc/librarypath.xml
.if ${PORT_OPTIONS:MGUI}
	@# Configure fixes
	@${REINPLACE_CMD} -e 's|/usr/lib/java|${JAVALIBDIR}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/lib64/jni|${LOCALBASE}/lib/|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/batik-all.jar|${LOCALBASE}/share/java/batik/lib/batik-all.jar|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/fop.jar|${LOCALBASE}/share/java/fop/build/fop.jar|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/jeuclid-core*.jar|${LOCALBASE}/share/java/jeuclid/repo/jeuclid-core*.jar|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|jrosetta-API.jar|jrosetta-api.jar|' \
		${WRKSRC}/configure
	@# Run fixes
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|' ${WRKSRC}/etc/librarypath.xml
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/etc/librarypath.xml
	@${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/bin/scilab \
		${WRKSRC}/bin/scilab-adv-cli ${WRKSRC}/bin/scilab-cli
	@${REINPLACE_CMD} -e 's|/usr/share/scilab|${DATADIR}|' ${WRKSRC}/desktop/scilab.desktop
	@${REINPLACE_CMD} -e 's|/usr/share/scilab-cli|${DATADIR}|' \
		${WRKSRC}/desktop/scilab-adv-cli.desktop ${WRKSRC}/desktop/scilab-cli.desktop
.if ${OSVERSION} < 900000 && ${ARCH} == "amd64"
	@# Avoids segfault when building help
	@${REINPLACE_CMD} 's|JIT|NONE|' ${WRKSRC}/etc/jvm_options.xml
.endif
.else
	@${REINPLACE_CMD} -e '/^check-local:/,/^$$/s/scilab-adv-cli/scilab-cli/g' \
		${WRKSRC}/Makefile.in
.endif

pre-install:
	@${MKDIR} ${DATADIR}/.atoms
.if ${PORT_OPTIONS:MGUI}
	@${MKDIR} ${DATADIR}/modules && ${INSTALL_DATA} ${DISTDIR}/${JGRAPHX_JAR} ${DATADIR}/modules/jgraphx.jar
	@${REINPLACE_CMD} -e 's|${WRKSRC}/thirdparty/jgraphx.jar|${DATADIR}/modules/jgraphx.jar|g' ${WRKSRC}/etc/classpath.xml
.endif

post-install:
	@# Remove empty dirs in DATADIR/modules - they will be removed by the
	@# toolbox uninstaller otherwise if 3rd party toolboxes are used
	@${FIND} ${DATADIR}/modules -type d -empty -delete
	@# plist for include/scilab
	@${FIND} -s ${PREFIX}/include/scilab -not -type d | ${SORT} | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/scilab -type d | ${SORT} -r | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@# plist for lib/scilab
	@${FIND} -s ${PREFIX}/lib/scilab -not -type d | ${SORT} | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/scilab -type d | ${SORT} -r | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@# plist for share/scilab EXCEPT:
	@# contrib and .atoms (3rd party toolboxes)
	@${FIND} -s ${DATADIR} -not -type d -not -path ${DATADIR}/contrib\* | \
		${SORT} | ${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d -not -path ${DATADIR}/contrib\* \
		-not -path ${DATADIR}/.atoms\* -not -path ${DATADIR} | \
		${SORT} -r | ${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/scilab 2>/dev/null || true" >> ${TMPPLIST}
.if ! ${PORT_OPTIONS:MGUI}
	@${TOUCH} ${DATADIR}/contrib/xcos_toolbox_skeleton/images/h5/.keep_me
.endif

check test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${_MAKE_JOBS} \
		${MAKE_ARGS} check

.include <bsd.port.mk>
