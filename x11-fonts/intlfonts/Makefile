# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intlfonts
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free X11 fonts for all characters that Emacs can handle

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf \
		mkfontdir:x11-fonts/mkfontdir \
		mkfontscale:x11-fonts/mkfontscale
RUN_DEPENDS=	type1inst:x11-fonts/p5-type1inst

OPTIONS_DEFINE=	DOCS

USE_XORG=	x11
PLIST_SUB+=	FONTSDIR=${FONTSDIR} T1_FONTSDIR=${T1_FONTSDIR} \
		TT_FONTSDIR=${TT_FONTSDIR}

NORMAL_FONTS=	Asian		\
		Chinese		\
		Ethiopic	\
		European	\
		Japanese	\
		Misc
BIG_FONTS=	Chinese.BIG	\
		European.BIG	\
		Japanese.BIG
SCALABLE_FONTS=	TrueType \
		Type1
FONTSDIR=	lib/X11/fonts/local
T1_FONTSDIR=	lib/X11/fonts/Type1
TT_FONTSDIR=	lib/X11/fonts/TrueType
PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL

do-build:
	cd ${WRKSRC}; \
	for dir in ${NORMAL_FONTS} ${BIG_FONTS}; do \
		for bdf in $$dir/*.bdf ; do \
			${ECHO_CMD} $$bdf; \
			pcf_gz=`${ECHO_CMD} $$bdf | ${SED} 's/.bdf$$/.pcf.gz/'`; \
			${CAT} $$bdf | bdftopcf | ${GZIP_CMD} \
				> $$pcf_gz; \
		done \
	done
	for f in INSTALL DEINSTALL; do \
		${SED} -e 's,%%FONTSDIR%%,${FONTSDIR},g' \
			-e 's,%%T1_FONTSDIR%%,${T1_FONTSDIR},g' \
			-e 's,%%TT_FONTSDIR%%,${TT_FONTSDIR},g' \
			-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
			< ${FILESDIR}/$${f}.tmpl > ${WRKDIR}/$${f}; \
	done


do-install:
.for d in ${FONTSDIR} ${T1_FONTSDIR} ${TT_FONTSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/$d
.endfor
	for dir in ${NORMAL_FONTS} ${BIG_FONTS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$dir/*.pcf.gz ${STAGEDIR}${PREFIX}/${FONTSDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/Type1/*.* ${STAGEDIR}${PREFIX}/${T1_FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/TrueType/*.ttf ${STAGEDIR}${PREFIX}/${TT_FONTSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/Emacs.ap ${WRKSRC}/NEWS \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
