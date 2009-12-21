# New ports collection makefile for:	minissdpd
# Date created:				20 Dec 2009
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	minissdpd
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://miniupnp.free.fr/files/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	UPnP IGD discovery speed enhancer

USE_RC_SUBR=	minissdpd
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-D_GNU_SOURCE

MAN1=		minissdpd.1
PLIST_FILES=	sbin/minissdpd

post-patch:
	@${REINPLACE_CMD} -E '/^(CC|CFLAGS)/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
