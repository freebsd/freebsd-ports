# New ports collection makefile for:	privoxy
# Date created:				21 November 2002
# Whom:					John von Essen
#
# $FreeBSD$
#

PORTNAME=	privoxy
PORTVERSION=	3.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ijbswa
DISTNAME=	privoxy-3.0.0-stable-src

MAINTAINER=	john@essenz.com

WRKSRC=		${WRKDIR}/privoxy-3.0.0-stable

USE_GMAKE=	yes
USE_AUTOCONF=	yes

MAKEFILE=	GNUmakefile

MAN1=		privoxy.1

pre-configure:
	@(cd ${WRKSRC}; autoheader${USE_AUTOCONF_VER})

.include <bsd.port.mk>
