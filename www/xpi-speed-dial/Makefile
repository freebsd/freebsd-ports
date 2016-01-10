# Created by: Harald Schmalzbauer <h.schmalzbauer@omnisec.de>
# $FreeBSD$

PORTNAME=	speed-dial
PORTVERSION=	0.9.6.17
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www
MASTER_SITES=	http://speeddial.uworks.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access websites through custom thumbnail views

USES=	zip

XPI_DISTNAME=	speed_dial
XPI_ID=		{64161300-e22b-11db-8314-0800200c9a66}
XPI_NUM=	4810

post-patch:
	@${REINPLACE_CMD} -i "" -e '/loadInNewTab/s|false|true|' \
		${WRKSRC}/defaults/preferences/speeddial.js

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
