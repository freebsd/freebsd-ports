# New ports collection makefile for:	blimitd
# Date created:		29 Jul 2001
# Whom:			Andrew Stevenson <andrew@ugh.net.au>
#
# $FreeBSD$
#

PORTNAME=	blimitd
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon to enforce login.conf limits

WRKSRC=		${WRKDIR}/blimitd

MAN8=		blimitd.8
MANCOMPRESSED=	maybe

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/blimitd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/blimitd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/blimitd.sh ${PREFIX}/etc/rc.d/blimitd.sh; \
	fi

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900007
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-utmpx
.endif

.include <bsd.port.post.mk>
