# New ports collection makefile for:	evolution-caldav
# Date created:				31 August 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/evolution-caldav/Makefile,v 1.1 2005/08/31 21:40:00 marcus Exp $
#

PORTNAME=	caldav
PORTVERSION=	2.3.99.3
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PKGNAMEPREFIX}${PORTNAME}/2.3
PKGNAMEPREFIX=	evolution-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CalDAV provider for Evolution

BUILD_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	evolution-${EVO_VERSION}:${PORTSDIR}/mail/evolution

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

EVO_VERSION=	2.4
PLIST_SUB=	EVO_VERSION=${EVO_VERSION} EDS_VERSION="1.2"

.include <bsd.port.mk>
