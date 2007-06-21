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
PORTVERSION=	2007.06.15.1339
CATEGORIES=	science biology graphics
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/AFNI/${PORTVERSION}/ \
		http://afni.nimh.nih.gov/pub/dist/tgz/
DISTFILES=	afni_src.tgz afni.1 \
		TTatlas+tlrc.BRIK.gz TTatlas+tlrc.HEAD CA_EZ_v1.3c-May0806.tgz
DIST_SUBDIR=	AFNI-${PORTVERSION}
EXTRACT_ONLY=	afni_src.tgz CA_EZ_v1.3c-May0806.tgz

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Advanced Functional Neuro Imaging

RUN_DEPENDS=	cjpeg:${PORTSDIR}/graphics/jpeg \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		whirlgif:${PORTSDIR}/graphics/whirlgif \
		ppmtogif:${PORTSDIR}/graphics/netpbm \
		endian:${PORTSDIR}/sysutils/endian

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not compile on sparc64: "undefined reference to '_mcount'"
.endif

USE_GL=		glw glu
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_MOTIF=	yes
MAKE_ENV=	CC="${CC}"

WRKSRC=		${WRKDIR}/afni_src
MAKEFILE=	Makefile.FreeBSD_PORT
ALL_TARGET=	vastness suma

###########################################################################
# Install parameters

MAN1=	afni.1

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
		SUMA/SUMA_StripPath.c \
		SUMA/GLUT/libglut/glut_event.c \
		SUMA/SUMA_Surface_IO.c

post-extract:
	@${CP} -f ${FILESDIR}/Makefile.FreeBSD_PORT ${WRKSRC}
.for f in ${X11R6_FILES}
	@${REINPLACE_CMD} -e 's|/usr/X11R6|$${X11BASE}|g' ${WRKSRC}/${f}
.endfor
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/afni.1 ${WRKDIR}
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
	${MV}	${INSTALL_WRKSRC}/*.jpg \
		${INSTALL_WRKSRC}/*.txt \
		${INSTALL_WRKSRC}/AFNI.*rc \
		${STAGE}/share
	${MV}	${INSTALL_WRKSRC}/*.h \
		${STAGE}/include
	${MV}	${INSTALL_WRKSRC}/README* \
		${STAGE}/doc
	${MV}	${INSTALL_WRKSRC}/abut ${INSTALL_WRKSRC}/afni_abut
	for binary in `${FILE} ${INSTALL_WRKSRC}/* | fgrep 'ELF' | ${AWK} -F ':' ' { print $$1 }'` ; do \
		${MV} $${binary} ${STAGE}/bin ; \
	done
	${MV}	${INSTALL_WRKSRC}/* \
		${STAGE}/scripts

do-install:
	${MKDIR} ${DATADIR} ${PREFIX}/lib/afni ${PREFIX}/include/afni
	${INSTALL_DATA} ${STAGE}/lib/* ${PREFIX}/lib/afni
	${INSTALL_DATA} ${STAGE}/include/* ${PREFIX}/include/afni
	${INSTALL_DATA} ${STAGE}/share/* ${DATADIR}
	${INSTALL_PROGRAM} ${STAGE}/bin/* ${PREFIX}/bin
	${INSTALL_SCRIPT} ${STAGE}/scripts/* ${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/TTatlas* ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/CA_EZ_v1.3c-May0806/* ${DATADIR}
	${INSTALL_MAN} ${WRKDIR}/afni.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${STAGE}/doc/* ${DOCSDIR}
.endif

post-install:
	@${CAT} pkg-message

.include <bsd.port.post.mk>
