# Ports collection makefile for:  bugmenot-firefox
# Date created:			  Tue May 24, 2005
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	bugmenot
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	http://extensions.roachfiend.com/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}_${PORTREVISION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Firefox extension to bypass compulsory web registration

XPI_ID=		{987311C6-B504-4aa2-90BF-60CC49808D42}
XPI_FILES=	chrome/bugmenot.jar install.js install.rdf license.txt chrome.manifest
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
