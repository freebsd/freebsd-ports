# New ports collection makefile for:   cronolog-beta
# Date created:        10 November 2010
# Whom:                Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	cronolog
PORTVERSION=	1.7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://cronolog.org/patches/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	A web log rotation utility that provides datestamp filenames

PLIST_FILES=	sbin/cronolog \
		sbin/cronosplit

CONFLICTS=	cronolog-[0-9]*

WRKSRC=		${WRKDIR}/cronolog-${PORTVERSION}
INFO=		cronolog
MAN1=		cronolog.1m cronosplit.1m

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
