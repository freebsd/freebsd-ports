# New ports collection makefile for: koi8rPS
# Date created:         22 July 1999
# Whom:                 mi@aldan.algebra.com
#
# $FreeBSD$
#

PORTNAME=	koi8rPS
PORTVERSION=	1.0
CATEGORIES=	russian print
MASTER_SITES=	ftp://ftp.redcom.ru/pub/X/psfonts/ \
		ftp://ftp.kapella.gpi.ru/pub/cyrillic/psfonts/
DISTFILES=	gs-type1_koi8_fonts.tgz gs-type1_koi8_afm.tgz \
		XFree86-Type1_fonts.dir.scale.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Add Russian (KOI8) fonts to your PostScript fonts collection

EXTRACT_ONLY=

DIST_SUBDIR=	koi8r-ps

.include <bsd.port.pre.mk>

.if !defined(FONTMAP)
FONTMAP!=	if which gs > /dev/null 2>&1 ; then \
			d=`gs -h  | awk '/^Search path:$$/ { nl=1; next } \
					nl { print $$3; exit }'`; \
			if [ -e $$d/Fontmap.GS ] ; then \
				${ECHO_CMD} $$d/Fontmap.GS; \
			elif [ -e $$d/Fontmap ] ; then \
				${ECHO_CMD} $$d/Fontmap \
			else \
				${ECHO_CMD} /nicht/ ; \
			fi; \
		else \
			${ECHO_CMD} /nicht/ ; \
		fi
.endif

NO_PACKAGE=	Nothing to build, configurations only
NO_WRKSUBDIR=	Yes

CPS_DIR=	${PREFIX}/share/koi8r-ps

do-extract:
	${MKDIR} ${WRKSRC}
	${GZIP_CMD} -d < ${DISTDIR}/${DIST_SUBDIR}/XFree86-Type1_fonts.dir.scale.gz \
		> ${WRKSRC}/XFree86-Type1_fonts.dir.scale

do-build:
	${ECHO_CMD} `${GREP} koi8 ${WRKSRC}/XFree86-Type1_fonts.dir.scale | wc -l` \
		> ${WRKSRC}/fonts.dir
	${GREP} koi8 ${WRKSRC}/XFree86-Type1_fonts.dir.scale \
		>> ${WRKSRC}/fonts.dir

do-configure:
	${SED} 's=(\(.*\.pfb\))=\(${CPS_DIR}/\1\)=' \
		< ${FILESDIR}/Fontmap.diff > ${WRKSRC}/Fontmap.diff

do-install:
	${MKDIR} ${CPS_DIR}
	${TAR} -C ${CPS_DIR} -xzpf \
		${DISTDIR}/${DIST_SUBDIR}/gs-type1_koi8_fonts.tgz
	${TAR} -C ${CPS_DIR} -xzpf \
		${DISTDIR}/${DIST_SUBDIR}/gs-type1_koi8_afm.tgz
.if ${FONTMAP} == "/nicht/"
	#################################################################
	### You do not appear to have GhostScript installed. The file
	###	${CPS_DIR}/Fontmap.diff
	### needs to be merged into GhostScript's Fontmap -- usually
	### located in something like
	###	${PREFIX}/share/ghostscript/5.50/Fontmap
	### for GhostScript to use cyrillic fonts.
	#################################################################
	@test -t 0 && test -t 1 && ${ECHO} -n "Press enter" && read junk || ${TRUE}
.else
	@if ${GREP} -q ArialCyrMT-BoldItalic "${FONTMAP}" ; then \
		${ECHO} Apparently, Fontmap already lists this fonts. Ok. \
			You can always merge ${CPS_DIR}/Fontmap.diff into \
			${FONTMAP} manually. ; \
		else \
			${SETENV} SIMPLE_BACKUP_SUFFIX=.CyrPS VERSION_CONTROL= \
				${PATCH} "${FONTMAP}" ${WRKSRC}/Fontmap.diff ; \
			${RM} -f "${FONTMAP}".CyrPS ; \
	fi
.endif
	${ECHO_CMD} ${FONTMAP} > ${CPS_DIR}/fontmap.path
	${INSTALL_DATA} ${WRKSRC}/Fontmap.diff ${CPS_DIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${CPS_DIR}
	${LN} -s fonts.dir ${CPS_DIR}/fonts.scale
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
