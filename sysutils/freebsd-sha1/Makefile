# New ports collection makefile for:	FreeBSD sha1 utility
# Date created:				17 October 2004
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	freebsd-sha1
PORTVERSION=	5.3
CATEGORIES=	sysutils security
MASTER_SITES=	http://www.daemonology.net/misc/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	FreeBSD sha1 utility

WRKSRC=		${WRKDIR}/${PORTNAME:S/freebsd-//}-${PORTVERSION}
BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man/man
MAKE_ARGS=	BINDIR="${BINDIR}" MANDIR="${MANDIR}" -DNOMANCOMPRESS

MAN1=		sha1.1
PLIST_FILES=	sbin/sha1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 502113 || ( ${OSVERSION} > 491100 && ${OSVERSION} < 500000 )
IGNORE=		"sha1 now contained in the base system"
.endif

.include <bsd.port.post.mk>
