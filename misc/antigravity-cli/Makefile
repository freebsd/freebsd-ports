PORTNAME=	antigravity-cli
DISTVERSION=	1.0.0
CATEGORIES=	misc
MASTER_SITES=	https://storage.googleapis.com/antigravity-public/antigravity-cli/${DISTVERSION}-5288553236791296/linux-x64/:amd64 \
		https://storage.googleapis.com/antigravity-public/antigravity-cli/${DISTVERSION}-5288553236791296/linux-arm/:aarch64
DISTFILES=	cli_linux_x64.tar.gz:amd64 \
		cli_linux_arm64.tar.gz:aarch64

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI for Antigravity
WWW=		https://antigravity.google/

LICENSE=	APACHE20

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
