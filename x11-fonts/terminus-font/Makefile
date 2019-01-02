# Created by: Michael Hsin <mhsin@mhsin.org>
# $FreeBSD$

PORTNAME=	terminus-font
PORTVERSION=	4.47
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	zeising@FreeBSD.org
COMMENT=	Terminus Font - a clean fixed width font

LICENSE=	OFL11

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		gmake fonts python:build,3.5+ shebangfix
NO_ARCH=	yes

SHEBANG_FILES=	bin/*.py

OPTIONS_DEFINE=	AO2 DV1 GE2 GQ2 IJ1 KA2 HI2 LL2 TD1
AO2_DESC=	Variant of letter 'a'
DV1_DESC=	Variant of cyrillic letters 'de' and 've'
GE2_DESC=	Variant of cyrillic letter 'ge'
GQ2_DESC=	Variant of grave accent and apostrophe
IJ1_DESC=	Variant of cyrillic letters 'i' and 'short i'
KA2_DESC=	Variant of cyrillic letter 'ka'
HI2_DESC=	Higher uppercase letters, for size 18
LL2_DESC=	Variant with more distinctive 'l' (ell)
TD1_DESC=	Variant with centered '~'

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

ALL_TARGET=	pcf pcf-8bit

post-extract:
.if ${PORT_OPTIONS:MAO2}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/ao2.diff
.endif
.if ${PORT_OPTIONS:MDV1} && !${PORT_OPTIONS:MHI2}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/dv1.diff
.endif
.if ${PORT_OPTIONS:MGE2}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/ge2.diff
.endif
.if ${PORT_OPTIONS:MGQ2}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/gq2.diff
.endif
.if ${PORT_OPTIONS:MIJ1}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/ij1.diff
.endif
.if ${PORT_OPTIONS:MKA2} && !${PORT_OPTIONS:MHI2}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/ka2.diff
.endif
.if ${PORT_OPTIONS:MHI2}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/hi2.diff
.if ${PORT_OPTIONS:MDV1}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/hi2-dv1.diff
.endif
.if ${PORT_OPTIONS:MKA2}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/hi2-ka2.diff
.endif
.endif
.if ${PORT_OPTIONS:MLL2}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/ll2.diff
.endif
.if ${PORT_OPTIONS:MTD1}
	cd ${WRKSRC} && ${PATCH} -p1 -i alt/td1.diff
.endif

post-patch:
	${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|g' ${WRKSRC}/Makefile

post-build:
	@${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
