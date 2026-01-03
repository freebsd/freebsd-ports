PORTNAME=	ncgopher
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	www

MAINTAINER=	ports@freebsd.org
COMMENT=	Fast and modern Gopher, Gemini and finger terminal client
WWW=		https://github.com/jansc/ncgopher

LICENSE=	BSD2CLAUSE APACHE20 BSD3CLAUSE MIT UNLICENSE ZLIB
LICENSE_COMB=	multi

USES=		cargo ssl sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	jansc
PLIST_FILES=	bin/ncgopher \
		share/man/man1/ncgopher.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/ncgopher.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
