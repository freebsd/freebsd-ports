# New ports collection makefile for:	xpi-passwordmaker
# Date created:		2008-05-21
# Whom:			Anatoly Borodin <anatoly.borodin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	passwordmaker
PORTVERSION=	1.7.7
DISTVERSIONSUFFIX=	-fx+mz+sm
CATEGORIES=	www

MAINTAINER=	anatoly.borodin@gmail.com
COMMENT=	Manages all your online accounts using new or existing passwords

XPI_ID=		{5872365e-67d1-4afd-9480-fd293bebd20d}
XPI_NUM=	469
XPI_FILES=	LICENSE chrome/passwdmaker.jar chrome.manifest \
		components/component.js defaults/preferences/passwdmaker.js \
		install.js install.rdf
XPI_DIRS=	chrome components defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
