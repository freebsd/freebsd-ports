# $FreeBSD$

PORTNAME=	btpd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16
PORTREVISION=	3
CATEGORIES=	net-p2p

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Bittorrent client consisting of a daemon and client commands

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

USES=		autoreconf ssl

USE_GITHUB=	yes
USE_RC_SUBR=	btpd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
