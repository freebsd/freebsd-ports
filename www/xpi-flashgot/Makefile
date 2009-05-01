# New ports collection makefile for:	xpi-flashgot
# Date created:		19 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flashgot
PORTVERSION=	1.1.8.6
#DISTVERSIONSUFFIX=	-fx+mz+tb+ns+sm+fl
CATEGORIES=	www
MASTER_SITES=	http://software.informaction.com/data/releases/ CENKES

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Download links using popular download managers

XPI_ID=		{19503e42-ca3c-4c27-b1e2-9cdb2170ee34}
XPI_NUM=	220
XPI_FILES=	FlashGot_License.txt GPL.txt chrome/flashgot.jar chrome.manifest components/.autoreg \
		components/flashgotService.js defaults/preferences/flashgot.js install.js install.rdf
XPI_DIRS=	chrome components defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
