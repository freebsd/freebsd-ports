# Created by: ijliao
# $FreeBSD$

PORTNAME=	whatmask
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://downloads.laffeycomputer.com/current_builds/whatmask/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Convert between common subnet mask notations

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
