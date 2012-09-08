# New ports collection makefile for:   userfw
# Date created:        10 Mar 2012
# Whom:                Maxim Ignatenko
#
# $FreeBSD$
#

PORTNAME=	userfw
PORTVERSION=	0.1.2
CATEGORIES=	net kld
MASTER_SITES=	http://userfw.net/files/release/ \
		http://imax.in.ua/files/ \
		http://projects.ukrweb.net/files/ \
		https://github.com/downloads/gelraen/userfw/

MAINTAINER=	gelraen.ua@gmail.com
COMMENT=	Modular packet filter

LICENSE=	BSD

USE_XZ=		yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
CMAKE_OUTSOURCE=	yes

KMODDIR?=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.x
.endif

.if !exists(${SRC_BASE}/sys/sys/module.h)
IGNORE=		requires kernel source files
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

CMAKE_ARGS+=	-DDOMAIN_STUB:BOOL=OFF
CMAKE_ARGS+=	-DOPCODE_VERIFICATION:BOOL=OFF

.include <bsd.port.post.mk>
