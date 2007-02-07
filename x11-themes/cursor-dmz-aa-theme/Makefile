# New ports collection makefile for:	cursor-dmz-aa-theme
# Date created:				Feb 7 2007
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cursor-dmz-aa-theme
PORTVERSION=	0.2
CATEGORIES=	x11-themes
MASTER_SITES=	http://jimmac.musichall.cz/zip/
DISTNAME=	vanilla-dmz-aa-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	The DMZ AA style neutral scalable cursor theme

USE_BZIP2=	yes
NO_BUILD=	yes
USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/Vanilla-DMZ-AA/cursors
	cd ${WRKSRC}/Vanilla-DMZ-AA/cursors \
		&& ${FIND} * | ${CPIO} -pdmu ${PREFIX}/lib/X11/icons/Vanilla-DMZ-AA/cursors

.include <bsd.port.mk>
