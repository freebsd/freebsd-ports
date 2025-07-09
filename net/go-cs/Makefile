PORTNAME=	go-cs
PORTVERSION=	0.9
DISTVERSIONPREFIX=	v
PORTREVISION=	29
CATEGORIES=	net

MAINTAINER=	akosela@andykosela.com
COMMENT=	Concurrent ssh client
WWW=		https://github.com/akosela/go-cs

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	akosela

CONFLICTS_INSTALL=	clearsilver csound # bin/cs

PLIST_FILES=	bin/cs share/man/man1/cs.1.gz

GO_TARGET=	./cs

post-install:
	${INSTALL_MAN} ${WRKSRC}/cs.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
