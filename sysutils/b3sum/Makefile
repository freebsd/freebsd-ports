PORTNAME=	b3sum
DISTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	Command line implementation of the BLAKE3 hash function
WWW=		https://github.com/BLAKE3-team/BLAKE3

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE_A2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	BLAKE3-team
GH_PROJECT=	BLAKE3

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

WRKSRC_SUBDIR=	${PORTNAME}

PORTDOCS=	*.md
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64
CARGO_FEATURES=	neon
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/.. && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
