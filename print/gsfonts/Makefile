# Created by: giffunip
# $FreeBSD$

PORTNAME=	gsfonts
PORTVERSION=	8.11
PORTREVISION=	6
CATEGORIES=	print x11-fonts
MASTER_SITES=	SF/gs-fonts/gs-fonts/${PORTVERSION}%20%28base%2035%2C%20GPL%29/:std \
		SF/gs-fonts/gs-fonts/6.0%20%28misc%2C%20GPL%29/:other
DISTFILES=	ghostscript-fonts-std-${PORTVERSION}${EXTRACT_SUFX}:std \
		gnu-gs-fonts-other-6.0${EXTRACT_SUFX}:other
DIST_SUBDIR=	ghostscript

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Standard Fonts for Ghostscript

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
OPTIONS_DEFINE=	DOCS

FONTSDIR=	${PREFIX}/share/ghostscript/fonts
CJKFONTS?=	std.ja_JP/Ryumin-Light \
		std.ja_JP/GothicBBB-Medium \
		std.ja_JP/Ryumin-Light.gs7 \
		std.ja_JP/GothicBBB-Medium.gs7 \
		std.zh_CN/STHeiti-Regular \
		std.zh_CN/STSong-Light \
		std.zh_CN/MSung-Light

NO_STAGE=	yes
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	ChangeLog README README.tweaks TODO

post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/fonts && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
