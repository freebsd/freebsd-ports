# New ports collection makefile for:	poc
# Date created:		Tue Jun 11 22:43:06 CEST 2002
# Whom:			king@v2project.com
#
# $FreeBSD$
#

PORTNAME=	poc
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=poc

MAINTAINER=	king@v2project.com

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		towitoko.2:${PORTSDIR}/devel/towitoko

USE_GMAKE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lgnugetopt"

.include <bsd.port.mk>
