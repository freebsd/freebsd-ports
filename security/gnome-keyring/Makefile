# New ports collection makefile for:   gnomekeyring
# Date Created:			08 December 2003
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/security/gnomekeyring/Makefile,v 1.2 2006/03/13 23:28:20 mezz Exp $
#

PORTNAME=	gnomekeyring
PORTVERSION=	0.4.9
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-keyring/0.4
DISTNAME=	gnome-keyring-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program that keeps passwords and other secrets

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gtk20
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
