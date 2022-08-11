PORTNAME=	intlfonts
PORTVERSION=	1.4.2
CATEGORIES=	x11-fonts
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	International X11 fixed fonts

LICENSE=	GPLv3+

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts

NO_ARCH=	yes

# Don't move to pkg-plist, must appear before @fcfontsdir from USES=fonts.
PLIST_FILES=	"@fontsdir ${FONTSDIR}/TrueType" \
		"@fontsdir ${FONTSDIR}/Type1"

FONTS=		Asian Chinese Chinese.X Ethiopic European European.BIG Japanese Japanese.BIG Japanese.X Misc
FONTS_ALIAS=	Asian Chinese European Japanese Japanese.X

do-build:
.for f in ${FONTS}
	for bdf in ${WRKSRC}/${f}/*.bdf ; do \
		${ECHO_CMD} $${bdf}; \
		${LOCALBASE}/bin/bdftopcf $${bdf} | ${GZIP_CMD} > $${bdf%.bdf}.pcf.gz; \
	done
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}/TrueType ${STAGEDIR}${FONTSDIR}/Type1
.for f in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f}/*.pcf.gz ${STAGEDIR}${FONTSDIR}
.endfor
.for f in ${FONTS_ALIAS}
	${CAT} ${WRKSRC}/${f}/fonts.alias >> ${STAGEDIR}${FONTSDIR}/fonts.alias
.endfor
	${INSTALL_DATA} ${WRKSRC}/TrueType/*.* ${STAGEDIR}${FONTSDIR}/TrueType
	${INSTALL_DATA} ${WRKSRC}/Type1/*.* ${STAGEDIR}${FONTSDIR}/Type1

.include <bsd.port.mk>
