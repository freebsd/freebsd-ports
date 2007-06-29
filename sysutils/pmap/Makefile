# New ports collection makefile for:	pmap
# Date created:		14 Oct 2002
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	pmap
PORTVERSION=	20060622
CATEGORIES=	sysutils kld
MASTER_SITES=	${MASTER_SITE_LOCAL:S!$!skv/!} \
		ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/pmap/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Detailed process memory display

NO_PACKAGE=	Depends on kernel

PLIST_SUB=	KMODDIR=${KMODDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN8=		pmap.8
MANCOMPRESSED=	maybe

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BROKEN=		Currently does not support -CURRENT
.endif

.if ${OSVERSION} <  600000
IGNORE=		not supported on systems prior to 6.0
.endif

pre-fetch:
.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel sources
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
