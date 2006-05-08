# New ports collection makefile for:	xpi-mldonkey
# Date created:		18 April 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	1.7
CATEGORIES=	www net-p2p
MASTER_SITES=	http://www.informatik.uni-oldenburg.de/~dyna/${PORTNAME}/${PORTVERSION}/
DISTNAME=	mldonkey_protocol_handler-${PORTVERSION}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A ed2k, magnet and sig2dat protocol handling extension

XPI_ID=		{bc72206d-b3ce-4b49-88b9-d59b388a0cde}
XPI_FILES=	components/ed2kprotocol.js contents.rdf install.js install.rdf chrome.manifest
XPI_DIRS=	components

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
