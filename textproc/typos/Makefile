PORTNAME=	typos
PORTVERSION=	1.39.2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Source code spell checker
WWW=		https://github.com/crate-ci/typos

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

CARGO_INSTALL_PATH=	crates/typos-cli

USE_GITHUB=	yes
GH_ACCOUNT=	crate-ci

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/typos

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
