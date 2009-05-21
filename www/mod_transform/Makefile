# New ports collection makefile for:	mod_transform
# Date created:				5 December 2004
# Whom:					laruiss
#
# $FreeBSD$
#

PORTNAME=	mod_transform
PORTVERSION=	0.6.0
CATEGORIES=	www
MASTER_SITES=	http://www.outoforder.cc/downloads/mod_transform/

MAINTAINER=	stan@stormier.net
COMMENT=	An XSLT and XIncludes Filter module for Apache 2.0

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0
USE_AUTOTOOLS=	libtool:15
HAS_CONFIGURE=	yes
USE_GNOME=	libxslt

post-install:
	@${CAT}	${PKGMESSAGE}

.include <bsd.port.mk>
