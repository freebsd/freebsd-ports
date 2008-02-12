# New ports collection makefile for:	libspiff
# Date Created:				19 Mar 2007
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	libspiff
PORTVERSION=	0.8.2
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ed@fxq.nl
COMMENT=	An XSPF parsing library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		uriparser.1:${PORTSDIR}/net/uriparser

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-expat=${LOCALBASE}

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

.include <bsd.port.mk>
