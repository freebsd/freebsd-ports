# New ports collection makefile for:	pfflowd
# Date created:		23 June 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	pftop
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	mlaier@FreeBSD.org
COMMENT=	Utility for real-time display of statistics for pf

MAN8=		pftop.8

MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700049
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=37
CFLAGS+=	-DHAVE_ALTQ=1
.elif ${OSVERSION} < 900000
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=41
CFLAGS+=	-DHAVE_ALTQ=1
.else
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=45
CFLAGS+=	-DHAVE_ALTQ=1 -DHAVE_SNPRINTF=1 -DHAVE_VSNPRINTF=1
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cache.c \
		${FILESDIR}/extra-patch-cache.h \
		${FILESDIR}/extra-patch-config.h \
		${FILESDIR}/extra-patch-engine.c \
		${FILESDIR}/extra-patch-pftop.c \
		${FILESDIR}/extra-patch-sf-gencode.c
.endif

MAKE_ENV+=	__MAKE_CONF=/dev/null

PLIST_FILES=	sbin/pftop

post-patch:
	@${REINPLACE_CMD} -e 's|<sys/queue.h>|"${FILESDIR}/queue.h"|g' \
	    ${WRKSRC}/engine.c
	@${REINPLACE_CMD} -e 's|__dead|__dead2|g' ${WRKSRC}/sf-gencode.h
	@${REINPLACE_CMD} -e 's|__dead|__dead2|g' ${WRKSRC}/sf-gencode.c
	@${REINPLACE_CMD} -e 's|__inline__|static __inline__|g' ${WRKSRC}/pftop.c
	@${REINPLACE_CMD} -e 's|#include <net/if_pflog.h>||g' \
	    ${WRKSRC}/sf-gencode.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
