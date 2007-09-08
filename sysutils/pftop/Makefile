# New ports collection makefile for:	pfflowd
# Date created:		23 June 2003
# Whom:			Max Laier <max@love2party.net>
#
# $FreeBSD$
#

PORTNAME=	pftop
PORTVERSION=	0.6
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	mlaier@freebsd.org
COMMENT=	Utility for real-time display of statistics for pf

MAN8=		pftop.8

MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502106
IGNORE=		only for 5.3 and above
.endif

.if ${OSVERSION} < 502116
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=34
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
CFLAGS+=	-DHAVE_ALTQ=1
.endif
.elif ${OSVERSION} < 600025
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=35
CFLAGS+=	-DHAVE_ALTQ=1 -DHAVE_RULE_ANCHOR=1
.elif ${OSVERSION} < 700049
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=37
CFLAGS+=	-DHAVE_ALTQ=1
.else
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=41
CFLAGS+=	-DHAVE_ALTQ=1
.endif

PLIST_FILES=	sbin/pftop

post-patch:
	@${REINPLACE_CMD} -e 's|<sys/queue.h>|"${FILESDIR}/queue.h"|g' \
	    ${WRKSRC}/engine.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
