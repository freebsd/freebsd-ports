# New ports collection makefile for:	userspace-rcu
# Date created:		29 February 2012
# Whom:			Leo Vandewoestijne <freebsd@dns-lab.com>
#
# $FreeBSD$
#

PORTNAME=	userspace-rcu
PORTVERSION=	0.6.4
CATEGORIES=	sysutils
MASTER_SITES=	http://lttng.org/files/urcu/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	A read-copy-update data synchronization library

LICENSE=	LGPL21

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's,^\(pkgconfigdir = \).(libdir),\1${PREFIX}/libdata,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
