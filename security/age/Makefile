PORTNAME=	age
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
PORTREVISION=	8
CATEGORIES=	security

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple, modern and secure file encryption tool
WWW=		https://github.com/FiloSottile/age

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	filippo.io/age
GO_TARGET=	./cmd/age \
		./cmd/age-keygen

PLIST_FILES=	bin/age \
		bin/age-keygen \
		man/man1/age-keygen.1.gz \
		man/man1/age.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
