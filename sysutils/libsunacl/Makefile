# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsunacl
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Wrapper providing SunOS NFSv4 ACL API

USE_LDCONFIG=	yes
PLIST_FILES=	include/sunacl.h lib/libsunacl.a lib/libsunacl.so.1 lib/libsunacl.so

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		no NFSv4 ACL support before FreeBSD 8.0
.endif

.if !defined(NO_PROFILE)
PLIST_FILES+=	lib/libsunacl_p.a
.endif

.include <bsd.port.post.mk>
