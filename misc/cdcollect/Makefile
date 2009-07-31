# New ports collection makefile for:	cdcollect
# Date created:				09 April 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	cdcollect
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	misc gnome
MASTER_SITES=	SF

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A simple CD catalog for GNOME

BUILD_DEPENDS=	sqlite3>=3.0:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnome gnomesharp20
GCONF_SCHEMAS=	cdcollect.schemas
USE_GETTEXT=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
