# New ports collection makefile for:	btpd
# Date created:		2008-11-14
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	btpd
PORTVERSION=	0.15
CATEGORIES=	net-p2p
MASTER_SITES=	http://www.murmeldjur.se/btpd/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Bittorrent  client consisting of a daemon and client commands

USE_AUTOTOOLS=	autoconf:262 aclocal:110
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/btcli \
		bin/btinfo \
		bin/btpd

PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
