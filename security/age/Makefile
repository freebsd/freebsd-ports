PORTNAME=	age
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	6
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
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
		share/man/man1/age-keygen.1.gz \
		share/man/man1/age.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
