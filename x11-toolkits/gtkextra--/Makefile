# New ports collection makefile for:	gtkextra--
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkextramm
PORTVERSION=	0.7.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtkextra.10:${PORTSDIR}/x11-toolkits/gtkextra \
		gtkmm-1.2.0:${PORTSDIR}/x11-toolkits/gtk--

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		PERL="${PERL}"

.include <bsd.port.mk>
