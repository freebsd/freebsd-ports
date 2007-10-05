# New ports collection makefile for:	xpi-statusbarclock
# Date created:		2006-07-27
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	statusbarclock
PORTVERSION=	1.8.0
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Display date and time in the status bar

XPI_DISTNAME=	statusbar_clock
XPI_ID=		{3669edc0-b1ad-11d8-92e7-00d09e0179f2}
XPI_NUM=	52

post-extract:
	@${RM} -rf ${WRKSRC}/readme.txt

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
