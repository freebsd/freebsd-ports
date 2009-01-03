# New ports collection makefile for:	xpi-mldonkey
# Date created:		18 April 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	2.5
CATEGORIES=	www net-p2p
MASTER_SITES=	http://www.informatik.uni-oldenburg.de/~dyna/${PORTNAME}/xpi/ LOCAL/chinsan/xpi

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A ed2k, magnet and sig2dat protocol handler

XPI_DISTNAME=	mldonkey_protocol_handler
XPI_ID=		{bc72206d-b3ce-4b49-88b9-d59b388a0cde}
XPI_FILES=	chrome/mldonkey.jar components/ed2kprotocol.js defaults/preferences/defaultprefs.js \
		install.rdf chrome.manifest
XPI_DIRS=	chrome components defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
