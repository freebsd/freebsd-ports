# Created by: mi@aldan.algebra.com
# $FreeBSD$

PORTNAME=	koi8rPS
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	russian print
MASTER_SITES=	ftp://ftp.redcom.ru/pub/X/psfonts/ \
		ftp://ftp.kapella.gpi.ru/pub/cyrillic/psfonts/
DISTFILES=	gs-type1_koi8_fonts.tgz gs-type1_koi8_afm.tgz \
		XFree86-Type1_fonts.dir.scale.gz
EXTRACT_ONLY=

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Add Russian (KOI8) fonts to your PostScript fonts collection

DIST_SUBDIR=	koi8r-ps

.include <bsd.port.pre.mk>

.if !defined(FONTMAP)
FONTMAP!=	${SH} ${FILESDIR}/find-fontmap.sh 2>/dev/null || ${ECHO_CMD}
.endif

NO_WRKSUBDIR=	Yes

CPS_DIR=	${PREFIX}/share/koi8r-ps

do-extract:
	${MKDIR} ${WRKSRC}
	${GZIP_CMD} -d < ${DISTDIR}/${DIST_SUBDIR}/XFree86-Type1_fonts.dir.scale.gz \
		> ${WRKSRC}/XFree86-Type1_fonts.dir.scale

do-build:
	${GREP} -c koi8 ${WRKSRC}/XFree86-Type1_fonts.dir.scale \
		> ${WRKSRC}/fonts.dir
	${GREP} koi8 ${WRKSRC}/XFree86-Type1_fonts.dir.scale \
		>> ${WRKSRC}/fonts.dir

do-configure:
	${SED} 's=(\(.*\.pfb\))=\(${CPS_DIR}/\1\)=' \
		< ${FILESDIR}/Fontmap.diff > ${WRKSRC}/Fontmap.diff

do-install:
	${MKDIR} ${STAGEDIR}${CPS_DIR}
	${TAR} -C ${STAGEDIR}${CPS_DIR} -xzpf \
		${DISTDIR}/${DIST_SUBDIR}/gs-type1_koi8_fonts.tgz
	${TAR} -C ${STAGEDIR}${CPS_DIR} -xzpf \
		${DISTDIR}/${DIST_SUBDIR}/gs-type1_koi8_afm.tgz
.if !exists(${FONTMAP})
	#################################################################
	### You do not appear to have GhostScript installed. The file
	###	${CPS_DIR}/Fontmap.diff
	### needs to be merged into GhostScript's Fontmap -- usually
	### located in something like
	###	${PREFIX}/share/ghostscript/5.50/Fontmap
	### for GhostScript to use cyrillic fonts.
	#################################################################
.else
	@if ${GREP} -q ArialCyrMT-BoldItalic "${FONTMAP}" ; then \
		${ECHO} Apparently, Fontmap already lists this fonts. Ok. \
			You can always merge ${CPS_DIR}/Fontmap.diff into \
			${FONTMAP} manually. ; \
		else \
			${SETENV} SIMPLE_BACKUP_SUFFIX=.CyrPS VERSION_CONTROL= \
				${PATCH} "${FONTMAP}" ${WRKSRC}/Fontmap.diff ; \
			${RM} "${FONTMAP}".CyrPS ; \
	fi
.endif
	${ECHO_CMD} ${FONTMAP} > ${STAGEDIR}${CPS_DIR}/fontmap.path
	${INSTALL_DATA} ${WRKSRC}/Fontmap.diff ${STAGEDIR}${CPS_DIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${STAGEDIR}${CPS_DIR}
	${LN} -s fonts.dir ${STAGEDIR}${CPS_DIR}/fonts.scale

.include <bsd.port.post.mk>
