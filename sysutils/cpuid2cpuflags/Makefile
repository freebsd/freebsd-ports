# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpuid2cpuflags
PORTVERSION=	11
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool to generate CPU_FLAGS_* for your CPU

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	fails to build: error "Platform not supported (only Linux supported at the moment)"

USES=		autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	mgorny
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
