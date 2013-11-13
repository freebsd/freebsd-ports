# Created by: Jason W. Bacon <jwbacon@tds.net>
# $FreeBSD$

############################################################################
# http://www.neuro.mcw.edu/Ports has the latest source distribution from
#  which this port is built.  It will be updated as time permits.
#
# afni.nimh.nih.gov is the ultimate source for AFNI, and will always
# contain the latest source release.  If this port is not up to date,
# you can download the latest sources and build manually.

PORTNAME=	afni
PORTVERSION=	2012.04.17.2129
PORTREVISION=	6
CATEGORIES=	science biology graphics
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/AFNI/${PORTVERSION}/ \
		http://www.acadix.biz/Ports/distfiles/AFNI/${PORTVERSION}/
DISTFILES=	afni_src.tgz afni.1 3dClustBust.c \
		TTatlas+tlrc.BRIK.gz TTatlas+tlrc.HEAD CA_EZ_v1.5-July3107.tgz
DIST_SUBDIR=	AFNI-${PORTVERSION}
EXTRACT_ONLY=	afni_src.tgz CA_EZ_v1.5-July3107.tgz

MAINTAINER=	jwbacon@tds.net
COMMENT=	Advanced Functional Neuro Imaging

LIB_DEPENDS=	R:${PORTSDIR}/math/R \
		gsl:${PORTSDIR}/math/gsl
RUN_DEPENDS=	cjpeg:${PORTSDIR}/graphics/jpeg \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		whirlgif:${PORTSDIR}/graphics/whirlgif \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		endian:${PORTSDIR}/sysutils/endian

USES=		gettext iconv gmake motif

NO_STAGE=	yes
BROKEN=	R_io.so fails to build with R-3.0.2

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not compile on sparc64: "undefined reference to '_mcount'"
.endif

USE_GL=		glw glu
USE_XORG=	xi
MAKE_ENV=	CC="${CC}"
MAKE_JOBS_UNSAFE=yes

WRKSRC=		${WRKDIR}/afni_src
ALL_TARGET=	vastness suma

###########################################################################
# Install parameters

MAN1=		afni.1

SUB_FILES=	pkg-message afni.cshrc afni.profile

INSTALL_WRKSRC=	${WRKSRC}/BSD
STAGE=		${WRKSRC}/stage

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
	@${CP} -f ${FILESDIR}/Makefile.FreeBSD_PORT ${WRKSRC}/Makefile
.for f in ${X11R6_FILES}
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${LOCALBASE}|g' ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -E 's|AFNI_[0-9_]+|${PORTVERSION}|g' ${WRKSRC}/AFNI_label.h
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/afni.1 ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/3dClustBust.c ${WRKSRC}
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKDIR}/afni.1

post-build:
	${MKDIR} ${STAGE}/bin \
		${STAGE}/scripts \
		${STAGE}/lib \
		${STAGE}/include \
		${STAGE}/trash \
		${STAGE}/doc \
		${STAGE}/share
	${MV}	${INSTALL_WRKSRC}/libf2c.a \
		${STAGE}/trash
	${MV}	${INSTALL_WRKSRC}/*.a \
		${INSTALL_WRKSRC}/*.so \
		${STAGE}/lib
	${MV}	${INSTALL_WRKSRC}/funstuff \
		${INSTALL_WRKSRC}/AFNI.*rc \
		${INSTALL_WRKSRC}/afnigui* \
		${STAGE}/share
	${MV}	${INSTALL_WRKSRC}/*.h \
		${STAGE}/include
	${MV}	${INSTALL_WRKSRC}/README* \
		${STAGE}/doc
	${MV}	${INSTALL_WRKSRC}/abut ${INSTALL_WRKSRC}/afni_abut
	${MV}	${INSTALL_WRKSRC}/qhull ${INSTALL_WRKSRC}/afni_qhull
	for binary in `${FILE} ${INSTALL_WRKSRC}/* | fgrep 'ELF' | ${AWK} -F ':' ' { print $$1 }'` ; do \
		${MV} $${binary} ${STAGE}/bin ; \
	done
	${MV}	${INSTALL_WRKSRC}/* \
		${STAGE}/scripts

do-install:
	${MKDIR} ${DATADIR} ${PREFIX}/lib/afni ${PREFIX}/include/afni
	${INSTALL_DATA} ${STAGE}/lib/* ${PREFIX}/lib/afni
	${INSTALL_DATA} ${STAGE}/include/* ${PREFIX}/include/afni
	${CP} -R ${STAGE}/share/* ${DATADIR}
	${INSTALL_PROGRAM} ${STAGE}/bin/* ${PREFIX}/bin
	${INSTALL_SCRIPT} ${STAGE}/scripts/* ${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/TTatlas* ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/CA_EZ_v1.5-July3107/* ${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/afni.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${PREFIX}/etc/mri
	${INSTALL_DATA} ${STAGE}/doc/* ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/afni.cshrc ${WRKDIR}/afni.profile \
		${PREFIX}/etc/mri
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
