PORTNAME=	github-copilot-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.68
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://github.com/github/copilot-cli/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/:amd64 \
		https://github.com/github/copilot-cli/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/:aarch64
DISTFILES=	copilot-linux-x64.tar.gz:amd64 \
		copilot-linux-arm64.tar.gz:aarch64
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI for GitHub Copilot
WWW=		https://github.com/github/copilot-cli

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	is a Linux binary with a limited platform support

USES=		linux:rl9
USE_LINUX=	base

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/copilot

find-new-version:
	@TAB=$$(printf '\t'); \
	new_ver=$$(${PORTSDIR}/Tools/scripts/github-get-latest-version.sh github copilot-cli | ${SED} 's/^v//'); \
	current_ver=$$(make -V DISTVERSION); \
	if [ "$$new_ver" != "$$current_ver" ]; then \
		${SED} -i '' "s/^DISTVERSION=.*/DISTVERSION=$${TAB}$$new_ver/" ${.CURDIR}/Makefile; \
		echo "=> New version available: $$current_ver -> $$new_ver"; \
	else \
		echo "=> No new version available (current: $$current_ver)"; \
	fi

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
EXTRACT_ONLY=	copilot-linux-arm64.tar.gz
.else
EXTRACT_ONLY=	copilot-linux-x64.tar.gz
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/copilot ${STAGEDIR}${PREFIX}/bin/copilot

.include <bsd.port.post.mk>
