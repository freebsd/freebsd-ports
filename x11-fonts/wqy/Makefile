# New ports collection makefile for:	wqy font
# Date created:		11 May 2005
# Whom:			Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	wqy-fonts
PORTVERSION=	20081102
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/wqy/wqy-bitmapfont/0.9.9:bitmapfont \
		SF/wqy/wqy-unibit/1.1.0:unibit \
		SF/wqy/wqy-zenhei/0.8.34-cvs20081027:zenhei
DISTFILES=	wqy-bitmapfont-pcf-0.9.9-0.tar.gz:bitmapfont \
		wqy-unibit-bdf-1.1.0-1.tar.gz:unibit \
		wqy-zenhei-0.8.34-cvs20081027.tar.gz:zenhei

MAINTAINER=	intron@intron.ac
COMMENT=	GNU GPL-licensed font set covering CJK and other Unicode characters

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_XORG=	x11
USE_PERL5=	yes

FONTSDIR=	lib/X11/fonts/wqy
CONFDDIR=	etc/fonts/conf.d
CONFAVAILDIR=	etc/fonts/conf.avail

PLIST_SUB=	FONTSDIR=${FONTSDIR} \
		CONFDDIR=${CONFDDIR} \
		CONFAVAILDIR=${CONFAVAILDIR}

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR=${PREFIX}/${FONTSDIR}

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS.bitmap AUTHORS.truetype \
		ChangeLog.bitmap ChangeLog.truetype \
		README.bitmap README.truetype \
		COPYING LOGO.png
.endif

do-build:
	${PERL} ${WRKDIR}/wqy-unibit/bdfmerge.pl 0x0--0xFFFF ${WRKDIR}/wqy-unibit/wqy-unibit.bdf > ${WRKDIR}/wqy-unibit/wqy-unibit_cjk.bdf
	bdftopcf ${WRKDIR}/wqy-unibit/wqy-unibit_cjk.bdf > ${WRKDIR}/wqy-unibit/wqy-unibit.pcf
	${CP} ${WRKDIR}/wqy-bitmapfont/AUTHORS ${WRKDIR}/wqy-bitmapfont/AUTHORS.bitmap
	${CP} ${WRKDIR}/wqy-bitmapfont/ChangeLog ${WRKDIR}/wqy-bitmapfont/ChangeLog.bitmap
	${CP} ${WRKDIR}/wqy-bitmapfont/README ${WRKDIR}/wqy-bitmapfont/README.bitmap
	${CP} ${WRKDIR}/wqy-zenhei/AUTHORS ${WRKDIR}/wqy-zenhei/AUTHORS.truetype
	${CP} ${WRKDIR}/wqy-zenhei/ChangeLog ${WRKDIR}/wqy-zenhei/ChangeLog.truetype
	${CP} ${WRKDIR}/wqy-zenhei/README ${WRKDIR}/wqy-zenhei/README.truetype

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR} ${PREFIX}/${CONFDDIR} ${PREFIX}/${CONFAVAILDIR}
# WQY Bitmap Song
	${INSTALL_DATA} ${WRKDIR}/wqy-bitmapfont/*.pcf ${PREFIX}/${FONTSDIR}
# WQY Bitmap Song
	${INSTALL_DATA} ${WRKDIR}/wqy-unibit/wqy-unibit.pcf ${PREFIX}/${FONTSDIR}
# WQY TrueType
	${INSTALL_DATA} ${WRKDIR}/wqy-zenhei/wqy-zenhei.ttc ${PREFIX}/${FONTSDIR}

	${INSTALL_DATA} ${FILESDIR}/85-wqy.conf ${PREFIX}/${CONFAVAILDIR}
	${LN} -sf ${PREFIX}/${CONFAVAILDIR}/85-wqy.conf ${PREFIX}/${CONFDDIR}/85-wqy.conf

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKDIR}/wqy-bitmapfont/AUTHORS.bitmap \
		${WRKDIR}/wqy-bitmapfont/ChangeLog.bitmap \
		${WRKDIR}/wqy-bitmapfont/README.bitmap \
		${WRKDIR}/wqy-bitmapfont/COPYING \
		${WRKDIR}/wqy-bitmapfont/LOGO.png \
		${WRKDIR}/wqy-zenhei/AUTHORS.truetype \
		${WRKDIR}/wqy-zenhei/ChangeLog.truetype \
		${WRKDIR}/wqy-zenhei/README.truetype \
			${DOCSDIR}
.endif

post-install:
	@${RM} -f ${PREFIX}/${FONTSDIR}/fonts.dir
	@${RM} -f ${PREFIX}/${FONTSDIR}/fonts.scale
	@command mkfontscale -b ${PREFIX}/${FONTSDIR}
	@command fc-cache -fv ${PREFIX}/${FONTSDIR}

	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
