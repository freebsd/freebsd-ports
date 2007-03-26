# New ports collection makefile for:	wqy font
# Date created:		11 May 2005
# Whom:			Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	wqy
PORTVERSION=	0.8.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	wqy
DISTNAME=	${PORTNAME}-bitmapfont-pcf-${PORTVERSION}-6

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A font which includes all the CJK characters covered by Unicode 4.0

WRKSRC=		${WRKDIR}/${PORTNAME}-bitmapfont
NO_BUILD=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/wqy
CONFDDIR=	etc/fonts/conf.d
CONFAVAILDIR=	etc/fonts/conf.avail

PLIST_SUB=	FONTSDIR=${FONTSDIR} \
		CONFDDIR=${CONFDDIR} \
		CONFAVAILDIR=${CONFAVAILDIR}

BUILD_DEPENDS+=        mkfontdir:${X_CLIENTS_PORT}
BUILD_DEPENDS+=        fc-cache:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS=	ALIAS	"Install fonts.alias" off

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog COPYING INSTALL INSTALL.zh.gb2312 LOGO.png README
.endif

.if defined(WITH_ALIAS)
PLIST_SUB+=	WITHALIAS=""
.else
PLIST_SUB+=	WITHALIAS="@comment "
.endif

do-install:
	@${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/85-wqy-bitmapsong.conf ${PREFIX}/${CONFAVAILDIR}
	${LN} -s ${PREFIX}/${CONFAVAILDIR}/85-wqy-bitmapsong.conf ${PREFIX}/${CONFDDIR}/85-wqy-bitmapsong.conf

post-install:
	@${RM} ${PREFIX}/${FONTSDIR}/fonts* >/dev/null 2>&1 || true
	@command mkfontdir ${PREFIX}/${FONTSDIR} || true
	@${CP} ${PREFIX}/${FONTSDIR}/fonts.dir ${PREFIX}/${FONTSDIR}/fonts.scale || true
	@command fc-cache -v ${PREFIX}/${FONTSDIR} || true
.if defined(WITH_ALIAS)
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${PREFIX}/${CONFAVAILDIR}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
