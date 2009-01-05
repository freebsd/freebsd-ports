# New ports collection makefile for:    bpfstat
# Date created:         27 July 2005
# Whom:                 Christian S.J. Peron <csjp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bpfstat
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=     csjp

MAINTAINER=	csjp@FreeBSD.org
COMMENT=	Program to retrieve bpf statistics

MAN8=		bpfstat.8
PLIST_FILES=	sbin/bpfstat

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
IGNORE=		this has been merged into netstat
.endif

.include <bsd.port.post.mk>
