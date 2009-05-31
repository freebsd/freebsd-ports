# New ports collection makefile for:	gsfonts
# Date created:		11 September 1997
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	gsfonts
PORTVERSION=	8.11
PORTREVISION=	5
CATEGORIES=	print x11-fonts
MASTER_SITES=	ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/fonts/ \
		${MASTER_SITE_TEX_CTAN:S/$/:CTAN/}
MASTER_SITE_SUBDIR=	support/ghostscript/fonts/:CTAN
DISTFILES=	${GS_FONTS_STD:S/$/:DEFAULT,CTAN/} ${GS_FONTS_OTHER:S/$/:DEFAULT,CTAN/}
DIST_SUBDIR=	ghostscript

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Standard Fonts for Ghostscript

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

PORTDOCS=	ChangeLog README README.tweaks TODO

FONTSDIR=	${PREFIX}/share/ghostscript/fonts
GS_FONTS_STD=	ghostscript-fonts-std-8.11.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-6.0.tar.gz
CJKFONTS?=	std.ja_JP/Ryumin-Light \
		std.ja_JP/GothicBBB-Medium \
		std.zh_CN/STHeiti-Regular \
		std.zh_CN/STSong-Light \
		std.zh_CN/MSung-Light

do-install:
	${MKDIR} ${FONTSDIR}
	cd ${WRKSRC}/fonts && \
		${INSTALL_DATA} fonts.dir COPYING \
			*.afm *.gsf *.pfa *.pfb *.pfm ${FONTSDIR}/ \
		&& ${INSTALL_DATA} fonts.scale ${FONTSDIR}/fonts.scale.urw
	cd ${FILESDIR} && \
		${INSTALL_DATA} fonts.scale Fontmap ${FONTSDIR}/
	for F in ${CJKFONTS}; do \
		${LN} -s -f ${PREFIX}/share/fonts/$${F} ${FONTSDIR}/; \
	done

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/fonts && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
