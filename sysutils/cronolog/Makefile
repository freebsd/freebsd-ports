# New ports collection makefile for:   cronolog
# Date created:        20 January 2000
# Whom:                Mark Blackman <tmb_ports@maddog.u-net.com>
#
# $FreeBSD$
#

PORTNAME=	cronolog
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cronolog.org/download/

MAINTAINER=	shaun@inerd.com
COMMENT=	A web log rotation utility that provides datestamp filenames

INFO=		cronolog
MAN1=		cronolog.1m cronosplit.1m

GNU_CONFIGURE=	yes

OPTIONS=	SETUID_PATCH "Build with setuid functionality" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SETUID_PATCH)
MASTER_SITES+=  http://cronolog.org/patches/:patches
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} cronolog-setugid-patch.txt:patches
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
EXTRA_PATCHES=	${WRKDIR}/cronolog-setugid-patch.txt
PATCH_WRKSRC=	${WRKDIR}
USE_DOS2UNIX=	../cronolog-setugid-patch.txt

post-extract:
	${CP} ${DISTDIR}/cronolog-setugid-patch.txt ${WRKDIR}/
.endif

.include <bsd.port.post.mk>
