# New ports collection makefile for:	tvbrowser
# Date Created:				24 May 2005
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	tvbrowser
PORTVERSION=	3.0.1
CATEGORIES=	misc java
MASTER_SITES=	SF/${PORTNAME}/TV-Browser%20Releases%20%28Java%206%20and%20higher%29/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}_bin

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A digital TV guide

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
SUB_FILES=	tvbrowser

DESKTOP_ENTRIES="TV-Browser" \
		"A digital TV guide" \
		"${DATADIR}/imgs/tvbrowser128.png" \
		"tvbrowser" \
		"Application;TV;" \
		false

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} "${DATADIR}/{}" \;
	cd ${WRKSRC} && ${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;
	${INSTALL_SCRIPT} ${WRKDIR}/tvbrowser ${PREFIX}/bin

.include <bsd.port.mk>
