# New ports collection makefile for:	xpi-firebug
# Date created:			10 Otcober 2010
# Whom:				Lapo Luchini <lapo@lapo.it>
#
# $FreeBSD$
#

PORTNAME=	jslib
PORTVERSION=	0.1.365
CATEGORIES=	www
MASTER_SITES=	http://downloads.mozdev.org/jslib/xpi/signed/
DISTNAME=	jslib_current_lite_signed
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	lapo@lapo.it
COMMENT=	Library of common useful routines for XPI developers

LICENSE=	MPL

FETCH_ARGS=	"-pRr" # without "-A" as MASTER_SITE uses redirect to send to different mirrors

XPI_ID=		{DF8E5247-8E0A-4de6-B393-0735A39DFD80}
XPI_FILES=	application.ini chrome/jslib.jar chrome/jsliblive/contents.rdf chrome/jsliblive/jsliblive.xul chrome.manifest components/jslib-dom.js components/jslib-service.js components/jslib.xpt defaults/preferences/prefs.js install.js install.rdf
XPI_DIRS=	chrome/jsliblive chrome components defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
