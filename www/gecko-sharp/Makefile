# New ports collection makefile for:		gecko-sharp
# Date created:					20040825
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	gecko-sharp
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/archive/1.0.3/

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Mono bindings for embeding mozilla

BUILD_DEPENDS=	gapi-parser:${PORTSDIR}/x11-toolkits/gtk-sharp
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${X11BASE}/lib/mozilla/components/libwidget_gtk2.so:${PORTSDIR}/www/mozilla

USE_GNOME=	gnomehack gnometarget
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
