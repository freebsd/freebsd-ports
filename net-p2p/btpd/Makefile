# $FreeBSD$

PORTNAME=	btpd
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	net-p2p
MASTER_SITES=	http://cloud.github.com/downloads/btpd/btpd/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Bittorrent client consisting of a daemon and client commands

LICENSE=	BSD

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

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
