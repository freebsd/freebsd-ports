# New ports collection makefile for:	xpi-jslib
# Date created:			10 October 2010
# Whom:				Lapo Luchini <lapo@lapo.it>
#
# $FreeBSD$
#

PORTNAME=	jslib
PORTVERSION=	0.1.371
CATEGORIES=	www
MASTER_SITES=	http://lapo.it/freebsd/
DISTNAME=	jslib_${PORTVERSION}_lite

MAINTAINER=	lapo@lapo.it
COMMENT=	Library of common useful routines for XPI developers

LICENSE=	MPL

XPI_ID=		{DF8E5247-8E0A-4de6-B393-0735A39DFD80}
XPI_FILES=	application.ini chrome/jslib.jar chrome/jsliblive/contents.rdf chrome/jsliblive/jsliblive.xul chrome.manifest components/jslib-dom.js components/jslib-service.js components/jslib.xpt defaults/preferences/prefs.js install.js install.rdf
XPI_DIRS=	chrome/jsliblive chrome components defaults/preferences defaults

post-patch:
		${REINPLACE_CMD} -Ee '/Suite/,/Flock/s/>2[.]0[.][*]</>2.4.*</' ${WRKSRC}/install.rdf
		${RM} -f ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
