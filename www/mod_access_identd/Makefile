# New ports collection makefile for:	mod_access_identd
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	mod_access_identd
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	http://MeepZor.Com/packages/mod_access_identd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache module to supply access control based on ident reply

WRKSRC=		${WRKDIR}/${PORTNAME}
WANT_APACHE=	13
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
.include <bsd.port.post.mk>
