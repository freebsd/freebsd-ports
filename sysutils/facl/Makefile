PORTNAME=	facl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI and CLI for NFSv4 ACLs
WWW=		https://github.com/olgeni/facl

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/olgeni/facl

PLIST_FILES=	bin/facl \
		share/man/man1/facl.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/facl.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
