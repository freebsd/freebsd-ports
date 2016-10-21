# Created by: Barbara Guida <bar@FreeBSD.org>
# $FreeBSD$

PORTNAME=	server_spy
PORTVERSION=	0.2.3
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	bar@FreeBSD.org
COMMENT=	Indicates what brand of HTTP server runs on the visited site

USE_XPI=	*firefox*

XPI_ID=		ServerSpy@jacquet.eu.org
XPI_NUM=	2036

post-patch:
	@${REINPLACE_CMD} -e 's|<em:maxVersion>22\.\*<|<em:maxVersion>99.*<|' \
		${WRKSRC}/install.rdf

pre-install:
	@${RM} ${WRKSRC}/install.rdf.bak

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
