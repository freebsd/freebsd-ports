# $FreeBSD$

PORTNAME=	spleen
DISTVERSION=	1.0.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/fcambus/spleen/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	-font

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Monospaced bitmap fonts for Xorg and vt(4)

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	VT X11
OPTIONS_MULTI=		TYPE
OPTIONS_MULTI_TYPE=	VT X11
.if !exists(/usr/bin/vtfontcvt)
OPTIONS_EXCLUDE=	VT
.endif
OPTIONS_SUB=		yes

TYPE_DESC=		Font type
VT_DESC=		Install vt(4) fonts
X11_DESC=		Install Xorg bitmap fonts

X11_BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf
X11_USES=		fonts
X11_USES_OFF=		fonts:none

post-patch:
	@${REINPLACE_CMD} -E 's/^FONT "(.*)"$$/FONT \1/g' ${WRKSRC}/*.bdf

do-build:
	@${DO_NADA}

do-build-VT-on:
# 32x64 appears to be too large for vtfontcvt: Unsupported wbytes 4!
.for sz in 5x8 8x16 12x24 16x32
	vtfontcvt ${sz:S/^/-w /:S/x/ -h /} \
		${WRKSRC}/spleen-${sz}.bdf ${WRKSRC}/spleen-${sz}.fnt
.endfor

do-build-X11-on:
.for sz in 5x8 8x16 12x24 16x32 32x64
	bdftopcf -t -o ${WRKSRC}/spleen-${sz}.pcf ${WRKSRC}/spleen-${sz}.bdf
.endfor
	${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

do-install-VT-on:
	${INSTALL_DATA} ${WRKSRC}/*.fnt ${STAGEDIR}${FONTSDIR}

do-install-X11-on:
	${INSTALL_DATA} ${WRKSRC}/fonts.alias-spleen \
		${STAGEDIR}${FONTSDIR}/fonts.alias
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
