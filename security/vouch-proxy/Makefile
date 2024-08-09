PORTNAME=	vouch-proxy
DISTVERSIONPREFIX=v
DISTVERSION=	0.40.0
PORTREVISION=	5
CATEGORIES=	security

MAINTAINER=	decke@FreeBSD.org
COMMENT=	SSO solution for Nginx using the auth_request module
WWW=		https://github.com/vouch/vouch-proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.22

USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/vouch/vouch-proxy
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION} -X main.uname=FreeBSD"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/config && ${COPYTREE_SHARE} "config.yml*" ${STAGEDIR}${ETCDIR})

.include <bsd.port.mk>
