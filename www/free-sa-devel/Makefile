# New ports collection makefile for:	free-sa-devel
# Date created:				27 Jul 2009
# Whom:					Alexander Moisseev <moiseev@mezonplus.ru>
#
# $FreeBSD$
#

PORTNAME=	free-sa
PORTVERSION=	2.0.0b2
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	free-sa/free-sa-dev/2.0.0b2%20_Big%20Change%20Edition_/
PKGNAMESUFFIX=	-devel

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Statistic analyzer for daemons log files similar to SARG

MAKE_JOBS_SAFE=	yes
CONFLICTS=	free-sa-[0-9]*
LATEST_LINK=	free-sa-devel

WWWDIR?=	${PREFIX}/www/data/${PORTNAME}
DOCSDIR=	share/doc/free-sa-${DISTVERSION}

PORTDOCS=	COPYING ChangeLog FAQ INSTALL README README.DEV THANKS
MAN1=		free-sa.1
MAN5=		free-sa.conf.5

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not configure on sparc64
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile
.endif

.if (${OSVERSION} >= 700000 && ${OSVERSION} <= 800000)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-global-native.mk
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-global-i386.mk
.if ${ARCH} != "i386"
BROKEN=		build fails with error: CPU you selected does not support x86-64 instruction set
.endif
.endif

.include <bsd.port.post.mk>
