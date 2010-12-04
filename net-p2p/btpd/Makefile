# New ports collection makefile for:	btpd
# Date created:		2008-11-14
# Whom:			bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	btpd
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://cloud.github.com/downloads/btpd/btpd/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Bittorrent client consisting of a daemon and client commands

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_AUTOTOOLS=	autoconf aclocal
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

PLIST_FILES=	bin/btcli \
		bin/btinfo \
		bin/btpd
MAN1=		btcli.1 \
		btinfo.1 \
		btpd.1

PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
