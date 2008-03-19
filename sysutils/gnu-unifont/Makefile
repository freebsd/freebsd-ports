# New ports collection makefile for:	gnu-unifont
# Date created:				Feb 23 2008
# Whom:					nrg milk <bsdports@gmail.com>
#
# $FreeBSD$

PORTNAME=	gnu-unifont
PORTVERSION=	1.0.0
CATEGORIES=	sysutils
MASTER_SITES=	http://chirashi-no-ura.net/files/
DISTNAME=	unifont.hex
EXTRACT_SUFX=	.tar.bz

MAINTAINER=	bsdports@gmail.com
COMMENT=	Unicode font

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

USE_PERL=	5.8
NO_BUILD=	yes
PLIST_FILES=	lib/X11/fonts/local/unifont.pcf.gz

do-install:
	${CHMOD} +x ${FILESDIR}/hex2bdf
	${CAT} ${WRKDIR}/unifont.hex | ${FILESDIR}/hex2bdf | ${LOCALBASE}/bin/bdftopcf | ${GZIP_CMD} > ${WRKDIR}/unifont.pcf.gz
	${CP} ${WRKDIR}/unifont.pcf.gz ${LOCALBASE}/lib/X11/fonts/local/unifont.pcf.gz

.include <bsd.port.mk>
