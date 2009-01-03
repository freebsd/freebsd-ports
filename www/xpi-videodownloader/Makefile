# New ports collection makefile for:	xpi-videodownloader
# Date created:			2006/05/06
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	videodownloader
PORTVERSION=	1.1.1
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www
MASTER_SITES=	CENKES

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Download embedded video files

DEPRECATED=	Ports could installed and updated more easily by user's browser(firefox)
EXPIRATION_DATE=2009-01-31

XPI_ID=		videodowloader@videodownloader.net
XPI_FILES=	chrome/videodownloader.jar chrome.manifest defaults/preferences/videodownloader.js \
		install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
