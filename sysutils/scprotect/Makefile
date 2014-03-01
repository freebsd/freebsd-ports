# Created by: Denis Barov  <dindin@dindin.ru>
# $FreeBSD$

PORTNAME=	scprotect
PORTVERSION=	20091116
CATEGORIES=	sysutils kld
MASTER_SITES=	http://dindin.ru/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Protect process from killing when the swap space is exhausted

NO_PACKAGE=	Needs to be compiled for specific kernel
SSP_UNSAFE=	kernel module does not support ssp

USES=		kmod

WRKSRC=		${WRKDIR}/${PORTNAME}

CFLAGS+=	-DWITH_SCPROTECT_LIST

.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel sources
.endif

post-extract:
	@cd ${WRKSRC}/kmod && ${RM} -f machine

.include <bsd.port.post.mk>
