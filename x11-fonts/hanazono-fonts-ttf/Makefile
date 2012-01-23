# New ports collection makefile for: hanazono-fonts-ttf
# Date created:		2011/08/09
# Whom:		Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hanazono-fonts-ttf
PORTVERSION=	20110915
CATEGORIES=	x11-fonts
MASTER_SITES=	http://kage.sourceforge.jp/hanazono/
DISTNAME=	${PORTNAME:C/-.*//}-${PORTVERSION}

MAINTAINER=	lichray@gmail.com
COMMENT=	CJK Mincho-typeface developed by Hanazono University

LICENSE=	OFL
LICENSE_NAME=	Open Font License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	auto-accept

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_ZIP=	yes
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
	${MKDIR} ${PREFIX}/${FONTDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.ttf fonts.* ${PREFIX}/${FONTDIR}/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
