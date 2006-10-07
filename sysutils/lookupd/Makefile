# New ports collection makefile for:	lookupd
# Date created:				3 July 2004
# Whom:					Michael Bushkov <bushman@rsu.ru>
#
# $FreeBSD$

PORTNAME=	lookupd
PORTVERSION=	0.3.c
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsu.ru/~bushman/lookupd/downloads/

MAINTAINER=	bushman@rsu.ru
COMMENT=	Lookupd daemon - IPC nsswitch implementation with system-wide caching

USE_LDCONFIG=	yes
USE_RC_SUBR=	lookupd
SUB_FILES=	pkg-message

MAKE_ENV=	WARNS=0

MAN5=		lookupd.conf.5
MAN8=		lookupd.8

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500112
IGNORE=		is only supported on FreeBSD 5.1 or later
.endif

.include <bsd.port.post.mk>
