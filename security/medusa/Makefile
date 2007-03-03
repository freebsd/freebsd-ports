# New ports collection makefile for:	medusa
# Date created:		2006-05-01
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	medusa
PORTVERSION=	1.3
CATEGORIES=	security
MASTER_SITES=	http://www.foofus.net/jmk/tools/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A speedy, massively parallel, modular, login brute-forcer

OPTIONS=	SVN "Enable Subversion module" off \
		POSTGRESQL "Enable PostgreSQL module" off

LIB_DEPENDS+=	ssh2:${PORTSDIR}/security/libssh2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-untested --program-transform=

MAN1=		medusa.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	pth.20:${PORTSDIR}/devel/pth
CFLAGS+=	-L${LOCALBASE}/lib/pth
USE_GCC=	3.2+
.endif

.if defined(WITH_SVN)
LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion
CFLAGS+=	-I${LOCALBASE}/include/subversion-1 -I${LOCALBASE}/include/apr-1
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
.endif

.include <bsd.port.post.mk>
