# Created by: Max Laier <max@love2party.net>
# $FreeBSD$

PORTNAME=	pftop
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for real-time display of statistics for pf

MAN8=		pftop.8

MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900039
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=41
CFLAGS+=	-DHAVE_ALTQ=1
.else
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=45
CFLAGS+=	-DHAVE_ALTQ=1 -DHAVE_SNPRINTF=1 -DHAVE_VSNPRINTF=1
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cache.c \
		${FILESDIR}/extra-patch-cache.h \
		${FILESDIR}/extra-patch-config.h \
		${FILESDIR}/extra-patch-pftop.c \
		${FILESDIR}/extra-patch-sf-gencode.c
.if ${OSVERSION} > 1000017
CFLAGS+=	-DHAVE_FINE_GRAINED_LOCKING=1
.endif
.endif

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-engine.c

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
