# New ports collection makefile for:	tvbrowser
# Date Created:				24 May 2005
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	tvbrowser
PORTVERSION=	2.7.3
CATEGORIES=	misc java
MASTER_SITES=	SF/${PORTNAME}/OldFiles/${PORTVERSION}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A digital TV guide

USE_LDCONFIG=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
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
