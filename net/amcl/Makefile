# New ports collection makefile for:	amcl
# Date created:				15 Apr 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=		amcl
PORTVERSION=		0.7.0
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.sourceforge.net/pub/sourceforge/amcl/ \
			http://www.localhost.nu/apps/amcl/tars/ \
			http://amcl.alliances.org/tars/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/muds
DISTNAME=		${PORTNAME}-${PORTVERSION}pl1

MAINTAINER=		will@FreeBSD.org

LIB_DEPENDS=		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config
WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
