PORTNAME=	btpd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16
PORTREVISION=	4
CATEGORIES=	net-p2p

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Bittorrent client consisting of a daemon and client commands
WWW=		https://github.com/btpd/btpd/wiki

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

DEPRECATED=	Abandoned upstream, lacks support for common functionality such as Magnet links, DHT, PEX and HTTPS. Consider net-p2p/qbittorrent or net-p2p/transmission
EXPIRATION_DATE=2024-03-31

USES=		autoreconf ssl

USE_GITHUB=	yes
USE_RC_SUBR=	btpd

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
