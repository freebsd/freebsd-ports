# New ports collection makefile for:	gnu-unifont-ttf
# Date created:				Jul 6 2008
# Whom:					nrg milk <bsdports@gmail.com>
#
# $FreeBSD$

PORTNAME=	gnu-unifont-ttf
PORTVERSION=	20080620
CATEGORIES=	x11-fonts
MASTER_SITES=	http://unifoundry.com/ \
		http://chirashi-no-ura.net/files/
DISTNAME=	unifont-5.1.${PORTVERSION}.ttf
EXTRACT_SUFX=	.gz

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode TrueType Font

NO_BUILD=	yes
PLIST_FILES=	lib/X11/fonts/local/unifont.ttf

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKDIR}
	${GUNZIP_CMD} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${CP} ${WRKDIR}/${DISTNAME} ${LOCALBASE}/lib/X11/fonts/local/unifont.ttf

.include <bsd.port.mk>
