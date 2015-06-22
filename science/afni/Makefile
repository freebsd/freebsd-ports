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
PORTREVISION=	12
CATEGORIES=	science biology graphics
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/AFNI/${PORTVERSION}/ \
		http://www.acadix.biz/Ports/distfiles/AFNI/${PORTVERSION}/
DISTFILES=	afni_src.tgz afni.1 3dClustBust.c \
		TTatlas+tlrc.BRIK.gz TTatlas+tlrc.HEAD CA_EZ_v1.5-July3107.tgz
DIST_SUBDIR=	AFNI-${PORTVERSION}
EXTRACT_ONLY=	afni_src.tgz CA_EZ_v1.5-July3107.tgz

MAINTAINER=	jwbacon@tds.net
COMMENT=	Advanced Functional Neuro Imaging

LICENSE=	GPLv2

LIB_DEPENDS=	libXm.so:${PORTSDIR}/x11-toolkits/open-motif \
		libR.so:${PORTSDIR}/math/R \
		libgsl.so:${PORTSDIR}/math/gsl \
		libnetcdff.so:${PORTSDIR}/science/netcdf-fortran
RUN_DEPENDS=	mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		whirlgif:${PORTSDIR}/graphics/whirlgif \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		endian:${PORTSDIR}/sysutils/endian \
		qhull:${PORTSDIR}/math/qhull5

CONFLICTS=	im-[0-9]* \
		nifticlib-[0-9]* \
		open-usp-tukubai-[0-9]*

USES=		gettext iconv jpeg:run gmake motif perl5 shebangfix
SHEBANG_FILES=	suma_change_spec 3dPAR2AFNI.pl

# Some prereqs use gcc anyway
USE_GCC=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

BROKEN_sparc64=	Does not compile: "undefined reference to '_mcount'"

USE_GL=		glw glu
USE_XORG=	xi
MAKE_ENV=	CC="${CC}"
MAKE_JOBS_UNSAFE=yes

WRKSRC=		${WRKDIR}/afni_src
ALL_TARGET=	vastness suma

###########################################################################
# Install parameters

SUB_FILES=	pkg-message afni.cshrc afni.profile

INSTALL_WRKSRC=	${WRKSRC}/BSD
PRESTAGE=	${WRKSRC}/prestage

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
	${MKDIR} ${PRESTAGE}/bin \
		${PRESTAGE}/scripts \
		${PRESTAGE}/lib \
		${PRESTAGE}/include \
		${PRESTAGE}/trash \
		${PRESTAGE}/doc \
		${PRESTAGE}/share
	${MV}	${INSTALL_WRKSRC}/libf2c.a \
		${PRESTAGE}/trash
	${MV}	${INSTALL_WRKSRC}/*.a \
		${INSTALL_WRKSRC}/*.so \
		${PRESTAGE}/lib
	${MV}	${INSTALL_WRKSRC}/funstuff \
		${INSTALL_WRKSRC}/AFNI.*rc \
		${INSTALL_WRKSRC}/afnigui* \
		${PRESTAGE}/share
	${MV}	${INSTALL_WRKSRC}/*.h \
		${PRESTAGE}/include
	${MV}	${INSTALL_WRKSRC}/README* \
		${PRESTAGE}/doc
	${MV}	${INSTALL_WRKSRC}/abut ${INSTALL_WRKSRC}/afni_abut
	for binary in `${FILE} ${INSTALL_WRKSRC}/* | fgrep 'ELF' | ${AWK} -F ':' ' { print $$1 }'` ; do \
		${MV} $${binary} ${PRESTAGE}/bin ; \
	done
	${MV}	${INSTALL_WRKSRC}/* \
		${PRESTAGE}/scripts

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} \
		${STAGEDIR}${PREFIX}/lib/afni \
		${STAGEDIR}${PREFIX}/include/afni
	${INSTALL_DATA} ${PRESTAGE}/lib/* ${STAGEDIR}${PREFIX}/lib/afni
	${INSTALL_DATA} ${PRESTAGE}/include/* ${STAGEDIR}${PREFIX}/include/afni
	${CP} -R ${PRESTAGE}/share/* ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${PRESTAGE}/bin/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${PRESTAGE}/scripts/* ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/TTatlas* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/CA_EZ_v1.5-July3107/* ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/afni.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${PREFIX}/etc/mri
	${INSTALL_DATA} ${PRESTAGE}/doc/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/afni.cshrc ${WRKDIR}/afni.profile \
		${STAGEDIR}${PREFIX}/etc/mri
.endif

.include <bsd.port.mk>
