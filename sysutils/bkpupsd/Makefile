# New ports collection makefile for: bkpupsd
# Date created:             26 May 1995
# Whom:                     Yoshifumi Watanabe <mwatts@edu1.tokyo-med.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	bkpupsd
PORTVERSION=	1.0a
CATEGORIES=	sysutils
MASTER_SITES=	ftp://edu1.tokyo-med.ac.jp/pub/contrib/bkpupsd/

MAINTAINER=	mwatts@edu1.tokyo-med.ac.jp
COMMENT=	A simple UPS daemon for APC BK Pro(TM)

MAN8=		bkpupsd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile due to deprecation of varargs.h"
.endif

.include <bsd.port.post.mk>
