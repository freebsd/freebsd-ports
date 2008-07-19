# New ports collection makefile for:	gnu-unifont
# Date created:				Feb 23 2008
# Whom:					nrg milk <bsdports@gmail.com>
#
# $FreeBSD$

PORTNAME=	gnu-unifont
PORTVERSION=	20080620
CATEGORIES=	x11-fonts
MASTER_SITES=	http://unifoundry.com/ \
		http://chirashi-no-ura.net/files/
DISTNAME=	unifont-5.1.${PORTVERSION}.bdf
EXTRACT_SUFX=	.gz

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode Font

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

NO_BUILD=	yes
PLIST_FILES=	lib/X11/fonts/local/unifont.pcf.gz

do-extract:
	${MKDIR} ${WRKDIR}
	${CP} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKDIR}
	${GUNZIP_CMD} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${LOCALBASE}/bin/bdftopcf  ${WRKDIR}/${DISTNAME} | ${GZIP_CMD} > ${WRKDIR}/unifont.pcf.gz
	${CP} ${WRKDIR}/unifont.pcf.gz ${LOCALBASE}/lib/X11/fonts/local/unifont.pcf.gz

.include <bsd.port.mk>
