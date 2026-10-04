PORTNAME=	lazydocker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.25.2
CATEGORIES=	sysutils

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Terminal UI for both docker and docker-compose
WWW=		https://github.com/jesseduffield/lazydocker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	jesseduffield

GO_BUILDFLAGS=	-ldflags "-s -X main.version=${DISTVERSION} \
		-X main.buildSource=freebsd-ports"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
