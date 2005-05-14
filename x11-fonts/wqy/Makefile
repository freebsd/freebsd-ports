# New ports collection makefile for:	wqy font
# Date created:		11 May 2005
# Whom:			Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	wqy
PORTVERSION=	1.1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://bsdchat.com/dist/dryice/
MASTER_SITE_SUBDIR=	wqy
DISTNAME=	${PORTNAME}-yhunifont-bdf-${PORTVERSION}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	A font which includes all the CJK characters covered by Unicode 4.0

WRKSRC=		${WRKDIR}/${PORTNAME}-yhunifont
NO_BUILD=	yes
USE_X_PREFIX=	yes
FONTSDIR=	lib/X11/fonts/wqy

PLIST_FILES=	${FONTSDIR}/fonts.dir ${FONTSDIR}/yhunifont.bdf
PLIST_DIRS=	${FONTSDIR}

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog COPYING INSTALL README.yhunifont
.endif

do-install:
	@${MKDIR} ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts.dir ${PREFIX}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/yhunifont.bdf ${PREFIX}/${FONTSDIR}

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
