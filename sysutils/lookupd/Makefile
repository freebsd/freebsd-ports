# Created by: Michael Bushkov <bushman@rsu.ru>
# $FreeBSD$

PORTNAME=	lookupd
PORTVERSION=	0.3.c
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://sfedu.ru/~bushman/lookupd/downloads/

MAINTAINER=	bushman@rsu.ru
COMMENT=	Lookupd daemon - IPC nsswitch implementation with system-wide caching

USE_LDCONFIG=	yes
USE_RC_SUBR=	lookupd
SUB_FILES=	pkg-message

MAKE_ENV=	WARNS=0

MAN5=		lookupd.conf.5
MAN8=		lookupd.8

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.include <bsd.port.post.mk>
