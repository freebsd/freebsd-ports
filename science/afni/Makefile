PORTNAME=		afni
DISTVERSIONPREFIX=	AFNI_
DISTVERSION=		25.2.00
CATEGORIES=		science biology graphics perl5 python

MAINTAINER=	fernape@FreeBSD.org
COMMENT=	Advanced Functional Neuro Imaging
WWW=		https://afni.nimh.nih.gov/afni/

LICENSE=	GPLv2

BROKEN_aarch64=	fails to build: statement requires expression of scalar type \
		('va_list' (aka '__builtin_va_list') invalid)

CRAN_DEPENDS=	R-cran-lme4>0:math/R-cran-lme4 \
		R-cran-snow>0:science/R-cran-snow \
		R-cran-psych>0:math/R-cran-psych
BUILD_DEPENDS=	gm4:devel/m4 \
		R:math/R \
		${CRAN_DEPENDS}
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libXm.so:x11-toolkits/open-motif \
		libf2c.so:lang/f2c \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgsl.so:math/gsl \
		libicudata.so:devel/icu \
		libnetcdff.so:science/netcdf-fortran \
		libnetpbm.so:graphics/netpbm \
		libpcre2-8.so:devel/pcre2 \
		libpng16.so:graphics/png

# Remote execution of suma.  Also needed for glxinfo.
RUN_DEPENDS=	endian:sysutils/endian \
		ffmpeg:multimedia/ffmpeg \
		qhull:math/qhull \
		R:math/R \
		${CRAN_DEPENDS}

USES=		gettext gl gmake gnome iconv jpeg:run motif readline
USES+=		perl5 python shebangfix tar:xz xorg
USE_GITHUB=	yes
USE_GL=		gl glu
USE_GNOME=	glib20 libxml2
USE_XORG= 	ice sm x11 xau xcb xdmcp xext xft xi xmu xrender xt

SHEBANG_FILES=	scripts_install/* \
		python_scripts/afnipy/*.py \
		python_scripts/scripts/*.py \
		jzosky/*.py \
		jzosky/lib_RetroTS/*.py \
		discoraj/ClusterExplorer/*.py \
		pkundu/*.py \
		pkundu/meica.libs/*.py \
		pkundu/meica.libs/*/*.py \
		pkundu/meica.libs/*/*/*.py

MAKE_ENV=	CC="${CC}" R_SHARE_DIR=${LOCALBASE}/lib/R/share
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	vastness suma

CFLAGS+=	-fcommon -Wno-incompatible-function-pointer-types

###########################################################################
# Install parameters

SUB_FILES=	pkg-message afni.cshrc afni.profile

INSTALL_WRKSRC=	${WRKSRC}/BSD
WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=	DOCS

INSTALL_TMP=	${INSTALL_WRKSRC}-temp
PRESTAGE=	${WRKSRC}/prestage

.include <bsd.port.options.mk>

CONFLICTS=	im \
		nifticlib \
		open-usp-tukubai

X11R6_FILES=	coxplot/Makefile \
		coxplot/Makefile.f2c

PKG_COMPRESSION_LEVEL= 	6

post-extract:
.for f in ${X11R6_FILES}
	@${REINPLACE_CMD} \
		-e 's|/usr/X11R6|$${LOCALBASE}|g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} \
		-E 's|AFNI_[0-9_]+|${PORTVERSION}|g' ${WRKSRC}/AFNI_label.h
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${RM} ${WRKSRC}/3DEdge/src/Makefile.orig

pre-configure:
	@${REINPLACE_CMD} -e "s|-lglib|-lglib-2.0|g" \
		${WRKSRC}/SUMA/SUMA_Makefile
	@${REINPLACE_CMD} \
		-e 's|os\.path\.dirname(os\.path\.abspath(os\.path\.expanduser(sys\.argv\[0\])))|"${DATADIR}"|g' \
		${WRKSRC}/pkundu/meica.py

do-install:
	# AFNI install just dumps everything into one flat directory
	# ${WRKSRC}/BSD == ${INSTALL_WRKSRC}.
	# Preserve ${INSTALL_WRKSRC} and make a sacrificial temp copy
	# to be pruned and rearranged for easy staging
	@${RM} -r ${INSTALL_TMP}
	@${CP} -R ${INSTALL_WRKSRC} ${INSTALL_TMP}

	# Clean up and organize files into ${PRESTAGE}, destroying
	# ${INSTALL_TMP} in the process
	@${RM} -rf ${PRESTAGE}
	@${MKDIR} ${PRESTAGE}/bin \
		${PRESTAGE}/scripts \
		${PRESTAGE}/lib \
		${PRESTAGE}/include \
		${PRESTAGE}/trash \
		${PRESTAGE}/doc \
		${PRESTAGE}/share \
		${PRESTAGE}/pylib
	@${RM}	${INSTALL_TMP}/libf2c.a
	@${MV}	${INSTALL_TMP}/meica.libs \
		${INSTALL_TMP}/shiny \
		${INSTALL_TMP}/lib_RetroTS \
		${INSTALL_TMP}/funstuff \
		${INSTALL_TMP}/AFNI.*rc \
		${INSTALL_TMP}/afnigui* \
		${PRESTAGE}/share
	@${MV}	${INSTALL_TMP}/*.a \
		${INSTALL_TMP}/*.so \
		${PRESTAGE}/lib
	@${MV}	${INSTALL_TMP}/*.h ${PRESTAGE}/include
	@${MV}	${INSTALL_TMP}/afnipy ${PRESTAGE}/pylib
	@${CP}	${WRKDIR}/afni-AFNI_${PORTVERSION}/doc/README/* ${PRESTAGE}/doc
	@for binary in `${FILE} ${INSTALL_TMP}/* | fgrep 'ELF' | ${AWK} -F ':' ' { print $$1 }'` ; do \
		${MV} $${binary} ${PRESTAGE}/bin ; \
	done
	@${MV}	${INSTALL_TMP}/* ${PRESTAGE}/scripts

	# Install to STAGEDIR using proper ports tools
	@${MKDIR} \
		${STAGEDIR}${DATADIR} \
		${STAGEDIR}${PREFIX}/lib/afni \
		${STAGEDIR}${PREFIX}/include/afni \
		${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${PREFIX}/etc/mri
	${INSTALL_PROGRAM} ${PRESTAGE}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${PRESTAGE}/scripts/* ${STAGEDIR}${PREFIX}/bin
	(cd ${PRESTAGE}/pylib && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR})
	${INSTALL_DATA} ${PRESTAGE}/lib/* ${STAGEDIR}${PREFIX}/lib/afni
	${INSTALL_DATA} ${PRESTAGE}/include/* ${STAGEDIR}${PREFIX}/include/afni
	(cd ${PRESTAGE}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/afni.cshrc ${WRKDIR}/afni.profile \
		${STAGEDIR}${PREFIX}/etc/mri

do-install-DOCS-on:
	${INSTALL_DATA} ${PRESTAGE}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
