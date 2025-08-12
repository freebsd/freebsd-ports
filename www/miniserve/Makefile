PORTNAME=	miniserve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.31.0
CATEGORIES=	www

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ad-hoc HTTP server for file sharing
WWW=		https://github.com/svenstaro/miniserve

LICENSE=	APACHE20 BSD3CLAUSE CC0-1.0 ISCL MIT MPL20 UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	the ring crate requires SSE2 instruction on intel cpu

BUILD_DEPENDS=	zstd>0:archivers/zstd
LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo ssl:build
USE_GITHUB=	yes
GH_ACCOUNT=	svenstaro

PLIST_FILES=	bin/miniserve
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
