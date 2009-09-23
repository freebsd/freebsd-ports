# New ports collection makefile for:	pmap
# Date created:		14 Oct 2002
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	pmap
PORTVERSION=	20060622
PORTREVISION=	1
CATEGORIES=	sysutils kld
MASTER_SITES=	${MASTER_SITE_LOCAL:S!$!skv/!} \
		ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/pmap/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Detailed process memory display

NO_PACKAGE=	Depends on kernel

KMODDIR=	/boot/modules

PLIST_SUB=	KMODDIR=${KMODDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	KMODDIR=${KMODDIR}

MAN8=		pmap.8
MANCOMPRESSED=	maybe

.include <bsd.port.pre.mk>

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel sources
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
