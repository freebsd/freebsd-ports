PORTNAME=	sttr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.26
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	se@FreeBSD.org
COMMENT=	Quickly run various transformations on strings
WWW=		https://github.com/abhimanyu003/sttr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules,1.23
GO_MODULE=	github.com/abhimanyu003/sttr
GO_MOD_DIST=	github

USE_GITHUB=	yes
GH_ACCOUNT=	abhimanyu003

PLIST_FILES=	bin/sttr

.include <bsd.port.mk>
