PORTNAME=	claude-code
DISTVERSION=	2.1.225
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://downloads.claude.ai/claude-code-releases/${DISTVERSION}/:amd64 \
		https://downloads.claude.ai/claude-code-releases/${DISTVERSION}/:aarch64
DISTFILES=	linux-x64/claude:amd64 \
		linux-arm64/claude:aarch64
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Agentic coding tool from Anthropic that lives in your terminal
WWW=		https://github.com/anthropics/claude-code

LICENSE=	Proprietary
LICENSE_NAME=	Anthropic Proprietary License
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	is a Linux binary with a limited platform support

RUN_DEPENDS=	bash:shells/bash

USES=		linux:rl9
USE_LINUX=	base

STRIP=		# elftoolchain strip fails on these Linux binaries
NO_BUILD=	yes
SUB_FILES=	claude

NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/claude \
		libexec/claude

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
	${INSTALL_PROGRAM} \
		${DISTDIR}/${DIST_SUBDIR}/${CC_PLATFORM}/claude \
		${STAGEDIR}${PREFIX}/libexec/claude
	${INSTALL_SCRIPT} ${WRKDIR}/claude ${STAGEDIR}${PREFIX}/bin/claude

.include <bsd.port.post.mk>
