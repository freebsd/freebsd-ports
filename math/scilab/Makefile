# New ports collection makefile for:   scilab
# Date created:        30 April 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	scilab
PORTVERSION=	5.2.2
PORTREVISION=	1
CATEGORIES=	math cad parallel java
MASTER_SITES=	http://www.scilab.org/download/${PORTVERSION}/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Scientific software package for numerical computations

# A partial dependencies list can be found at:
# http://wiki.scilab.org/Dependencies_of_Scilab_5.X
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		pcre.0:${PORTSDIR}/devel/pcre \
		readline.6:${PORTSDIR}/devel/readline

MAKE_JOBS_UNSAFE=	yes

USE_FORTRAN=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib ${PTHREAD_LIBS}
FFLAGS+=	-fPIC

OPTIONS=	ATLAS "Use Atlas instead of Blas" OFF \
		FFTW "Use FFTW" ON \
		GUI "Build GUI (requires Java and required for docs)" ON \
		NLS "Build localization" OFF \
		MATIO "Matlab compatibility" OFF \
		OCAML "Build ocaml modelica compiler (requires GUI)" OFF \
		PVM "Parallel Virtual Machine support" OFF \
		TK "TCL/TK support" OFF \
		UMFPACK "Build with umfpack" ON

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
PLIST_SUB+=	TK="@comment "
.else
USE_TK=		yes
CONFIGURE_ARGS+=	--with-tk-library=${LOCALBASE}/lib \
			--with-tk-include=${TK_INCLUDEDIR} \
			--with-tcl-library=${LOCALBASE}/lib \
			--with-tcl-include=${TCL_INCLUDEDIR}
PLIST_SUB+=	TK=""
.endif

.if defined(WITHOUT_GUI)
CONFIGURE_ARGS+=	--without-gui \
			--without-javasci \
			--without-hdf5 \
			--disable-build-help
PLIST_SUB+=	GUI="@comment "
PLIST_SUB+=	NOGUI=""
NOPORTDOCS=	YES
.else
LIB_DEPENDS+=	hdf5.6:${PORTSDIR}/science/hdf5-18

BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant \
		${JAVALIBDIR}/flexdock-0.5.1.jar:${PORTSDIR}/devel/flexdock \
		${JAVALIBDIR}/jogl.jar:${PORTSDIR}/graphics/jogl \
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/jgraphx.jar:${PORTSDIR}/java/jgraphx \
		${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks \
		${JAVALIBDIR}/skinlf.jar:${PORTSDIR}/x11-toolkits/skinlf \
		${JAVALIBDIR}/jrosetta-API.jar:${PORTSDIR}/java/jrosetta \
		${JAVALIBDIR}/jhall.jar:${PORTSDIR}/java/javahelp \
		${JAVALIBDIR}/jlatexmath-0.8.9.jar:${PORTSDIR}/math/jlatexmath \
		fop:${PORTSDIR}/textproc/fop \
		${LOCALBASE}/share/java/batik/batik.jar:${PORTSDIR}/graphics/batik \
		foprep:${PORTSDIR}/math/jeuclid \
		${JAVALIBDIR}/commons-io.jar:${PORTSDIR}/devel/jakarta-commons-io \
		${JAVALIBDIR}/xmlgraphics-commons.jar:${PORTSDIR}/graphics/xmlgraphics-commons \
		${JAVALIBDIR}/xml-apis-ext.jar:${PORTSDIR}/textproc/xml-commons \
		${JAVALIBDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework \
		${LOCALBASE}/share/xsl/docbook/javahelp/javahelp.xsl:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		swig:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/share/examples/saxon/data/books.dtd:${PORTSDIR}/textproc/saxon \
		${JAVALIBDIR}/jhdf5.jar:${PORTSDIR}/science/hdf-java

RUN_DEPENDS+=	${JAVALIBDIR}/flexdock-0.5.1.jar:${PORTSDIR}/devel/flexdock \
		${JAVALIBDIR}/jogl.jar:${PORTSDIR}/graphics/jogl \
		${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/jgraphx.jar:${PORTSDIR}/java/jgraphx \
		${JAVALIBDIR}/looks.jar:${PORTSDIR}/devel/looks \
		${JAVALIBDIR}/skinlf.jar:${PORTSDIR}/x11-toolkits/skinlf \
		${JAVALIBDIR}/jrosetta-API.jar:${PORTSDIR}/java/jrosetta \
		${JAVALIBDIR}/jhall.jar:${PORTSDIR}/java/javahelp \
		${JAVALIBDIR}/jlatexmath-0.8.9.jar:${PORTSDIR}/math/jlatexmath \
		fop:${PORTSDIR}/textproc/fop \
		${LOCALBASE}/share/java/batik/batik.jar:${PORTSDIR}/graphics/batik \
		foprep:${PORTSDIR}/math/jeuclid \
		${JAVALIBDIR}/commons-io.jar:${PORTSDIR}/devel/jakarta-commons-io \
		${JAVALIBDIR}/xmlgraphics-commons.jar:${PORTSDIR}/graphics/xmlgraphics-commons \
		${JAVALIBDIR}/xml-apis-ext.jar:${PORTSDIR}/textproc/xml-commons \
		${JAVALIBDIR}/avalon-framework.jar:${PORTSDIR}/devel/avalon-framework \
		${LOCALBASE}/share/xsl/docbook/javahelp/javahelp.xsl:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${JAVALIBDIR}/jhdf5.jar:${PORTSDIR}/science/hdf-java

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_BUILD=	yes
JAVA_RUN=	yes
USE_XORG=	x11

CONFIGURE_ARGS+=	--with-jdk=${JAVA_HOME} \
			--with-docbook=${LOCALBASE}/share/xsl/docbook

DESKTOP_ENTRIES=	"SciLab" \
			"Scientific software package for numerical computations" \
			"${DATADIR}/icons/scilab.xpm" "scilab" \
			"Application;Education;Math;" false

PLIST_SUB+=	GUI=""
PLIST_SUB+=	NOGUI="@comment "
.endif

.if defined(WITHOUT_FFTW)
CONFIGURE_ARGS+=	--without-fftw
PLIST_SUB+=	FFTW="@comment "
.else
LIB_DEPENDS+=	fftw3.5:${PORTSDIR}/math/fftw3
PLIST_SUB+=	FFTW=""
.endif

.if defined(WITHOUT_PVM)
CONFIGURE_ARGS+=	--without-pvm
PLIST_SUB+=	PVM="@comment "
.else
BUILD_DEPENDS+=		pvm:${PORTSDIR}/net/pvm
RUN_DEPENDS+=		pvm:${PORTSDIR}/net/pvm

CONFIGURE_ARGS+=	--with-pvm-include=${LOCALBASE}/include \
			--with-pvm-library=${LOCALBASE}/lib

CONFIGURE_ENV=	PVM_ROOT=${LOCALBASE} \
		PVMGETARCH=${LOCALBASE}/lib/pvm/lib/pvmgetarch

PLIST_SUB+=	PVM=""
.endif

.if defined(WITHOUT_UMFPACK)
CONFIGURE_ARGS+=	--without-umfpack
PLIST_SUB+=	UMFPACK="@comment "
.else
LIB_DEPENDS+=	amd.1:${PORTSDIR}/math/suitesparse
CONFIGURE_ARGS+=	--with-umfpack-include=${LOCALBASE}/include \
			--with-umfpack-library=${LOCALBASE}/lib
PLIST_SUB+=	UMFPACK=""
.endif

.if defined(WITHOUT_MATIO)
CONFIGURE_ARGS+=	--without-matio
PLIST_SUB+=	MATIO="@comment "
.else
LIB_DEPENDS+=	matio.1:${PORTSDIR}/math/matio
PLIST_SUB+=	MATIO=""
.endif

.if defined(WITHOUT_OCAML)
CONFIGURE_ARGS+=	--without-ocaml
PLIST_SUB+=	OCAML="@comment "
.else
BUILD_DEPENDS+=	ocaml:${PORTSDIR}/lang/ocaml
RUN_DEPENDS+=	ocaml:${PORTSDIR}/lang/ocaml
PLIST_SUB+=	OCAML=""
.endif

post-patch:
	# Configure fixes
	${REINPLACE_CMD} -e 's|/usr/lib/java|${JAVALIBDIR}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|/usr/lib64/jni|${LOCALBASE}/lib/|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-ldl | |' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-L$$with_umfpack_library|-L$$with_umfpack_library -lgfortran|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-lumfpack|-lumfpack -lamd -L$$with_umfpack_library -lgfortran|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|TCLTK_LIBS=" -ldl"|TCLTK_LIBS=" "|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$$jardir/batik.jar|${LOCALBASE}/share/java/batik/batik.jar|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$$jardir/fop.jar|${LOCALBASE}/share/java/fop/build/fop.jar|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|$$jardir/jeuclid-core*.jar|${LOCALBASE}/share/java/jeuclid/repo/jeuclid-core*.jar|' ${WRKSRC}/configure
	# Build fixes
	${REINPLACE_CMD} -e 's|$$(CFLAGS:-O%=)|-I${LOCALBASE}/include -L${LOCALBASE}/lib|' ${WRKSRC}/modules/elementary_functions/Makefile.in
	${REINPLACE_CMD} -e 's|freebsd|__FreeBSD__|g' ${WRKSRC}/modules/sparse/includes/spConfig.h
	${REINPLACE_CMD} -e 's|exp10(|pow(10., |g' ${WRKSRC}/modules/graphics/src/c/Format.c \
		${WRKSRC}/modules/graphics/src/c/getHandleProperty/set_log_flags_property.c
	@# malloc.h -> stdlib.h conversions
	@${GREP} -lr "<malloc.h>" ${WRKSRC} \
		| ${XARGS} ${REINPLACE_CMD} -e \
		's/[<"]malloc.h[>"]/<stdlib.h>/'
	#Install fixes
	${MV} ${WRKSRC}/modules/call_scilab/examples/call_scilab/NET/VB.NET/My\ Project/ \
		${WRKSRC}/modules/call_scilab/examples/call_scilab/NET/VB.NET/My_Project/
	${REINPLACE_CMD} -e 's|My Project|My_Project|g' ${WRKSRC}/modules/call_scilab/examples/call_scilab/NET/VB.NET/VB.NET.vbproj
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/%%PORTDOCS%%/d' ${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's/%%PORTDOCS%%//' ${WRKSRC}/Makefile.in
.endif

pre-install:
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${FIND} ${WRKSRC} -name .cvsignore -delete

.include <bsd.port.mk>
