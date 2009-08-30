# New ports collection makefile for:   terminus-font
# Date Created:                         04 Nov 2002
# Whom:                                 Michael Hsin <mhsin@mhsin.org>
#
# $FreeBSD$
#

PORTNAME=	terminus-font
PORTVERSION=	4.28
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.is-vn.bg/hamster/
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	Terminus Font - a clean fixed width font

BUILD_DEPENDS=	mkitalic:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USE_PERL5_BUILD=yes

OPTIONS=	AO2 "Variant of letter 'a'" off \
		DV1 "Variant of cyrillic letters 'de' and 've'" off \
		GE1 "Variant of cyrillic letter 'ge'" off \
		GQ2 "Variant of grave accent and apostrophe" off \
		IJ1 "Variant of cyrillic letters 'i' and 'short i'" off \
		KA2 "Variant of cyrillic letter 'ka'" off \
		CM2 "Variant of letters with circumflex, caron and macron" off

.include <bsd.port.pre.mk>

ALL_TARGET=	pcf
FONTDIR=	lib/X11/fonts/${PORTNAME}
PLIST_SUB+=	FONTDIR=${FONTDIR}

.if defined(WITH_AO2)
PATCHFILES+=	terminus-font-4.28-ao2.diff.gz
.endif

.if defined(WITH_DV1)
PATCHFILES+=	terminus-font-4.28-dv1.diff.gz
.endif

.if defined(WITH_GE1)
PATCHFILES+=	terminus-font-4.28-ge1.diff.gz
.endif

.if defined(WITH_GQ2)
PATCHFILES+=	terminus-font-4.28-gq2.diff.gz
.endif

.if defined(WITH_IJ1)
PATCHFILES+=	terminus-font-4.28-ij1.diff.gz
.endif

.if defined(WITH_KA2)
PATCHFILES+=	terminus-font-4.28-ka2.diff.gz
.endif

.if defined(WITH_CM2)
PATCHFILES+=	terminus-font-4.28-cm2.diff.gz
.endif

post-build:
	@${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	@${MKDIR} ${LOCALBASE}/${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pcf.gz ${LOCALBASE}/${FONTDIR}

post-install:
	@cd ${LOCALBASE}/${FONTDIR}; mkfontdir
	@${CP} ${LOCALBASE}/${FONTDIR}/fonts.dir ${LOCALBASE}/${FONTDIR}/fonts.scale || true
	@command fc-cache -f -v ${LOCALBASE}/${FONTDIR} || true

.include <bsd.port.post.mk>
