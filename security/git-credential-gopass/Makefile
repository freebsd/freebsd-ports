PORTNAME=	git-credential-gopass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.15.12
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${PORTNAME}/88d11d2b1b49f00b7fba9a917cf90f7ea14c9d1b/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Manage git credentials using gopass
WWW=		https://github.com/gopasspw/git-credential-gopass

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules
USE_GITHUB=	yes
GH_ACCOUNT=	gopasspw

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/git-credential-gopass

.include <bsd.port.mk>
