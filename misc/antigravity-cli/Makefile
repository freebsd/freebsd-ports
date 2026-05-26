PORTNAME=	antigravity-cli
DISTVERSION=	1.0.2
CATEGORIES=	misc # machine-learning
MASTER_SITES=	https://storage.googleapis.com/antigravity-public/antigravity-cli/${DISTVERSION}-6109799369277440/linux-x64/:amd64 \
		https://storage.googleapis.com/antigravity-public/antigravity-cli/${DISTVERSION}-6109799369277440/linux-arm/:aarch64
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

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/agy

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
EXTRACT_ONLY=	cli_linux_arm64.tar.gz
.else
EXTRACT_ONLY=	cli_linux_x64.tar.gz
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/antigravity ${STAGEDIR}${PREFIX}/bin/agy

.include <bsd.port.post.mk>
