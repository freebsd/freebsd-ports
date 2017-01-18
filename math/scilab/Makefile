# Created by: js@jeannot.org
# $FreeBSD$

PORTNAME=	scilab
PORTVERSION=	5.5.2
PORTREVISION=	4
CATEGORIES=	math cad java
MASTER_SITES=	http://www.scilab.org/download/${PORTVERSION}/
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scientific software package for numerical computations

# A partial dependencies list can be found at:
# http://wiki.scilab.org/Dependencies_of_Scilab_5.X
LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libpcre.so:devel/pcre \
		libcurl.so:ftp/curl \
		libhdf5.so:science/hdf5 \
		libarpack.so:math/arpack \
		libfftw3.so:math/fftw3 \
		libmatio.so:math/matio \
		libamd.so:math/suitesparse
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cpe desktop-file-utils fortran gettext gmake iconv \
		libtool ncurses pathfix pkgconfig shared-mime-info
USE_LOCALE=	en_US.UTF-8
GNU_CONFIGURE=	yes

INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gfortran \
		--without-emf \
		-disable-static-system-lib
CONFIGURE_ENV=	BLAS_LIBS="${BLASLIB}" LAPACK_LIBS="${LAPACKLIB}"
INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=	GUI OCAML TK
OPTIONS_RADIO=	BLAS
OPTIONS_RADIO_BLAS=	ATLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	GUI NETLIB OCAML TK
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
		${JAVALIBDIR}/commons-logging.jar:java/jakarta-commons-logging \
		${JAVALIBDIR}/jgraphx.jar:java/jgraphx \
		${JAVALIBDIR}/jlatexmath.jar:math/jlatexmath \
		${LOCALBASE}/share/java/ecj-4.5.jar:lang/gcc-ecj45
# Documentation, graphic export:
_GUI_DEPENDS+=	${LOCALBASE}/share/java/fop/build/fop.jar:textproc/fop \
		${JAVALIBDIR}/jlatexmath-fop.jar:math/jlatexmath \
		${LOCALBASE}/share/java/batik/lib/batik-all.jar:graphics/batik \
		${JAVALIBDIR}/avalon-framework.jar:devel/avalon-framework \
		${JAVALIBDIR}/commons-io.jar:devel/jakarta-commons-io \
		${JAVALIBDIR}/xmlgraphics-commons.jar:graphics/xmlgraphics-commons
# Code quality:
_GUI_DEPENDS+=	${JAVALIBDIR}/commons-beanutils.jar:java/jakarta-commons-beanutils \
		${JAVALIBDIR}/antlr.jar:devel/antlr \
		${JAVALIBDIR}/junit4.jar:java/junit \
		${LOCALBASE}/bin/splint:devel/splint
# Documentation building:
_GUI_DEPENDS+=	${LOCALBASE}/share/xsl/docbook/javahelp/javahelp.xsl:textproc/docbook-xsl \
		${JAVALIBDIR}/saxon9he.jar:textproc/saxon-he \
		${JAVALIBDIR}/xml-apis-ext.jar:textproc/xml-commons \
		xsltproc:textproc/libxslt
# Other gui deps:
_GUI_DEPENDS+=	${JAVALIBDIR}/looks.jar:devel/looks \
		${JAVALIBDIR}/skinlf.jar:x11-toolkits/skinlf

# Can't use USE_ANT because it overrides do-build target
GUI_BUILD_DEPENDS=	${_GUI_DEPENDS} \
			ant:devel/apache-ant
GUI_RUN_DEPENDS=	${_GUI_DEPENDS}

GUI_ALL_TARGET=	all doc
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
OCAML_BUILD_DEPENDS=	ocaml:lang/ocaml
OCAML_RUN_DEPENDS=	ocaml:lang/ocaml

TK_CONFIGURE_OFF=	--without-tk
TK_CONFIGURE_ON=	--with-tk-library=${LOCALBASE}/lib \
			--with-tk-include=${TK_INCLUDEDIR} \
			--with-tcl-library=${LOCALBASE}/lib \
			--with-tcl-include=${TCL_INCLUDEDIR}
TK_USES=	tk
TK_USE=		XORG=x11
TK_RUN_DEPENDS=	${LOCALBASE}/lib/bwidget/init.tcl:x11-toolkits/bwidget

.if !exists(/usr/include/omp.h)
CONFIGURE_ARGS+=	--without-openmp
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGUI} && ${JAVA_PORT_VERSION:M1.8.*}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-Makefile.in
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

post-patch-GUI-on:
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

pre-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/.atoms

post-install:
	@# Remove empty dirs in DATADIR/modules - they will be removed by the
	@# toolbox uninstaller otherwise if 3rd party toolboxes are used
	@${FIND} ${STAGEDIR}${DATADIR}/modules -type d -empty -delete

check test regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} \
		${MAKE_ARGS} check)

.include <bsd.port.post.mk>
