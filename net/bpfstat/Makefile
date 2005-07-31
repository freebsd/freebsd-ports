# New ports collection makefile for:    bpfstat
# Date created:         27 July 2005
# Whom:                 Christian S.J. Peron <csjp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bpfstat
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://people.freebsd.org/~csjp/

MAINTAINER=	csjp@FreeBSD.org
COMMENT=	Program to retrieve bpf statistics

MAN8=		bpfstat.8
PLIST_FILES=	sbin/bpfstat

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600033
IGNORE=		will only work on systems >= 600033
.endif

.include <bsd.port.post.mk>
