# New ports collection makefile for:	libspiff
# Date Created:				19 Mar 2007
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	libspiff
DISTVERSION=	0.6.1rc1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libspiff

MAINTAINER=	ed@fxq.nl
COMMENT=	An XSPF parsing library

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-expat=${LOCALBASE}

USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes

.include <bsd.port.mk>
