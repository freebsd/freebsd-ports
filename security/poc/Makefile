# New ports collection makefile for:	poc
# Date created:		Tue Jun 11 22:43:06 CEST 2002
# Whom:			king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	poc
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=poc

MAINTAINER=	king@v2project.com
COMMENT=	Program for managing passwords on smartcards

LIB_DEPENDS=	towitoko.2:${PORTSDIR}/devel/towitoko

PLIST_FILES=	bin/poc
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
