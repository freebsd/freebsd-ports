PORTNAME=	sonic
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.9
PORTREVISION=	10
CATEGORIES=	textproc
MASTER_SITES+=	https://clrd.ninjal.ac.jp/unidic_archive/cwj/2.1.2/:unidic
DISTFILES+=	unidic-mecab-2.1.2_src.zip:unidic # check cargo-crates/lindera-unidic-XXX/build.rs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast, lightweight, and schema-less search backend
WWW=		https://github.com/valeriansaliou/sonic

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo compiler:c++11-lang gmake
USE_GITHUB=	yes
GH_ACCOUNT=	valeriansaliou
USE_RC_SUBR=	sonic

USERS=		sonic
GROUPS=		sonic

PLIST_FILES=	bin/sonic \
		"@sample ${ETCDIR}/config.cfg.sample"
PORTDOCS=	CONFIGURATION.md PROTOCOL.md README.md
OPTIONS_DEFINE=	DOCS

CARGO_ENV+=	DISTDIR=${DISTDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.cfg ${STAGEDIR}${ETCDIR}/config.cfg.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
