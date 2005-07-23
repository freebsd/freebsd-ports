# New ports collection makefile for:	JX
# Date created:		30 July 1999
# Whom:			Davec <davec@unforgettable.com>
#
# $FreeBSD$
#

PORTNAME=	JX
PORTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.matrix.com.br/pub/linuxberg/files/x11/dev/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/X/c++libs
DISTNAME=	${PORTNAME}_source-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ application framework and widget library for X11

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

BROKEN=		Incorrect pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_AUTOCONF_VER=	213
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKDIR}
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}"
MAKE_ENV=	JX_INSTALL_ROOT="${PREFIX}/bin" \
		JX_LIB_ROOT="${PREFIX}/lib"
PLIST_SUB=	LIBACE="${LIBACE}" \
		LIBJTOOL="${LIBJTOOL}" \
		LIBJX="${LIBJX}"
INSTALLS_SHLIB=	yes

# Installs dir with proper permissions
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755
# the libraries
LIBFILES=	libACE-5_0_2.so \
		libjcore-1_5_3.a libjcore-1_5_3.so \
		libjx-1_5_3.a libjx-1_5_3.so
# bin program files
PROGRAMFILES=		lib/util/autodoc/autodoc programs/jxlayout/jxlayout \
			programs/makemake/makemake
PROGRAMFILES_SCRIPT=	jxlayout/jfdesign makemake/makecheck \
			makemake/maketouch
# header files
INCLUDEDIR=	jcore jx
INCLUDEDIR_ACE_WRKSRC=	ACE/ACE_wrappers/ace
INCLUDEDIR_ACE_DIR=	. CLASSIX
# documentation
DOCDIR_PREFIX=	${PREFIX}/share/doc/jx
DOCFILES=	README FAQ LICENSE CHANGES
DOCDIRS=	ACE jxlayout makemake
DOCDIRFILES=	LICENSE README
# examples
EXAMPLEDIRS=		tutorial
EXAMPLEDIR_PREFIX=	${PREFIX}/share/examples/jx
# xpm images
ICONDIRS=	libjx/menu_image
ICONDIR_PREFIX=	${PREFIX}/share/jx
# additional configuration and header files
EXTRALIB_PREFIX=		${PREFIX}/lib/jx
EXTRALIBDIRS=			jxlayout lib make
EXTRALIBFILES_JXLAYOUT=		class_map need_font_list option_map
EXTRALIBFILES_MAKE_WRKSRC=	include/make
EXTRALIBFILES_MAKE_DIR=		. sys
# odd behavior
POSTBUILD_WRKSRC=	jxlayout
# post patch preprocessing
POSTPATCH_FILES=	post-patch-aa
# post configure placement directory
POSTCONFIGURE_WRKSRC=		include/make/sys
# configuration preprocessing
CONFIGURE_PREPROCESSING_FILES=	FreeBSD-2.x_g++ FreeBSD-3.x_g++

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 300000
ALL_TARGET=	freebsd3.x
LIBACE=		5
LIBJTOOL=	0
LIBJX=		1
.else
ALL_TARGET=	freebsd2.x
LIBACE=		5.0
LIBJTOOL=	0.5
LIBJX=		1.5
.endif

# -CURRENT post gcc 3.1
.if ${OSVERSION} >= 500035
BROKEN=	Does not work with gcc 3.x
.endif

# wrapper to allow makemake to work during build time
# it requires some libs which are not available in build time
makemake-extract-wrapper:
	@${SED} \
		-e 's|%libdir%|${WRKSRC}/lib|' \
		-e 's|%makemake%|${WRKSRC}/programs/makemake/makemake|' \
		${FILESDIR}/makemake-template \
		> ${WRKDIR}/makemake
	@${CHMOD} u+rx ${WRKDIR}/makemake

# have all relevant places point to location of the makemake wrapper
makemake-patch-path:
	@${FIND} ${WRKSRC}/libjx ${WRKSRC}/libjcore \
		-name "Make*" \
		-exec ${REINPLACE_CMD} -E \
		-e 's|makemake;|${WRKDIR}/makemake;|' \
		{} \;
	@${REINPLACE_CMD} -E \
		-e 's|; makemake;|; ${WRKDIR}/makemake;|' \
		${WRKSRC}/lib/Makefile

post-extract: makemake-extract-wrapper

post-patch: makemake-patch-path
.for i in ${CONFIGURE_PREPROCESSING_FILES}
	@${CP} ${WRKSRC}/${POSTCONFIGURE_WRKSRC}/${i} ${WRKDIR}/${i}.in
	@cd ${WRKDIR}; ${PATCH} -s ${i}.in < ${PATCHDIR}/${POSTPATCH_FILES}
.endfor

pre-configure:
	@${CP} ${FILESDIR}/configure.in ${WRKDIR}
	@cd ${WRKDIR}; ${AUTOCONF}

post-configure:
.for i in ${CONFIGURE_PREPROCESSING_FILES}
	@${CP} ${WRKDIR}/${i} ${WRKSRC}/${POSTCONFIGURE_WRKSRC}/${i}
.endfor

# odd behavior
post-build:
.for i in ${POSTBUILD_WRKSRC}
	@cd ${WRKSRC}/programs/${i}; ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS}
.endfor

do-install:
.if !defined(NOPORTDOCS)
# Install all documentation
	@${INSTALL_DATA_DIR} ${DOCDIR_PREFIX}
.for i in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCDIR_PREFIX}
.endfor
.for i in ${DOCDIRS}
	@for j in ${DOCDIRFILES} ; \
	do \
		if [ -f ${WRKSRC}/programs/${i}/$${j} ]; \
		then \
			${INSTALL_DATA} ${WRKSRC}/programs/${i}/$${j} \
				${DOCDIR_PREFIX}/$${j}_${i} ; \
		elif [ -f ${WRKSRC}/${i}/$${j} ]; \
		then \
			${INSTALL_DATA} ${WRKSRC}/${i}/$${j} \
				${DOCDIR_PREFIX}/$${j}_${i} ; \
		fi ; \
	done
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCDIR_PREFIX}
	@${INSTALL_DATA} ${WRKSRC}/ACE/ACE_wrappers/VERSION \
		${DOCDIR_PREFIX}/ACE_VERSION
# Install all examples
.for i in ${EXAMPLEDIRS}
	@${INSTALL_DATA_DIR} ${EXAMPLEDIR_PREFIX}/${i} ; \
	cd ${WRKSRC}/${i}; \
	for j in * ; \
	do \
		if [ -f $${j} ]; \
		then \
			${INSTALL_DATA} $${j} ${EXAMPLEDIR_PREFIX}/${i} ; \
		elif [ -d $${j} ]; \
		then \
			${INSTALL_DATA_DIR} ${EXAMPLEDIR_PREFIX}/${i}/$${j} ; \
			for k in $${j}/* ; \
			do \
				${INSTALL_DATA} $${k} ${EXAMPLEDIR_PREFIX}/${i}/$${j} ; \
			done; \
		fi ; \
	done
.endfor
.endif # !defined(NOPORTDOCS)
# Install all icons
.for i in ${ICONDIRS}
	@${INSTALL_DATA_DIR} ${ICONDIR_PREFIX} ; \
	for j in ${WRKSRC}/${i}/*.xpm ; \
	do \
		${INSTALL_DATA} $${j} ${ICONDIR_PREFIX} ; \
	done
.endfor
# Install all header files
.for i in ${INCLUDEDIR}
	@${INSTALL_DATA_DIR} ${PREFIX}/include/${i} ; \
	for j in ${WRKSRC}/include/${i}/*.*h \
		${WRKSRC}/include/${i}/*.tmpl \
		${WRKSRC}/include/${i}/*.tmpls ; \
	do \
		if [ -f $${j} ]; \
		then \
			${INSTALL_DATA} $${j} ${PREFIX}/include/${i}/ ; \
		fi ; \
	done
.endfor
.for i in ${INCLUDEDIR_ACE_DIR}
	@${INSTALL_DATA_DIR} ${PREFIX}/include/ace/${i} ; \
	for j in ${WRKSRC}/${INCLUDEDIR_ACE_WRKSRC}/${i}/*.cpp \
		${WRKSRC}/${INCLUDEDIR_ACE_WRKSRC}/${i}/*.h \
		${WRKSRC}/${INCLUDEDIR_ACE_WRKSRC}/${i}/*.i ; \
	do \
		if [ -f $${j} ]; \
		then \
			${INSTALL_DATA} $${j} ${PREFIX}/include/ace/${i}/ ; \
		fi ; \
	done
.endfor
# Install all libraries
.for i in ${LIBFILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/lib/${i} ${PREFIX}/lib
.endfor
# Install additional library files
.for i in ${EXTRALIBDIRS}
	@${INSTALL_DATA_DIR} ${EXTRALIB_PREFIX}/${i}
.endfor
.for i in ${EXTRALIBFILES_JXLAYOUT}
	@${INSTALL_DATA} ${WRKSRC}/programs/jxlayout/${i} \
			${EXTRALIB_PREFIX}/jxlayout
.endfor
.for i in ${EXTRALIBFILES_MAKE_DIR}
	@${INSTALL_DATA_DIR} ${EXTRALIB_PREFIX}/make/${i} ; \
	for j in ${WRKSRC}/${EXTRALIBFILES_MAKE_WRKSRC}/${i}/* ; \
	do \
		if [ -f $${j} ]; \
		then \
			${INSTALL_DATA} $${j} ${EXTRALIB_PREFIX}/make/${i}/ ; \
		fi ; \
	done
.endfor
# Install all programs
.for i in ${PROGRAMFILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.for i in ${PROGRAMFILES_SCRIPT}
	@${INSTALL_SCRIPT} ${WRKSRC}/programs/${i} ${PREFIX}/bin
.endfor

post-install:
	@${LN} -sf libACE-5_0_2.so \
		${PREFIX}/lib/libACE-5_0_2.so.${LIBACE}
	@${LN} -sf libjcore-1_5_3.so \
		${PREFIX}/lib/libjcore-1_5_3.so.${LIBJX}
	@${LN} -sf libjx-1_5_3.so \
		${PREFIX}/lib/libjx-1_5_3.so.${LIBJX}
.for i in ${LIBFILES}
	@${LN} -sf ../../${i} ${EXTRALIB_PREFIX}/lib/${i}
.endfor

.include <bsd.port.post.mk>
