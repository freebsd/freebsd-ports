# New ports collection makefile for:	xpi-statusbarclock
# Date created:		2006-07-27
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	statusbarclock
PORTVERSION=	1.7.2
CATEGORIES=	www
MASTER_SITES=	http://www.willbueche.com/temp/ \
		http://olofsson.de/mirror/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	simon@olofsson.de
COMMENT=	Display date and time in the status bar

XPI_ID=		{3669edc0-b1ad-11d8-92e7-00d09e0179f2}
XPI_FILES=	chrome/timestatus.jar chrome.manifest \
		defaults/preferences/timestatus-defaults.js \
		install.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

post-extract:
	@${RM} -rf ${WRKSRC}/META-INF ${WRKSRC}/readme.txt

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
