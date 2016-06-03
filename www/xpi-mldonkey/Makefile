# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mldonkey
PORTVERSION=	2.5
CATEGORIES=	www net-p2p
MASTER_SITES=	http://www.informatik.uni-oldenburg.de/~dyna/${PORTNAME}/xpi/ LOCAL/chinsan/xpi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ed2k, magnet and sig2dat protocol handler

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

XPI_DISTNAME=	mldonkey_protocol_handler
XPI_ID=		{bc72206d-b3ce-4b49-88b9-d59b388a0cde}
XPI_FILES=	chrome/mldonkey.jar components/ed2kprotocol.js defaults/preferences/defaultprefs.js \
		install.rdf chrome.manifest
XPI_DIRS=	chrome components defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
