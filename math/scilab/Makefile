# New ports collection makefile for:   scilab
# Date created:        30 April 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	scilab
PORTVERSION=	5.3.1
CATEGORIES=	math cad parallel java
MASTER_SITES=	http://www.scilab.org/download/${PORTVERSION}/:scilab \
		http://www.predatorlabs.net/dl/:jgraphx \
		http://www.bayofrum.net/dist/jgraphx/:jgraphx
DISTFILES=	${DISTNAME}-src.tar.gz:scilab
EXTRACT_ONLY=	${DISTNAME}-src.tar.gz

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Scientific software package for numerical computations

# A partial dependencies list can be found at:
# http://wiki.scilab.org/Dependencies_of_Scilab_5.X
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		pcre.0:${PORTSDIR}/devel/pcre

MAKE_JOBS_SAFE=	yes

USE_FORTRAN=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib ${PTHREAD_LIBS}
FFLAGS+=	-fPIC

OPTIONS=	ATLAS "Use Atlas instead of Blas" OFF \
		FFTW "Use FFTW" ON \
		GUI "Build GUI (requires Java)" ON \
		HELP "Help Browser (Java based, requires GUI)" ON \
		NLS "Build localization" OFF \
		MATIO "Matlab compatibility" OFF \
		OCAML "Build ocaml modelica compiler (requires GUI)" OFF \
		PVM "Parallel Virtual Machine support" OFF \
		TK "TCL/TK support" OFF \
		UMFPACK "Build with umfpack" OFF

.include <bsd.port.options.mk>

.if defined(WITH_ATLAS)
CONFIGURE_ARGS+=	--with-atlas-library=${LOCALBASE}/lib
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
BLAS_LIBS=	-lalapack -lcblas -lf77blas -latlas
.else
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	blas.2:${PORTSDIR}/math/blas
BLAS_LIBS?=	-llapack -lblas
.endif
MAKE_ENV+=	BLAS_LIBS="-L${LOCALBASE}/lib ${BLAS_LIBS}"

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-build-localization
PLIST_SUB+=	NLS="@comment "
.else
CONFIGURE_ARGS+=	--enable-build-localization
PLIST_SUB+=	NLS=""
.endif

.if defined(WITHOUT_TK)
CONFIGURE_ARGS+=	--without-tk
.else
USE_TK=		yes
CONFIGURE_ARGS+=	--with-tk-library=${LOCALBASE}/lib \
			--with-tk-include=${TK_INCLUDEDIR} \
			--with-tcl-library=${LOCALBASE}/lib \
			--with-tcl-include=${TCL_INCLUDEDIR}
.endif

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=	--without-gui \
			--without-javasci \
			--without-hdf5 \
			--disable-build-help
.else
DISTFILES+=	${JGRAPHX_JAR}:jgraphx
JGRAPHX_VERSION=	1.4.1.0
JGRAPHX_JAR=	jgraphx-${JGRAPHX_VERSION:C/\./_/g}.jar

EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-bin-JAVA_HOME

LIB_DEPENDS+=	hdf5.6:${PORTSDIR}/science/hdf5-18

GUI_DEPENDS=	${JAVALIBDIR}/flexdock.jar:${PORTSDIR}/devel/flexdock \
		${JAVALIBDIR}/jogl.jar:${PORTSDIR}/graphics/jogl \
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks \
		${JAVALIBDIR}/skinlf.jar:${PORTSDIR}/x11-toolkits/skinlf \
		${JAVALIBDIR}/jrosetta-API.jar:${PORTSDIR}/java/jrosetta \
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
		swig:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/share/examples/saxon/data/books.dtd:${PORTSDIR}/textproc/saxon

RUN_DEPENDS+=	${GUI_DEPENDS}

USE_JAVA=	yes
JAVA_VERSION=	1.5+
# bsdjava (ie java/jdk16) doesn't have some "extra" classes that aren't in
# the standard java. namespace, but are required by scilab, such as
# javax.xml.bind.annotation.XmlSeeAlso
JAVA_VENDOR=	freebsd openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes
USE_XORG=	x11

CONFIGURE_ARGS+=	--with-jdk=${JAVA_HOME} \
			--with-docbook=${LOCALBASE}/share/xsl/docbook \
			--enable-build-help

DESKTOP_ENTRIES=	"SciLab" \
			"${COMMENT}" \
			"${DATADIR}/icons/scilab.xpm" "scilab" \
			"Application;Education;Math;" false

.endif

.if !defined(WITHOUT_HELP)
ALL_TARGET=	all doc
.endif

.if defined(WITHOUT_FFTW)
CONFIGURE_ARGS+=	--without-fftw
.else
LIB_DEPENDS+=	fftw3.5:${PORTSDIR}/math/fftw3
.endif

.if defined(WITHOUT_PVM)
CONFIGURE_ARGS+=	--without-pvm
.else
BUILD_DEPENDS+=		pvm:${PORTSDIR}/net/pvm
RUN_DEPENDS+=		pvm:${PORTSDIR}/net/pvm

CONFIGURE_ARGS+=	--with-pvm-include=${LOCALBASE}/include \
			--with-pvm-library=${LOCALBASE}/lib

CONFIGURE_ENV=	PVM_ROOT=${LOCALBASE} \
		PVMGETARCH=${LOCALBASE}/lib/pvm/lib/pvmgetarch
.endif

.if defined(WITHOUT_UMFPACK)
CONFIGURE_ARGS+=	--without-umfpack
.else
LIB_DEPENDS+=	amd.1:${PORTSDIR}/math/suitesparse
CONFIGURE_ARGS+=	--with-umfpack-include=${LOCALBASE}/include \
			--with-umfpack-library=${LOCALBASE}/lib
.endif

.if defined(WITHOUT_MATIO)
CONFIGURE_ARGS+=	--without-matio
.else
LIB_DEPENDS+=	matio.1:${PORTSDIR}/math/matio
.endif

.if defined(WITHOUT_OCAML)
CONFIGURE_ARGS+=	--without-ocaml
PLIST_SUB+=	OCAML="@comment "
.else
BUILD_DEPENDS+=	ocaml:${PORTSDIR}/lang/ocaml
RUN_DEPENDS+=	ocaml:${PORTSDIR}/lang/ocaml
PLIST_SUB+=	OCAML=""
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-NOPORTDOCS
.endif

post-patch:
	@# Configure fixes
	@${REINPLACE_CMD} -e 's|-ldl | |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-L$$with_umfpack_library|-L$$with_umfpack_library -lgfortran|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lumfpack|-lumfpack -lamd -L$$with_umfpack_library -lgfortran|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|TCLTK_LIBS=" -ldl"|TCLTK_LIBS=" "|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"x=" ==|"x" =|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"x" ==|"x" =|g' ${WRKSRC}/configure
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
.if !defined(WITHOUT_GUI)
	@# Configure fixes
	@${REINPLACE_CMD} -e 's|/usr/lib/java|${JAVALIBDIR}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/lib64/jni|${LOCALBASE}/lib/|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/batik-all.jar|${LOCALBASE}/share/java/batik/lib/batik-all.jar|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/fop.jar|${LOCALBASE}/share/java/fop/build/fop.jar|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$jardir/jeuclid-core*.jar|${LOCALBASE}/share/java/jeuclid/repo/jeuclid-core*.jar|' ${WRKSRC}/configure
	@${MKDIR} ${WRKSRC}/thirdparty
	@${CP} ${DISTDIR}/${JGRAPHX_JAR} ${WRKSRC}/thirdparty/jgraphx.jar
	@# Run fixes
	@${REINPLACE_CMD} -e 's|%%JAVALIBDIR%%|${JAVALIBDIR}|' ${WRKSRC}/etc/librarypath.xml
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/etc/librarypath.xml
	@${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' ${WRKSRC}/bin/scilab \
		${WRKSRC}/bin/scilab-adv-cli ${WRKSRC}/bin/scilab-cli
.endif

pre-install:
	@${MKDIR} ${DATADIR}/.atoms
.if !defined(WITHOUT_GUI)
	@${MKDIR} ${DATADIR}/modules && ${INSTALL_DATA} ${DISTDIR}/${JGRAPHX_JAR} ${DATADIR}/modules/jgraphx.jar
	@${REINPLACE_CMD} -e 's|${WRKSRC}/thirdparty/jgraphx.jar|${DATADIR}/modules/jgraphx.jar|g' ${WRKSRC}/etc/classpath.xml
.endif

post-install:
	@# Remove empty dirs in DATDIR/modules - they will be removed by the
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

.include <bsd.port.mk>
