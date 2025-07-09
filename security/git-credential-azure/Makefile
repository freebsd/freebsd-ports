PORTNAME=	git-credential-azure
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Git credential helper for Azure Repos
WWW=		https://github.com/hickford/git-credential-azure

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	hickford

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/git-credential-azure

.include <bsd.port.mk>
