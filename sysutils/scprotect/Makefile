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

KMODDIR?=	/boot/modules

PLIST_SUB=	KMODDIR=${KMODDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	KMODDIR=${KMODDIR}
CFLAGS+=-DWITH_SCPROTECT_LIST

#MAN4=		scprotect.4
#MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel sources
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
