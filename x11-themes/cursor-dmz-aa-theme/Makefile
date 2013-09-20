# $FreeBSD$

PORTNAME=	cursor-dmz-aa-theme
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://jimmac.musichall.cz/zip/
DISTNAME=	vanilla-dmz-aa-${PORTVERSION}

MAINTAINER=	flz@FreeBSD.org
COMMENT=	The DMZ AA style neutral scalable cursor theme

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/lib/X11/icons/Vanilla-DMZ-AA/cursors
	cd ${WRKSRC}/Vanilla-DMZ-AA/cursors \
		&& ${FIND} * | ${CPIO} -pdmu ${PREFIX}/lib/X11/icons/Vanilla-DMZ-AA/cursors

.include <bsd.port.mk>
