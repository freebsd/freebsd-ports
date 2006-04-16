# Ports collection makefile for:  preferential-firefox
# Date created:			  Tue Oct 28, 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	preferential
PORTVERSION=	0.8.1
CATEGORIES=	www
MASTER_SITES=	http://mozdev.elliptic.fr/preferential/versions/	\
		http://mozdev.oregonstate.edu/preferential/versions/	\
		http://downloads.mozdev.org/preferential/versions/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI interface to view & edit all Firefox prefs

XPI_ID=		{e3a1bec3-1cc1-4d20-875b-a10587471a5e}
XPI_FILES=	chrome/preferential.jar install.js install.rdf chrome.manifest
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
