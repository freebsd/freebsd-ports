# New ports collection makefile for:	gtkextra--
# Date created:				17 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkextramm
PORTVERSION=	0.9.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gtkextra.14:${PORTSDIR}/x11-toolkits/gtkextra \
		gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	PERL="${PERL}"

.include <bsd.port.mk>
