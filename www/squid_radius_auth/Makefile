# New ports collection makefile for: squid_radius_auth
# Date created: 18 October 2005
# Whom: Michael Capp <myntric@exeonline.com>
#
# $FreeBSD$
#

PORTNAME=	squid_radius_auth
PORTVERSION=	1.0.8
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/contrib/squid_radius_auth/ \
		http://www.exeonline.com/downloads/
DISTNAME=	squid_radius_auth-1.08
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://www.exeonline.com/downloads/
PATCHFILES=	squid_radius_freebsd.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	myntric@exeonline.com
COMMENT=	RADIUS authenticator for squid proxy 2.5 and later

MAN8=		squid_radius_auth.8

.include <bsd.port.mk>
