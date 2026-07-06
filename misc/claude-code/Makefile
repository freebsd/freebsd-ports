PORTNAME=	claude-code
DISTVERSION=	2.1.201
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://downloads.claude.ai/claude-code-releases/${DISTVERSION}/:amd64 \
		https://downloads.claude.ai/claude-code-releases/${DISTVERSION}/:aarch64
DISTFILES=	linux-x64/claude:amd64 \
		linux-arm64/claude:aarch64
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Agentic coding tool from Anthropic that lives in your terminal
WWW=		https://github.com/anthropics/claude-code

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	is a Linux binary with a limited platform support

USES=		linux:rl9
USE_LINUX=	base

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_ONLY=

PLIST_FILES=	bin/claude

find-new-version:
	@TAB=$$(printf '\t'); \
	new_ver=$$(fetch -q -o - https://downloads.claude.ai/claude-code-releases/latest); \
	current_ver=$$(make -V DISTVERSION); \
	if [ "$$new_ver" != "$$current_ver" ]; then \
		${SED} -i '' "s/^DISTVERSION=.*/DISTVERSION=$${TAB}$$new_ver/" ${.CURDIR}/Makefile; \
		echo "=> New version available: $$current_ver -> $$new_ver"; \
	else \
		echo "=> No new version available (current: $$current_ver)"; \
	fi

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
CC_PLATFORM=	linux-arm64
.else
CC_PLATFORM=	linux-x64
.endif

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${CC_PLATFORM}/claude ${STAGEDIR}${PREFIX}/bin/claude

.include <bsd.port.post.mk>
