# Created by: Max Laier <max@love2party.net>
# $FreeBSD$

PORTNAME=	pftop
PORTVERSION=	0.7
PORTREVISION=	7
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Utility for real-time display of statistics for pf

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1100080
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bpf_dump.c \
		${FILESDIR}/extra-patch-sf-gencode.h
.endif

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

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-engine.c

MAKE_ARGS+=	CSTD=gnu89
MAKE_ENV+=	__MAKE_CONF=/dev/null

PLIST_FILES=	sbin/pftop man/man8/pftop.8.gz

post-patch:
.if ${OSVERSION} >= 1100000
	@${ECHO_MSG} "===> Applying FairQ/Codel patches to ${PORTNAME}."
	@${CAT} ${FILESDIR}/extra-patch-fairq_codel.diff | \
		${PATCH} ${PATCH_ARGS}
.endif
	@${REINPLACE_CMD} -e 's|<sys/queue.h>|"${FILESDIR}/queue.h"|g' \
	    ${WRKSRC}/engine.c
	@${REINPLACE_CMD} -e 's|__dead|__dead2|g' ${WRKSRC}/sf-gencode.h
	@${REINPLACE_CMD} -e 's|__dead|__dead2|g' ${WRKSRC}/sf-gencode.c
	@${REINPLACE_CMD} -e 's|#include <net/if_pflog.h>||g' \
	    ${WRKSRC}/sf-gencode.c
.if ${OPSYS} == DragonFly || ${OSVERSION} >= 1100070
	@${REINPLACE_CMD} -e 's|altq/|net/&|' ${WRKSRC}/pftop.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.post.mk>
