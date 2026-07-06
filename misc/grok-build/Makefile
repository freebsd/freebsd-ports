PORTNAME=	grok-build
DISTVERSION=	0.2.87
CATEGORIES=	misc # machine-learning
MASTER_SITES=	${GROK_URL_BASE:S|$|:amd64|} \
		${GROK_URL_BASE:S|$|:aarch64|}
DISTFILES=	grok-${DISTVERSION}-linux-x86_64:amd64 \
		grok-${DISTVERSION}-linux-aarch64:aarch64
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI for xAI Grok AI platform
WWW=		https://x.ai/

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	is a Linux binary with a limited platform support

USES=		linux:rl9
USE_LINUX=	base

GROK_URL_BASE=	https://x.ai/cli/ \
		https://storage.googleapis.com/grok-build-public-artifacts/cli/

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/agent \
		bin/grok

find-new-version:
	@TAB=$$(printf '\t'); \
	new_ver=$$(fetch -q -o - https://x.ai/cli/stable 2>/dev/null || \
		fetch -q -o - https://storage.googleapis.com/grok-build-public-artifacts/cli/stable); \
	current_ver=$$(make -V DISTVERSION); \
	if [ "$$new_ver" != "$$current_ver" ] && [ -n "$$new_ver" ]; then \
		${SED} -i '' "s/^DISTVERSION=.*/DISTVERSION=$${TAB}$$new_ver/" ${.CURDIR}/Makefile; \
		echo "=> New version available: $$current_ver -> $$new_ver"; \
	else \
		echo "=> No new version available (current: $$current_ver)"; \
	fi

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
GROK_DISTFILE=	grok-${DISTVERSION}-linux-aarch64
.else
GROK_DISTFILE=	grok-${DISTVERSION}-linux-x86_64
.endif

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${GROK_DISTFILE} ${STAGEDIR}${PREFIX}/bin/grok
	${LN} -s grok ${STAGEDIR}${PREFIX}/bin/agent

.include <bsd.port.post.mk>
