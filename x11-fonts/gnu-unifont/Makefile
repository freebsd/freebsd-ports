# New ports collection makefile for:	gnu-unifont
# Date created:				Feb 23 2008
# Whom:					nrg milk <bsdports@gmail.com>
#
# $FreeBSD$

PORTNAME=	gnu-unifont
PORTVERSION=	20080510
CATEGORIES=	x11-fonts
MASTER_SITES=	http://unifoundry.com/ \
		http://chirashi-no-ura.net/files/
DISTNAME=	gnu-unifont-2008-05-10.bdf
EXTRACT_SUFX=	.gz

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode font

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
