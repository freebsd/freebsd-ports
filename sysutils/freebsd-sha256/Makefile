# New ports collection makefile for:	FreeBSD sha256 utility
# Date created:				10 March 2004
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	freebsd-sha256
PORTVERSION=	20050310
CATEGORIES=	sysutils security
MASTER_SITES=	http://www.daemonology.net/misc/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	FreeBSD sha256 utility

BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man/man
MAKE_ARGS=	BINDIR="${BINDIR}" MANDIR="${MANDIR}" -DNOMANCOMPRESS

MAN1=		sha256.1
PLIST_FILES=	sbin/sha256

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 600020
IGNORE=		"sha256 now contained in the base system"
.endif

.include <bsd.port.post.mk>
