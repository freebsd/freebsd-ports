# New ports collection makefile for:	wqy font
# Date created:		11 May 2005
# Whom:			Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	wqy
PORTVERSION=	0.7.0
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	wqy
DISTNAME=	${PORTNAME}-bitmapfont-pcf-${PORTVERSION}-4

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A font which includes all the CJK characters covered by Unicode 4.0

WRKSRC=		${WRKDIR}/${PORTNAME}-bitmapfont
NO_BUILD=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/wqy

PLIST_SUB=	FONTSDIR=${FONTSDIR}

BUILD_DEPENDS+=        mkfontdir:${X_CLIENTS_PORT}
BUILD_DEPENDS+=        fc-cache:${PORTSDIR}/x11-fonts/fontconfig

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog CREDIT GPL.txt INSTALL INSTALL.zh.gb2312 LOGO.png PLEASE_HELP_TO_IMPROVE README STAT
.endif

do-install:
	@${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.pcf ${PREFIX}/${FONTSDIR}

post-install:
	@${RM} ${PREFIX}/${FONTSDIR}/fonts* >/dev/null 2>&1 || true
	@command mkfontdir ${PREFIX}/${FONTSDIR} || true
	@${CP} ${PREFIX}/${FONTSDIR}/fonts.dir ${PREFIX}/${FONTSDIR}/fonts.scale || true
	@command fc-cache -v ${PREFIX}/${FONTSDIR} || true

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
