# New ports collection makefile for:	xpi-table2clipboard
# Date created:				2009-04-26
# Whom:					Norikatsu Shigemura <nork@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	table2clipboard
PORTVERSION=	1.5.1
DISTVERSIONSUFFIX=	-fx+tb+sm
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Table to Clipboard extension with correct disposition

XPI_NUM=	1852
XPI_ID=		{9ab67d74-ec41-4cb2-b417-df5d93ba1beb}
XPI_FILES=	chrome.manifest chrome/t2c.jar \
		defaults/preferences/t2c.js \
		install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
