# New ports collection makefile for:	xpi-dispmua
# Date created:			25 august 2010
# Whom:				Lapo Luchini <lapo@lapo.it>
#
# $FreeBSD$
#

PORTNAME=	dispmua
PORTVERSION=	1.6.5
CATEGORIES=	mail
DISTNAME=	display_mail_user_agent-${DISTVERSION}-tb+sm

MAINTAINER=	lapo@lapo.it
COMMENT=	Displays the icon of the application with which the e-mail was written

XPI_NUM=	562
XPI_ID=		{F8147CF4-B9E3-445B-AA87-081ED66548F8}
XPI_FILES=	CHANGELOG LICENSE chrome/chrome.jar chrome.manifest defaults/preferences/prefs.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../../www/xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
