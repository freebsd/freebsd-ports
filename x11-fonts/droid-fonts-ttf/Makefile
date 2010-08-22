# New ports collection makefile for: droid-fonts-ttf
# Date created:		2010-02-14
# Whom:		Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	droid-fonts-ttf
PORTVERSION=	20100214
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://android.git.kernel.org/?p=platform/frameworks/base.git\;a=blob_plain\;f=data/fonts/:droid
DISTFILES=	DroidSans-Bold.ttf:droid \
		DroidSans.ttf:droid \
		DroidSansArabic.ttf:droid \
		DroidSansFallback.ttf:droid \
		DroidSansFallbackLegacy.ttf:droid \
		DroidSansHebrew.ttf:droid \
		DroidSansJapanese.ttf:droid \
		DroidSansMono.ttf:droid \
		DroidSansThai.ttf:droid \
		DroidSerif-Bold.ttf:droid \
		DroidSerif-BoldItalic.ttf:droid \
		DroidSerif-Italic.ttf:droid \
		DroidSerif-Regular.ttf:droid \
		NOTICE:droid

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	The Droid typeface family

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

LICENSE=	ASL
LICENSE_FILE=	${DISTDIR}/NOTICE

NO_WRKSUBDIR=	yes

PLIST_SUB=	FONTDIR="${FONTDIR:S|${LOCALBASE}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTDIR=${FONTDIR}

FONTNAME=	Droid
FONTDIR=	${LOCALBASE}/lib/X11/fonts/${FONTNAME}

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

NO_MTREE=	yes

do-extract:
	@${MKDIR} ${WRKDIR}/ttf
	@${CP} -p ${DISTDIR}/*.ttf ${WRKDIR}/ttf

do-build:
	@cd ${WRKDIR}/ttf && \
		${MKFONTSCL_CMD} && \
		${MKFONTDIR_CMD}

do-install:
	@${MKDIR} ${FONTDIR}
	@cd ${WRKDIR} && \
		${INSTALL_DATA} ttf/* ${FONTDIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
