# New ports collection makefile for:	free-sa
# Date created:				22 Mar 2007
# Whom:					Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	free-sa
PORTVERSION=	1.6.0
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	toxa@toxahost.ru
COMMENT=	Statistic analyzer for daemons log files similar to SARG

PORTDOCS=	COPYING INSTALL README README.DEV ChangeLog FAQ THANKS
DOCSDIR=	share/doc/free-sa-${DISTVERSION}
MAKE_JOBS_SAFE=	yes

MAN1=	free-sa.1
MAN5=	free-sa.conf.5

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
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

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS =.*,CFLAGS = -I. -I.. ${CFLAGS},' ${WRKSRC}/global.mk

.include <bsd.port.post.mk>
