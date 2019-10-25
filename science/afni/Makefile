# $FreeBSD$

PORTNAME=		afni
DISTVERSIONPREFIX=	AFNI_
DISTVERSION=		19.1.20
PORTREVISION=	4
CATEGORIES=		science biology graphics perl5 python

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Advanced Functional Neuro Imaging

LICENSE=	GPLv2

BROKEN_sparc64=	Does not compile: "undefined reference to '_mcount'"

BUILD_DEPENDS=	gm4:devel/m4 \
		R:math/R
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libf2c.so:lang/f2c \
		libgsl.so:math/gsl \
		libnetcdff.so:science/netcdf-fortran \
		libxml2.so:textproc/libxml2 \
		libXm.so:x11-toolkits/open-motif \
		libnetpbm.so:graphics/netpbm
RUN_DEPENDS=	endian:sysutils/endian \
		mpeg_encode:multimedia/mpeg_encode \
		qhull:math/qhull5 \
		R:math/R

USES=		compiler:openmp gettext gl gmake gnome iconv jpeg:run motif \
		perl5 python shebangfix tar:xz xorg
USE_GNOME=	glib20
USE_GITHUB=	yes

SHEBANG_FILES=	scripts_install/* \
		python_scripts/afni_python/*.py \
		jzosky/*.py \
		jzosky/lib_RetroTS/*.py \
		discoraj/ClusterExplorer/*.py \
		roopchansinghv/PsychoPy-NeuroFeedback-Demo/*.py \
		roopchansinghv/PsychoPy-NeuroFeedback-Demo/*/*.py \
		pkundu/*.py \
		pkundu/meica.libs/*.py \
		pkundu/meica.libs/*/*.py \
		pkundu/meica.libs/*/*/*.py

USE_GL=		gl glu
USE_XORG=	x11 xext xi xmu xt
MAKE_ENV=	CC="${CC}" R_SHARE_DIR=${LOCALBASE}/lib/R/share
MAKE_JOBS_UNSAFE=yes

WRKSRC_SUBDIR=	src
ALL_TARGET=	vastness suma

###########################################################################
# Install parameters

SUB_FILES=	pkg-message afni.cshrc afni.profile

INSTALL_WRKSRC=	${WRKSRC}/BSD
INSTALL_TMP=	${INSTALL_WRKSRC}-temp
PRESTAGE=	${WRKSRC}/prestage

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

CONFLICTS=	im-[0-9]* \
		nifticlib-[0-9]* \
		open-usp-tukubai-[0-9]*

X11R6_FILES=	coxplot/Makefile \
		coxplot/Makefile.f2c \
		3DEdge/src/Makefile \
		SUMA/SUMA_Makefile \
		edt_blur.c \
		suma_datasets.c \
		SUMA/SUMA_Load_Surface_Object.c \
		SUMA/SUMA_MiscFunc.c \
		SUMA/SUMA_ParseCommands.c \
		SUMA/GLUT/libglut/glut_event.c \
		SUMA/SUMA_Surface_IO.c

post-extract:
.for f in ${X11R6_FILES}
	@${REINPLACE_CMD} \
		-e 's|/usr/X11R6|$${LOCALBASE}|g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} \
		-E 's|AFNI_[0-9_]+|${PORTVERSION}|g' ${WRKSRC}/AFNI_label.h
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}
	@${RM} ${WRKSRC}/3DEdge/src/Makefile.orig

# shebangfix misses /bin/python on 10.1
#	@${REINPLACE_CMD} -e "s|/bin/python|${PYTHON_CMD}|g" \
#		${WRKSRC}/python_scripts/afni_python/lib_fat_Rfactor.py

pre-configure:
	@${REINPLACE_CMD} -e "s|-lglib|-lglib-2.0|g" \
		${WRKSRC}/SUMA/SUMA_Makefile
	@${REINPLACE_CMD} \
		-e 's|os\.path\.dirname(sys\.argv\[0\])|"${DATADIR}"|g' \
		${WRKSRC}/pkundu/meica.py
	@${REINPLACE_CMD} \
		-e 's|g_info|afni_g_info|g' \
		${WRKSRC}/rickr/Dimon.c \
		${WRKSRC}/rickr/Dimon1.c \
		${WRKSRC}/afni_history_rickr.c \
		${WRKSRC}/mri_dicom_stuff.c \
		${WRKSRC}/mri_process_siemens.c \
		${WRKSRC}/mri_read_dicom.c \
		${WRKSRC}/to3d.c \
		${WRKSRC}/mri_dicom_stuff.h

do-install:
	# AFNI install just dumps everything into one flat directory
	# Preserve original install dir and make a sacrificial temp copy
	# to be pruned and rearranged for easy staging
	@${RM} -r ${INSTALL_TMP}
	@${CP} -R ${INSTALL_WRKSRC} ${INSTALL_TMP}

	# Clean up and organize files into ${PRESTAGE}, destroying
	# temp copy in the process
	@${RM} -rf ${PRESTAGE}
	@${MKDIR} ${PRESTAGE}/bin \
		${PRESTAGE}/scripts \
		${PRESTAGE}/lib \
		${PRESTAGE}/include \
		${PRESTAGE}/trash \
		${PRESTAGE}/doc \
		${PRESTAGE}/share
	@${RM}	${INSTALL_TMP}/libf2c.a
	@${MV}	${INSTALL_TMP}/meica.libs \
		${INSTALL_TMP}/shiny \
		${INSTALL_TMP}/lib_RetroTS \
		${INSTALL_TMP}/afniInterfaceRT \
		${INSTALL_TMP}/funstuff \
		${INSTALL_TMP}/AFNI.*rc \
		${INSTALL_TMP}/afnigui* \
		${PRESTAGE}/share
	@${MV}	${INSTALL_TMP}/*.a \
		${INSTALL_TMP}/*.so \
		${PRESTAGE}/lib
	@${MV}	${INSTALL_TMP}/*.h ${PRESTAGE}/include
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
	${INSTALL_DATA} ${PRESTAGE}/lib/* ${STAGEDIR}${PREFIX}/lib/afni
	${INSTALL_DATA} ${PRESTAGE}/include/* ${STAGEDIR}${PREFIX}/include/afni
	(cd ${PRESTAGE}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/afni.cshrc ${WRKDIR}/afni.profile \
		${STAGEDIR}${PREFIX}/etc/mri

do-install-DOCS-on:
	${INSTALL_DATA} ${PRESTAGE}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
