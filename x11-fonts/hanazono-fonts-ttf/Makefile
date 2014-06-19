# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	hanazono-fonts-ttf
PORTVERSION=	20131208
CATEGORIES=	x11-fonts
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	hanazono-font/60001
DISTNAME=	${PORTNAME:C/-.*//}-${PORTVERSION}

MAINTAINER=	lichray@gmail.com
COMMENT=	CJK Mincho-typeface developed by Hanazono University

LICENSE=	OFL11

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USES=		zip
NO_WRKSUBDIR=	yes

FONTDIR=	lib/X11/fonts/Hana
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_SUB=	FONTDIR=${FONTDIR}
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

do-build:
	@cd ${WRKSRC}/ && \
		${LOCALBASE}/bin/mkfontscale && \
		${LOCALBASE}/bin/mkfontdir

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTDIR}/
	cd ${WRKSRC}/ && \
		${INSTALL_DATA} *.ttf fonts.* ${STAGEDIR}${PREFIX}/${FONTDIR}/

.include <bsd.port.mk>
