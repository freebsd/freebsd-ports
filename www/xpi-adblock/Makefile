# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	adblock
PORTVERSION=	0.5.3.043
DISTVERSIONSUFFIX=	-fx+fl+mz+ns
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Content filtering extension

XPI_NUM=	10
XPI_ID=		{34274bf4-1d97-a289-e984-17e546307e4f}
XPI_FILES=	chrome/adblock.jar chrome.manifest components/.autoreg components/nsAdblock.js \
		defaults/preferences/adblock.js install.js install.rdf license.txt
XPI_DIRS=	chrome/adblock chrome components defaults/preferences defaults

post-patch:
	@${REINPLACE_CMD} -e 's|2.0a3|2.0.*|g' ${WRKSRC}/install.rdf
	@${RM} ${WRKSRC}/install.rdf?*

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
