# Created by: Max Laier <max@love2party.net>
# $FreeBSD$

PORTNAME=	pftop
PORTVERSION=	0.7
PORTREVISION=	9
CATEGORIES=	sysutils net

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Utility for real-time display of statistics for pf

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	araujobsd

OPTIONS_DEFINE=	ALTQ

ALTQ_DESC=	ALTQ support for queue statistics

.include <bsd.port.options.mk>

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bpf_dump.c \
		${FILESDIR}/extra-patch-sf-gencode.h

MAKE_ARGS=	LOCALBASE="${PREFIX}" \
		OSLEVEL=45
CFLAGS+=	-DHAVE_SNPRINTF=1 -DHAVE_VSNPRINTF=1 \
		-DHAVE_FINE_GRAINED_LOCKING=1

.if ${PORT_OPTIONS:MALTQ}
CFLAGS+=	-DHAVE_ALTQ=1
.endif

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-cache.c ${FILESDIR}/extra-patch-cache.h \
		${FILESDIR}/extra-patch-config.h \
		${FILESDIR}/extra-patch-pftop.c \
		${FILESDIR}/extra-patch-sf-gencode.c

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-engine.c

MAKE_ARGS+=	CSTD=gnu89
MAKE_ENV+=	__MAKE_CONF=/dev/null

PLIST_FILES=	sbin/pftop \
		man/man8/pftop.8.gz

post-patch:
	@${ECHO_MSG} "===> Applying FairQ/Codel patches to ${PORTNAME}."
	@${CAT} ${FILESDIR}/extra-patch-fairq_codel.diff | \
		${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS}
	@${REINPLACE_CMD} -e 's|<sys/queue.h>|"${FILESDIR}/queue.h"|g' \
		${WRKSRC}/engine.c
	@${REINPLACE_CMD} -e 's|__dead|__dead2|g' \
		${WRKSRC}/sf-gencode.h
	@${REINPLACE_CMD} -e 's|__dead|__dead2|g' \
		${WRKSRC}/sf-gencode.c
	@${REINPLACE_CMD} -e 's|#include <net/if_pflog.h>||g' \
		${WRKSRC}/sf-gencode.c
	@${REINPLACE_CMD} -e 's|altq/|net/&|' \
		${WRKSRC}/pftop.c
	@${REINPLACE_CMD} -e 's|#include .pcap-int.h.|#include <pcap/pcap.h>|g' \
		${WRKSRC}/bpf_image.c \
		${WRKSRC}/bpf_optimize.c \
		${WRKSRC}/pcap-nametoaddr.c \
		${WRKSRC}/sf-gencode.c \
		${WRKSRC}/sf-gencode.h \
		${WRKSRC}/sf-grammer.y \
		${WRKSRC}/sf-scanner.l

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 \
		${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
