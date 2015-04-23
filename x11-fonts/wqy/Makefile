# Created by: Dryice Liu <dryice@liu.com.cn>
# $FreeBSD$

PORTNAME=	wqy-fonts
PORTVERSION=	20100803
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/wqy/wqy-bitmapfont/1.0.0-RC1:bitmapfont \
		SF/wqy/wqy-unibit/1.1.0:unibit \
		SF/wqy/wqy-zenhei/0.9.45%20%28Fighting-state%20RC1%29:zenhei \
		SF/wqy/wqy-microhei-lite/0.2.0-beta:microheilite \
		SF/wqy/wqy-microhei/0.2.0-beta:microhei
DISTFILES=	wqy-bitmapsong-pcf-1.0.0-RC1.tar.gz:bitmapfont \
		wqy-unibit-bdf-1.1.0-1.tar.gz:unibit \
		wqy-zenhei-0.9.45.tar.gz:zenhei \
		wqy-microhei-lite-0.2.0-beta.tar.gz:microheilite \
		wqy-microhei-0.2.0-beta.tar.gz:microhei

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU GPL-licensed font set covering CJK and other Unicode characters

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

USE_XORG=	x11
USES=		fonts perl5
USE_PERL5=	build
NO_WRKSUBDIR=	yes

FONTNAME=	wqy
CONFDDIR=	etc/fonts/conf.d
CONFAVAILDIR=	etc/fonts/conf.avail

PLIST_SUB=	CONFDDIR=${CONFDDIR} \
		CONFAVAILDIR=${CONFAVAILDIR}

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS.bitmap ChangeLog.bitmap README.bitmap COPYING.bitmap \
		LOGO.png \
		AUTHORS.zenhei ChangeLog.zenhei README.zenhei \
		AUTHORS.microheilite README.microheilite ChangeLog.microheilite \
		AUTHORS.microhei README.microhei ChangeLog.microhei \
		LICENSE_Apache2.txt LICENSE_GPLv3.txt

do-build:
	${PERL} ${WRKDIR}/wqy-unibit/bdfmerge.pl 0x0--0xFFFF ${WRKDIR}/wqy-unibit/wqy-unibit.bdf > ${WRKDIR}/wqy-unibit/wqy-unibit_cjk.bdf
	bdftopcf ${WRKDIR}/wqy-unibit/wqy-unibit_cjk.bdf > ${WRKDIR}/wqy-unibit/wqy-unibit.pcf
	${CP} ${WRKDIR}/wqy-bitmapsong/AUTHORS ${WRKDIR}/wqy-bitmapsong/AUTHORS.bitmap
	${CP} ${WRKDIR}/wqy-bitmapsong/ChangeLog ${WRKDIR}/wqy-bitmapsong/ChangeLog.bitmap
	${CP} ${WRKDIR}/wqy-bitmapsong/README ${WRKDIR}/wqy-bitmapsong/README.bitmap
	${CP} ${WRKDIR}/wqy-bitmapsong/COPYING ${WRKDIR}/wqy-bitmapsong/COPYING.bitmap
	${CP} ${WRKDIR}/wqy-zenhei/AUTHORS ${WRKDIR}/wqy-zenhei/AUTHORS.zenhei
	${CP} ${WRKDIR}/wqy-zenhei/ChangeLog ${WRKDIR}/wqy-zenhei/ChangeLog.zenhei
	${CP} ${WRKDIR}/wqy-zenhei/README ${WRKDIR}/wqy-zenhei/README.zenhei
	${CP} ${WRKDIR}/wqy-microhei-lite/AUTHORS.txt ${WRKDIR}/wqy-microhei-lite/AUTHORS.microheilite
	${CP} ${WRKDIR}/wqy-microhei-lite/ChangeLog.txt ${WRKDIR}/wqy-microhei-lite/ChangeLog.microheilite
	${CP} ${WRKDIR}/wqy-microhei-lite/README.txt ${WRKDIR}/wqy-microhei-lite/README.microheilite
	${CP} ${WRKDIR}/wqy-microhei/AUTHORS.txt ${WRKDIR}/wqy-microhei/AUTHORS.microhei
	${CP} ${WRKDIR}/wqy-microhei/ChangeLog.txt ${WRKDIR}/wqy-microhei/ChangeLog.microhei
	${CP} ${WRKDIR}/wqy-microhei/README.txt ${WRKDIR}/wqy-microhei/README.microhei

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR} ${STAGEDIR}${PREFIX}/${CONFDDIR} ${STAGEDIR}${PREFIX}/${CONFAVAILDIR}
# WQY Bitmap Song
	${INSTALL_DATA} ${WRKDIR}/wqy-bitmapsong/*.pcf ${STAGEDIR}${FONTSDIR}
# WQY Bitmap Song
	${INSTALL_DATA} ${WRKDIR}/wqy-unibit/wqy-unibit.pcf ${STAGEDIR}${FONTSDIR}
# WQY TrueType Zenhei
	${INSTALL_DATA} ${WRKDIR}/wqy-zenhei/wqy-zenhei.ttc ${STAGEDIR}${FONTSDIR}
# WQY TrueType MicroHei Lite
	${INSTALL_DATA} ${WRKDIR}/wqy-microhei-lite/wqy-microhei-lite.ttc ${STAGEDIR}${FONTSDIR}
# WQY TrueType MicroHei
	${INSTALL_DATA} ${WRKDIR}/wqy-microhei/wqy-microhei.ttc ${STAGEDIR}${FONTSDIR}

	${INSTALL_DATA} ${FILESDIR}/85-wqy.conf ${STAGEDIR}${PREFIX}/${CONFAVAILDIR}
	${LN} -sf ${PREFIX}/${CONFAVAILDIR}/85-wqy.conf ${STAGEDIR}${PREFIX}/${CONFDDIR}/85-wqy.conf

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKDIR}/wqy-bitmapsong/AUTHORS.bitmap \
		${WRKDIR}/wqy-bitmapsong/ChangeLog.bitmap \
		${WRKDIR}/wqy-bitmapsong/README.bitmap \
		${WRKDIR}/wqy-bitmapsong/COPYING.bitmap \
		${WRKDIR}/wqy-bitmapsong/LOGO.png \
		${WRKDIR}/wqy-zenhei/AUTHORS.zenhei \
		${WRKDIR}/wqy-zenhei/ChangeLog.zenhei \
		${WRKDIR}/wqy-zenhei/README.zenhei \
		${WRKDIR}/wqy-microhei-lite/AUTHORS.microheilite \
		${WRKDIR}/wqy-microhei-lite/ChangeLog.microheilite \
		${WRKDIR}/wqy-microhei-lite/README.microheilite \
		${WRKDIR}/wqy-microhei/AUTHORS.microhei \
		${WRKDIR}/wqy-microhei/ChangeLog.microhei \
		${WRKDIR}/wqy-microhei/README.microhei \
		${WRKDIR}/wqy-microhei/LICENSE_Apache2.txt \
		${WRKDIR}/wqy-microhei/LICENSE_GPLv3.txt \
			${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
