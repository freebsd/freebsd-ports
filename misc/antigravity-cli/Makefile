PORTNAME=	antigravity-cli
DISTVERSION=	1.0.16
CATEGORIES=	misc # machine-learning
MASTER_SITES=	${AGY_URL_BASE}linux-x64/:amd64 \
		${AGY_URL_BASE}linux-arm/:aarch64
DISTFILES=	cli_linux_x64.tar.gz:amd64 \
		cli_linux_arm64.tar.gz:aarch64
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI for Google Antigravity AI platform
WWW=		https://antigravity.google/

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	is a Linux binary with a limited platform support

USES=		linux:rl9
USE_LINUX=	base

AGY_URL_BASE=	https://storage.googleapis.com/antigravity-public/antigravity-cli/1.0.16-4893150192467968/

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/agy

find-new-version:
	@TAB=$$(printf '\t'); \
	install_sh=$$(fetch -q -o - https://antigravity.google/cli/install.sh); \
	download_base_url=$$(echo "$$install_sh" | ${SED} -n 's/^DOWNLOAD_BASE_URL="\(.*\)"/\1/p'); \
	manifest=$$(fetch -q -o - "$${download_base_url}/manifests/linux_amd64.json"); \
	new_ver=$$(echo "$$manifest" | jq -r '.version'); \
	current_ver=$$(make -V DISTVERSION); \
	if [ "$$new_ver" != "$$current_ver" ]; then \
		new_url=$$(echo "$$manifest" | jq -r '.url'); \
		new_url_base=$$(echo "$$new_url" | ${SED} -E 's|/[^/]+/[^/]+$$||'); \
		${SED} -i '' "s/^DISTVERSION=.*/DISTVERSION=$${TAB}$$new_ver/" ${.CURDIR}/Makefile; \
		${SED} -i '' "s|^AGY_URL_BASE=.*|AGY_URL_BASE=$${TAB}$$new_url_base/|" ${.CURDIR}/Makefile; \
		echo "=> New version available: $$current_ver -> $$new_ver"; \
	else \
		echo "=> No new version available (current: $$current_ver)"; \
	fi

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
EXTRACT_ONLY=	cli_linux_arm64.tar.gz
.else
EXTRACT_ONLY=	cli_linux_x64.tar.gz
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/antigravity ${STAGEDIR}${PREFIX}/bin/agy

.include <bsd.port.post.mk>
