# New ports collection makefile for:	xpi-xhtml-ruby-support
# Date created:		2008-05-21
# Whom:			Anatoly Borodin <anatoly.borodin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xhtml-ruby-support
PORTVERSION=	3.0.2009060901
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	anatoly.borodin@gmail.com
COMMENT=	Adds XHTML Ruby support

XPI_DISTNAME=	xhtml_ruby_support
XPI_ID=		{0620B69D-7B58-416d-A92A-0198860C2757}
XPI_NUM=	1935
XPI_FILES=	chrome/rubysupport.jar chrome.manifest \
		defaults/preferences/rubysupport.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
