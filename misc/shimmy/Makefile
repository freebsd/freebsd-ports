PORTNAME=	shimmy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Privacy-first alternative to Ollama
WWW=		https://github.com/Michael-A-Kuykendall/shimmy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	Michael-A-Kuykendall

PLIST_FILES=	bin/create_realistic_safetensors \
		bin/create_test_safetensors \
		bin/${PORTNAME} \
		bin/test_real_safetensors
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md DEVELOPERS.md README.md \
		ROADMAP.md SECURITY.md

OPTIONS_DEFINE=		DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
