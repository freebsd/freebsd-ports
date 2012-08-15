# New ports collection makefile for:	xpi-firemobilesimulator
# Date created:				2009-04-23
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firemobilesimulator
PORTVERSION=	1.2.2
CATEGORIES=	www
MASTER_SITES=	https://ss1.xrea.com/poly.s49.xrea.com/dev/firefox/
DISTNAME=	${XPI_DISTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Mobile Browser(NTT docomo/au/SoftBank) Simulator

XPI_ID=		{77cc852e-6b45-11dd-929f-d30256d89593}
XPI_FILES=	chrome.manifest chrome/msim.jar \
		components/msimModifyHeaders.js \
		components/msimStreamConverter.js \
		components/nsDeviceProtocolHandler.js \
		defaults/preferences/msim.js \
		install.rdf license.txt

XPI_DIRS=	chrome components \
		defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
