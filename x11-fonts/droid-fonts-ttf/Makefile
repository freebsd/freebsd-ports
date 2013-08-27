# Created by: Olivier Duchateau <duchateau.olivier@gmail.com>
# $FreeBSD$

PORTNAME=	droid-fonts-ttf
PORTVERSION=	20110324
CATEGORIES=	x11-fonts
MASTER_SITES=	LOCAL/sunpoet/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	The Droid typeface family

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/NOTICE

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_BZIP2=	yes

FONTDIR=	lib/X11/fonts/Droid
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

# maintainer section:
# http://android.git.kernel.org/?p=platform/frameworks/base.git;a=tree;f=data/fonts

MS_WRKSRC=	${WRKSRC}/${PORTNAME}-${MS_VERSION}
MS_MASTER_SITE=	http://android.git.kernel.org/?p=platform/frameworks/base.git\;a=blob_plain\;f=data/fonts
MS_DISTFILES=	DroidSans-Bold.ttf \
		DroidSans.ttf \
		DroidSansArabic.ttf \
		DroidSansFallback.ttf \
		DroidSansFallbackLegacy.ttf \
		DroidSansHebrew.ttf \
		DroidSansJapanese.ttf \
		DroidSansMono.ttf \
		DroidSansThai.ttf \
		DroidSerif-Bold.ttf \
		DroidSerif-BoldItalic.ttf \
		DroidSerif-Italic.ttf \
		DroidSerif-Regular.ttf \
		NOTICE

.if defined(MS_VERSION)
maketar: do-clean extract
	${MKDIR} ${MS_WRKSRC}
.for distfile in ${MS_DISTFILES}
	${FETCH_CMD} -o ${MS_WRKSRC}/${distfile} ${MS_MASTER_SITE}/${distfile}
.endfor
	cd ${WRKSRC}/ && ${TAR} -jcf ${PORTNAME}-${MS_VERSION}.tar.bz2 ${PORTNAME}-${MS_VERSION}/
	${SED} -i '' -e 's|${PORTVERSION}|${MS_VERSION}|' ${.CURDIR}/Makefile
	${INSTALL} -m 644 ${WRKSRC}/${PORTNAME}-${MS_VERSION}.tar.bz2 ${DISTDIR}/
	cd ${.CURDIR}/ && ${MAKE} makesum
	${ECHO_MSG} '*** Update from ${PORTVERSION} to ${MS_VERSION} ***'
.endif

.include <bsd.port.mk>
