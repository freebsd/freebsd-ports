# Created by: giffunip
# $FreeBSD$

PORTNAME=	gsfonts
PORTVERSION=	8.11
PORTREVISION=	8
CATEGORIES=	print x11-fonts
MASTER_SITES=	SF/gs-fonts/gs-fonts/${PORTVERSION}%20%28base%2035%2C%20GPL%29/:std \
		SF/gs-fonts/gs-fonts/6.0%20%28misc%2C%20GPL%29/:other
DISTFILES=	ghostscript-fonts-std-${PORTVERSION}${EXTRACT_SUFX}:std \
		gnu-gs-fonts-other-6.0${EXTRACT_SUFX}:other
DIST_SUBDIR=	ghostscript

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Standard Fonts for Ghostscript

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/fonts/COPYING

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${STAGEDIR}${PREFIX}/||}"
OPTIONS_DEFINE=	DOCS

FONTSDIR=	${STAGEDIR}${PREFIX}/share/ghostscript/fonts
CJKFONTS?=	std.ja_JP/Ryumin-Light \
		std.ja_JP/GothicBBB-Medium \
		std.ja_JP/Ryumin-Light.gs7 \
		std.ja_JP/GothicBBB-Medium.gs7 \
		std.zh_CN/STHeiti-Regular \
		std.zh_CN/STSong-Light \
		std.zh_CN/MSung-Light

PORTDOCS=	ChangeLog README README.tweaks TODO

do-install:
	${MKDIR} ${FONTSDIR}
	cd ${WRKSRC}/fonts && \
		${INSTALL_DATA} fonts.dir \
			*.afm *.gsf *.pfa *.pfb *.pfm ${FONTSDIR}/ \
		&& ${INSTALL_DATA} fonts.scale ${FONTSDIR}/fonts.scale.urw
	cd ${FILESDIR} && \
		${INSTALL_DATA} fonts.scale Fontmap ${FONTSDIR}/
	for F in ${CJKFONTS}; do \
		${LN} -s -f ${PREFIX}/share/fonts/$${F} ${FONTSDIR}/; \
	done

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/fonts && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
