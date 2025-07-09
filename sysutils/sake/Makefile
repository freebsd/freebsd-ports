PORTNAME=	sake
PORTVERSION=	0.15.1
DISTVERSIONPREFIX=	v
PORTREVISION=	13
CATEGORIES=	sysutils

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Task runner for local and remote hosts
WWW=		https://sakecli.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	alajmo

GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/sake \
		share/man/man1/sake.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/core/sake.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
