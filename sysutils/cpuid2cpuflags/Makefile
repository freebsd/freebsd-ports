PORTNAME=	cpuid2cpuflags
PORTVERSION=	15
CATEGORIES=	sysutils
MASTER_SITES=	${WWW}/releases/download/v${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool to generate CPU_FLAGS_* for your CPU
WWW=		https://github.com/projg2/cpuid2cpuflags

LICENSE=	GPLv2+

BROKEN_riscv64=		fails to build: src/platforms.h:15:4: error: "Unsupported platform, please report"

USES=		tar:bzip2
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
