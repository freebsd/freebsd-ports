# New ports collection makefile for:		gecko-sharp
# Date created:					20040825
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	gecko-sharp
PORTVERSION=	0.6
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/sources/gecko-sharp/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for embeding mozilla

BUILD_DEPENDS=	gapi-parser:${PORTSDIR}/x11-toolkits/gtk-sharp10
RUN_DEPENDS=	gapi-parser:${PORTSDIR}/x11-toolkits/gtk-sharp10

USE_GECKO=	firefox mozilla
USE_GNOME=	gnomehack gnometarget
LATEST_LINK=	gecko-sharp10
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
