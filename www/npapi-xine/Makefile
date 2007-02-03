# New ports collection makefile for:	npapi-xine
# Date created:		03 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xine
PORTVERSION=	1.0
DISTVERSIONPREFIX=	plugin-
CATEGORIES=     www multimedia
MASTER_SITES=	SF
PKGNAMEPREFIX=	npapi-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Embed Xine player into browser

LIB_DEPENDS=	xine.16:${PORTSDIR}/multimedia/libxine

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_NPAPI=	native
NPAPI_ID=	${PORTNAME}
NPAPI_WRKSRC=	${WRKSRC}/src/.libs
NPAPI_FILES=	xineplugin.so

.include "${.CURDIR}/../linux-mplayer-plugin/Makefile.npapi"
.include <bsd.port.mk>
