# New ports collection makefile for:	clean-theme-gtk
# Date Created:				1 June 2000
# Whom:				 	Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clean-theme-gtk
PORTVERSION= 	0.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://progen.dynodns.net/dengen/cleantheme/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/gtk-clean-theme

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
