PORTNAME=	mdbook
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.52
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
PORTEXAMPLES=	examples guide test_book

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${PORTEXAMPLES}" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
