PORTNAME=	mdbook
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.36
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Create book from Markdown files (like GitBook but implemented in Rust)
WWW=		https://rust-lang.github.io/mdBook/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo cpe
CPE_VENDOR=	rust-lang
USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang
GH_PROJECT=	mdBook

PLIST_FILES=	bin/mdbook

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mdbook

.include <bsd.port.mk>
