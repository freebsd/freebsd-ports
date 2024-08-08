PORTNAME=	cpuid2cpuflags
PORTVERSION=	14
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool to generate CPU_FLAGS_* for your CPU
WWW=		https://github.com/projg2/cpuid2cpuflags

LICENSE=	BSD2CLAUSE

BROKEN_riscv64=		fails to build: src/platforms.h:15:4: error: "Unsupported platform, please report"

USES=		autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	projg2
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
