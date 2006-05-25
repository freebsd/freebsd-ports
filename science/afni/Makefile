############################################################################
# Ports collection Makefile for:   afni
# Date created:        11 Jan 2005
# Whom:                bacon@smithers.neuro.mcw.edu
#
# $FreeBSD$
#

############################################################################
# www.neuro.mcw.edu has the latest source distribution from which this port
# is built.  It will be updated as time permits.
#
# afni.nimh.nih.gov is the ultimate source for AFNI, and will always
# contain the latest source release.  If this port is not up to date,
# you can download the latest sources and build manually using
# Makefile.BSD, which is included in the source distribution.

PORTNAME=	afni
PORTVERSION=	2006.03.21.1314
CATEGORIES=	science biology graphics
MASTER_SITES=	http://afni.nimh.nih.gov/pub/dist/tgz/ \
		http://www.neuro.mcw.edu/~bacon/Ports/distfiles/AFNI/${PORTVERSION}/
DISTFILES=	afni_src.tgz afni_doc.tgz afni.1 Makefile.FreeBSD_PORT \
		TTatlas+tlrc.BRIK.gz TTatlas+tlrc.HEAD CA_EZ_v1.3b-Mar1506.tgz
DIST_SUBDIR=	AFNI-${PORTVERSION}
EXTRACT_ONLY=	afni_src.tgz afni_doc.tgz CA_EZ_v1.3b-Mar1506.tgz

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Advanced Functional Neuro Imaging

RUN_DEPENDS=	cjpeg:${PORTSDIR}/graphics/jpeg \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		whirlgif:${PORTSDIR}/graphics/whirlgif \
		ppmtogif:${PORTSDIR}/graphics/netpbm

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not compile on sparc64: "undefined reference to `_mcount'"
.endif

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_MOTIF=	yes
MAKE_ENV=	CC="${CC}"

WRKSRC=		${WRKDIR}/afni_src
MAKEFILE=	Makefile.FreeBSD_PORT
ALL_TARGET=	vastness suma

SUB_FILES=	pkg-message

###########################################################################
# Install parameters

MAN1=	afni.1

# these need not to be stripped
SCRIPTS=\
	@2dwarper \
	@4Daverage \
	@AfniOrient2RAImap \
	@AfniOrientSign \
	@Align_Centers \
	@Center_Distance \
	@CheckForAfniDset \
	@CommandGlobb \
	@DTI_studio_reposition \
	@FromRAI \
	@GetAfniOrient \
	@GetAfniPrefix \
	@GetAfniView \
	@IsoMasks \
	@NoExt \
	@Purify_1D \
	@RenamePanga \
	@SUMA_AlignToExperiment \
	@SUMA_Make_Spec_FS \
	@SUMA_Make_Spec_SF \
	@ToRAI \
	@UpdateAfni \
	@VolCenter \
	@align_partial_oblique \
	@auto_align \
	@auto_tlrc \
	@clip_volume \
	@fix_FSsphere \
	@make_stim_file \
	@np \
	@parse_afni_name \
	@parse_name \
	3dMax \
	suma_change_spec

PLIST_FILES+=	${SCRIPTS:S|^|bin/|}

INSTALL_WRKSRC=	${WRKSRC}/BSD
INSTALL_TEMP=	${WRKSRC}/Backup.BSD

post-extract:
	${CP} -f ${DISTDIR}/${DIST_SUBDIR}/Makefile.FreeBSD_PORT ${WRKSRC}

do-install:
	${MKDIR} ${DATADIR} ${INSTALL_TEMP}
	@${MV} ${INSTALL_WRKSRC}/libf2c.a ${INSTALL_TEMP}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/*.so ${INSTALL_WRKSRC}/*.a \
		${PREFIX}/lib
	${INSTALL_DATA} ${INSTALL_WRKSRC}/*.h \
		${PREFIX}/include
	${INSTALL_DATA} ${INSTALL_WRKSRC}/*.jpg ${INSTALL_WRKSRC}/*.txt \
		${DATADIR}
	@${MV}	${INSTALL_WRKSRC}/*.so \
		${INSTALL_WRKSRC}/*.a \
		${INSTALL_WRKSRC}/*.h \
		${INSTALL_WRKSRC}/*.jpg \
		${INSTALL_WRKSRC}/*.txt \
	 	${INSTALL_WRKSRC}/cjpeg \
		${INSTALL_WRKSRC}/djpeg \
		${INSTALL_WRKSRC}/mpeg_encode \
		${INSTALL_WRKSRC}/whirlgif \
		${INSTALL_TEMP}
.for f in ${SCRIPTS}
		${INSTALL_SCRIPT} ${INSTALL_WRKSRC}/${f} ${PREFIX}/bin
		@${MV} ${INSTALL_WRKSRC}/${f} ${INSTALL_TEMP}
.endfor
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/* ${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/TTatlas* ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/CA_EZ_v1.3b-Mar1506/* ${DATADIR}
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/afni.1 ${PREFIX}/man/man1
	@${MV} ${INSTALL_TEMP}/* ${INSTALL_WRKSRC}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/afni_doc/* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
