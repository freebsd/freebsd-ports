# New ports collection makefile for:	buffy
# Date Created:				13 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buffy
PORTVERSION= 	0.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://reality.sgi.com/offer/src/buffy/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

FETCH_BEFORE_ARGS=	-b

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
#USE_GMAKE=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
