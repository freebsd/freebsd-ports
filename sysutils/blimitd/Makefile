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
MASTER_SITES=	ftp://ftp.ugh.net.au/pub/unix/blimitd/ \
		ftp://ftp.megamirror.com/pub/ugh/unix/blimitd/ \
		http://ftp.megamirror.com/pub/ugh/unix/blimitd/

MAINTAINER=	andrew@ugh.net.au
COMMENT=	Daemon to enforce login.conf limits

WRKSRC=		${WRKDIR}/blimitd

MAN8=		blimitd.8
MANCOMPRESSED=	maybe

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/blimitd.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/blimitd.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/blimitd.sh ${PREFIX}/etc/rc.d/blimitd.sh; \
	fi

.include <bsd.port.mk>
