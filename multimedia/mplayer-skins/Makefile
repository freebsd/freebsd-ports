# New ports collection makefile for:	mplayer gui skins
# Date created:				Sat Jan 12 10:59:45 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayer-skins
PORTVERSION=	1.1.3
PORTREVISION=	0
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/skins/ \
		http://www4.mplayerhq.hu/MPlayer/skins/ \
		http://www5.mplayerhq.hu/MPlayer/skins/ \
		ftp://ftp.mplayerhq.hu/MPlayer/skins/ \
		ftp://ftp4.mplayerhq.hu/MPlayer/skins/ \
		ftp://ftp5.mplayerhq.hu/MPlayer/skins/
DISTFILES=	# filled in later after options
DIST_SUBDIR=	mplayer-skins

MAINTAINER=	thomas.e.zander@googlemail.com
COMMENT=	Skins for MPlayer's Graphical User Interface (GUI)

#
# When adding a new skin, please make sure to add it into the following
# Makefiles:
# - Makefile.skins
# - Makefile.options
#
# Then do "make config", select "All Skins" and run "make makesum".
#

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.include "${.CURDIR}/Makefile.options"

.include <bsd.port.pre.mk>

.include "${.CURDIR}/Makefile.skins"

myDATADIR=	share/${PORTNAME:S/-skins//}/skins
# Used by other ports to detect if this is installed
DETECTION_FILE=	${LOCALBASE}/${myDATADIR}/${PKGNAME}

PLIST_SUB+=	PKGNAME="${PKGNAME}"

post-extract:
	@${FIND} ${WRKSRC} -type d \( -name '.svn' \) -delete

pre-build:
# Build and install all skins (rather expensive)
.if (defined(BATCH) && !defined(_OPTIONS_READ)) || defined(WITH_SKIN_ALL)
.for f in ${ALLSKINS}
WITH_SKIN_${f}=	yes
.endfor
.endif # WITH_SKIN_ALL

post-build-script:
.for f in ${ALLSKINS}
.ifdef(WITH_SKIN_${f})
PLIST_SUB+=	${f}="" WITHOUT_SKIN_${f}="@comment "
HAVE_SKIN=	true
DISTFILES+=	${${f}_FILE}${EXTRACT_SUFX}
.else
PLIST_SUB+=	${f}="@comment " WITHOUT_SKIN_${f}=""
.endif
.endfor
.if !defined(HAVE_SKIN)
IGNORE=	no skin selected
.endif

do-install:
# both anotate and create target directories
	@for dir in `cd ${WRKDIR} && ${FIND} . -type d ! -name ".*" | ${SORT} -r` ; do \
		${MKDIR} "${PREFIX}/${myDATADIR}/$${dir#./}" ; \
		LAST_DIR="$${dir#./}"; \
	done && \
	${LN} -sfh "${PREFIX}/${myDATADIR}/$${LAST_DIR#./}" "${PREFIX}/${myDATADIR}/default"
.ifdef(WITH_SKIN_DEFAULT)
	@${LN} -sfh "${PREFIX}/${myDATADIR}/Blue" "${PREFIX}/${myDATADIR}/default"
.endif
# both anotate installed and install files
	@for f in `cd ${WRKDIR} && ${FIND} . -type f ! -name ".*" | ${SORT}` ; do \
		${INSTALL_DATA} "${WRKDIR}/$${f#./}" ${PREFIX}/${myDATADIR}/$${f#./} ; \
	done
# add marker file
	@${TOUCH} ${PREFIX}/${myDATADIR}/${PKGNAME}

.include <bsd.port.post.mk>
