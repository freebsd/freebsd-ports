# $FreeBSD$

PORTNAME=	btpd
PORTVERSION=	0.16
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://cloud.github.com/downloads/btpd/btpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bittorrent client consisting of a daemon and client commands

LICENSE=	BSD

OPTIONS_DEFINE=	DOCS

USE_AUTOTOOLS=	autoconf aclocal
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
