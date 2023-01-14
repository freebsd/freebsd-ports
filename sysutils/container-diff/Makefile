PORTNAME=	container-diff
PORTVERSION=	0.17.0
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	sysutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Diff your Docker containers
WWW=		https://github.com/GoogleContainerTools/container-diff

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/container-diff

GH_ACCOUNT=	GoogleContainerTools
USE_GITHUB=	yes

.include <bsd.port.mk>
