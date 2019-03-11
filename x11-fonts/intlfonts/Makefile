# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intlfonts
PORTVERSION=	1.2.1
PORTREVISION=	6
CATEGORIES=	x11-fonts
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free X11 fonts for all characters that Emacs can handle

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts
# Don't move to pkg-plist, must appear before @fcfontsdir from USES=fonts.
PLIST_FILES=	"@fontsdir ${FONTSDIR}/TrueType" \
		"@fontsdir ${FONTSDIR}/Type1"

OPTIONS_DEFINE=	DOCS

FONTS=		Asian		\
		Chinese		\
		Chinese.BIG	\
		Ethiopic	\
		European	\
		European.BIG	\
		Japanese	\
		Japanese.BIG	\
		Misc

do-build:
.for f in ${FONTS}
	for bdf in ${WRKSRC}/${f}/*.bdf ; do \
		${ECHO_CMD} $${bdf}; \
		${LOCALBASE}/bin/bdftopcf $${bdf} | ${GZIP_CMD} \
			> $${bdf%.bdf}.pcf.gz; \
	done
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
.for f in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f}/*.pcf.gz ${STAGEDIR}${FONTSDIR}
	[ ! -f ${WRKSRC}/${f}/fonts.alias ] || \
		${CAT} ${WRKSRC}/${f}/fonts.alias >> ${STAGEDIR}${FONTSDIR}/fonts.alias
.endfor
	@${MKDIR} ${STAGEDIR}${FONTSDIR}/TrueType
	${INSTALL_DATA} ${WRKSRC}/TrueType/*.* ${STAGEDIR}${FONTSDIR}/TrueType
	@${MKDIR} ${STAGEDIR}${FONTSDIR}/Type1
	${INSTALL_DATA} ${WRKSRC}/Type1/*.* ${STAGEDIR}${FONTSDIR}/Type1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/Emacs.ap ${WRKSRC}/NEWS \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
