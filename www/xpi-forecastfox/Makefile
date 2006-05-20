# New ports collection makefile for:	forecastfox
# Date created:		2006-05-15
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	forecastfox
PORTVERSION=	0.9.0.2
DISTVERSIONSUFFIX=	-fx+fl+mz+ns+zm
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Get international weather forecasts and display it

XPI_ID=		{0538E3E3-7E9B-4d49-8831-A227C80A7AD3}

post-patch:
	@${REINPLACE_CMD} -e \
		's|install = this._app.clone();|install = app.clone();|g' \
		${WRKSRC}/components/ffDisk.js
	@${RM} -f ${WRKSRC}/components/ffDisk.js.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
