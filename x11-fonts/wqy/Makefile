# Created by: Dryice Liu <dryice@liu.com.cn>
# $FreeBSD$

PORTNAME=	wqy-fonts
PORTVERSION=	20100803
PORTREVISION=	10
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

LICENSE=	GPLv2

BUILD_DEPENDS=	bdftopcf:x11-fonts/bdftopcf

USES=		fonts perl5 xorg
USE_XORG=	x11
USE_PERL5=	build
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

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
	${PERL} ${WRKSRC}/wqy-unibit/bdfmerge.pl 0x0--0xFFFF ${WRKSRC}/wqy-unibit/wqy-unibit.bdf > ${WRKSRC}/wqy-unibit/wqy-unibit_cjk.bdf
	bdftopcf ${WRKSRC}/wqy-unibit/wqy-unibit_cjk.bdf > ${WRKSRC}/wqy-unibit/wqy-unibit.pcf
	${CP} ${WRKSRC}/wqy-bitmapsong/AUTHORS ${WRKSRC}/wqy-bitmapsong/AUTHORS.bitmap
	${CP} ${WRKSRC}/wqy-bitmapsong/ChangeLog ${WRKSRC}/wqy-bitmapsong/ChangeLog.bitmap
	${CP} ${WRKSRC}/wqy-bitmapsong/README ${WRKSRC}/wqy-bitmapsong/README.bitmap
	${CP} ${WRKSRC}/wqy-bitmapsong/COPYING ${WRKSRC}/wqy-bitmapsong/COPYING.bitmap
	${CP} ${WRKSRC}/wqy-zenhei/AUTHORS ${WRKSRC}/wqy-zenhei/AUTHORS.zenhei
	${CP} ${WRKSRC}/wqy-zenhei/ChangeLog ${WRKSRC}/wqy-zenhei/ChangeLog.zenhei
	${CP} ${WRKSRC}/wqy-zenhei/README ${WRKSRC}/wqy-zenhei/README.zenhei
	${CP} ${WRKSRC}/wqy-microhei-lite/AUTHORS.txt ${WRKSRC}/wqy-microhei-lite/AUTHORS.microheilite
	${CP} ${WRKSRC}/wqy-microhei-lite/ChangeLog.txt ${WRKSRC}/wqy-microhei-lite/ChangeLog.microheilite
	${CP} ${WRKSRC}/wqy-microhei-lite/README.txt ${WRKSRC}/wqy-microhei-lite/README.microheilite
	${CP} ${WRKSRC}/wqy-microhei/AUTHORS.txt ${WRKSRC}/wqy-microhei/AUTHORS.microhei
	${CP} ${WRKSRC}/wqy-microhei/ChangeLog.txt ${WRKSRC}/wqy-microhei/ChangeLog.microhei
	${CP} ${WRKSRC}/wqy-microhei/README.txt ${WRKSRC}/wqy-microhei/README.microhei

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR} ${STAGEDIR}${PREFIX}/${CONFDDIR} ${STAGEDIR}${PREFIX}/${CONFAVAILDIR}
# WQY Bitmap Song
	${INSTALL_DATA} ${WRKSRC}/wqy-bitmapsong/*.pcf ${STAGEDIR}${FONTSDIR}
# WQY Bitmap Song
	${INSTALL_DATA} ${WRKSRC}/wqy-unibit/wqy-unibit.pcf ${STAGEDIR}${FONTSDIR}
# WQY TrueType Zenhei
	${INSTALL_DATA} ${WRKSRC}/wqy-zenhei/wqy-zenhei.ttc ${STAGEDIR}${FONTSDIR}
# WQY TrueType MicroHei Lite
	${INSTALL_DATA} ${WRKSRC}/wqy-microhei-lite/wqy-microhei-lite.ttc ${STAGEDIR}${FONTSDIR}
# WQY TrueType MicroHei
	${INSTALL_DATA} ${WRKSRC}/wqy-microhei/wqy-microhei.ttc ${STAGEDIR}${FONTSDIR}

	${INSTALL_DATA} ${FILESDIR}/85-wqy.conf ${STAGEDIR}${PREFIX}/${CONFAVAILDIR}
	${LN} -sf ${PREFIX}/${CONFAVAILDIR}/85-wqy.conf ${STAGEDIR}${PREFIX}/${CONFDDIR}/85-wqy.conf

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/wqy-bitmapsong/AUTHORS.bitmap \
		${WRKSRC}/wqy-bitmapsong/ChangeLog.bitmap \
		${WRKSRC}/wqy-bitmapsong/README.bitmap \
		${WRKSRC}/wqy-bitmapsong/COPYING.bitmap \
		${WRKSRC}/wqy-bitmapsong/LOGO.png \
		${WRKSRC}/wqy-zenhei/AUTHORS.zenhei \
		${WRKSRC}/wqy-zenhei/ChangeLog.zenhei \
		${WRKSRC}/wqy-zenhei/README.zenhei \
		${WRKSRC}/wqy-microhei-lite/AUTHORS.microheilite \
		${WRKSRC}/wqy-microhei-lite/ChangeLog.microheilite \
		${WRKSRC}/wqy-microhei-lite/README.microheilite \
		${WRKSRC}/wqy-microhei/AUTHORS.microhei \
		${WRKSRC}/wqy-microhei/ChangeLog.microhei \
		${WRKSRC}/wqy-microhei/README.microhei \
		${WRKSRC}/wqy-microhei/LICENSE_Apache2.txt \
		${WRKSRC}/wqy-microhei/LICENSE_GPLv3.txt \
			${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
