# New ports collection makefile for:	cursor-dmz-theme
# Date created:				Feb 7 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cursor-dmz-theme
PORTVERSION=	0.3
CATEGORIES=	x11-themes
MASTER_SITES=	http://jimmac.musichall.cz/zip/
DISTNAME=	vanilla-dmz-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	The DMZ style neutral scalable cursor theme

USE_BZIP2=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/Vanilla-DMZ/cursors
	cd ${WRKSRC}/Vanilla-DMZ/cursors \
		&& ${FIND} * | ${CPIO} -pdmu ${PREFIX}/lib/X11/icons/Vanilla-DMZ/cursors

.include <bsd.port.mk>
