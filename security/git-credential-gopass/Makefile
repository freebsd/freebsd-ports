PORTNAME=	git-credential-gopass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16.0
CATEGORIES=	security

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Manage git credentials using gopass
WWW=		https://github.com/gopasspw/git-credential-gopass

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules
USE_GITHUB=	yes
GH_ACCOUNT=	gopasspw

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/git-credential-gopass

.include <bsd.port.mk>
