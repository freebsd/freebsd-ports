# $FreeBSD$

PORTNAME=	tamsyn-font
DISTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.fial.com/~scott/tamsyn-font/download/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Monospaced bitmap font for programming

LICENSE=	TAMSYN
LICENSE_NAME=	Tamsyn License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

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

VT_BUILD_DEPENDS=	pcf2bdf:x11-fonts/pcf2bdf
VT_CHARFIX_7x14=	168 # U+00A8 (DIAERESIS)
VT_CHARFIX_8x15=	180 # U+00B4 (ACUTE ACCENT)
VT_CHARFIX_8x16=	180

X11_USES=		fonts
X11_USES_OFF=		fonts:none

do-build:
	@${DO_NADA}

do-build-VT-on:
.for sz in 5x9 6x12 7x13 7x14 8x15 8x16 10x20
	pcf2bdf -o ${WRKSRC}/Tamsyn${sz}r.bdf ${WRKSRC}/Tamsyn${sz}r.pcf
	pcf2bdf -o ${WRKSRC}/Tamsyn${sz}b.bdf ${WRKSRC}/Tamsyn${sz}b.pcf
.endfor
.for sz in 5x9 6x12 7x13 7x14 8x15 8x16 10x20
.if !empty(VT_CHARFIX_${sz})
# Fix fonts that are missing some characters in the regular fonts
# that are available in the bold fonts, which vtfontcvt does not
# like.
	${MV} ${WRKSRC}/Tamsyn${sz}r.bdf \
		${WRKSRC}/Tamsyn${sz}r.bdf.orig
	${AWK} -f ${FILESDIR}/paste-char.awk \
		-v copy=${VT_CHARFIX_${sz}} \
		${WRKSRC}/Tamsyn${sz}b.bdf \
		${WRKSRC}/Tamsyn${sz}r.bdf.orig \
		> ${WRKSRC}/Tamsyn${sz}r.bdf
.endif
	vtfontcvt ${sz:S/^/-w /:S/x/ -h /} \
		${WRKSRC}/Tamsyn${sz}r.bdf \
		${WRKSRC}/Tamsyn${sz}b.bdf \
		${WRKSRC}/Tamsyn${sz}.fnt
.endfor

do-build-X11-on:
	${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-VT-on:
	${INSTALL_DATA} ${WRKSRC}/*.fnt ${STAGEDIR}${FONTSDIR}

do-install-X11-on:
	${INSTALL_DATA} ${FILESDIR}/fonts.alias ${WRKSRC}/*.pcf.gz \
		${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
