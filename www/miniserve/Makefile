PORTNAME=	miniserve
DISTVERSIONPREFIX=	v
DISTVERSION=	0.35.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ad-hoc HTTP server for file sharing
WWW=		https://github.com/svenstaro/miniserve

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	the ring crate requires SSE2 instruction on intel cpu

#BUILD_DEPENDS=	zstd>0:archivers/zstd
LIB_DEPENDS=	libonig.so:devel/oniguruma \
		libzstd.so:archivers/zstd

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
