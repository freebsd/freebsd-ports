# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mplayer-skins
PORTVERSION=	1.1.3
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	MPLAYERHQ/skins
DISTFILES=	# filled in later after options
DIST_SUBDIR=	mplayer-skins

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	Skins for MPlayer's Graphical User Interface (GUI)

#
# When adding a new skin, please make sure to add it into the following
# Makefiles:
# - Makefile.skins
# - Makefile.options
#
# Then do "make config", select "All Skins" and run "make makesum".
#

USES=		tar:bzip2
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

NO_ARCH=	yes

.include "${.CURDIR}/Makefile.options"

.include <bsd.port.pre.mk>

.include "${.CURDIR}/Makefile.skins"

myDATADIR=	share/${PORTNAME:S/-skins//}/skins
myWRKSRC=		${WRKSRC}/skins

post-extract:
	@${FIND} ${WRKSRC} -type d \( -name '.svn' \) -delete
	@${MKDIR} ${myWRKSRC}
	@for dir in `cd ${WRKSRC} && ${FIND} . -type d ! -name ".*" ! -name "skins" -maxdepth 1` ; do \
		${MV} ${WRKSRC}/$${dir#./} ${myWRKSRC}; \
	done

pre-build:
.if ${PORT_OPTIONS:MALL}
PORT_OPTIONS+=	${ALLSKINS}
.endif

post-build-script:
DISTFILES+=	${DEFAULT_FILE}${EXTRACT_SUFX}
.for f in ${ALLSKINS}
.if ${PORT_OPTIONS:M${f}}
PLIST_SUB+=	${f}="" WITHOUT_SKIN_${f}="@comment "
DISTFILES+=	${${f}_FILE}${EXTRACT_SUFX}
.else
PLIST_SUB+=	${f}="@comment " WITHOUT_SKIN_${f}=""
.endif
.endfor

do-install:
# both anotate and create target directories
	@for dir in `cd ${myWRKSRC} && ${FIND} . -type d | ${SORT} -r` ; do \
		${MKDIR} "${STAGEDIR}${PREFIX}/${myDATADIR}/$${dir#./}" ; \
	done
# both anotate installed and install files
	@for f in `cd ${myWRKSRC} && ${FIND} . -type f | ${SORT}` ; do \
		${INSTALL_DATA} "${myWRKSRC}/$${f#./}" ${STAGEDIR}${PREFIX}/${myDATADIR}/$${f#./} ; \
	done
# Create link to the default skin
	@${LN} -sfh Blue ${STAGEDIR}${PREFIX}/${myDATADIR}/default

.include <bsd.port.post.mk>
