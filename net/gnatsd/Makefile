# $FreeBSD$

PORTNAME=	gnatsd
PORTVERSION=	1.0.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Messaging system written in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io

USE_RC_SUBR=	gnatsd.sh

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${FILESDIR}/gnatsd.conf ${STAGEDIR}${PREFIX}/etc/gnatsd.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/server && ${COPYTREE_SHARE} configs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
