PORTNAME=	zeroclaw
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.5
CATEGORIES=	misc

MAINTAINER=	jperlow@gmail.com
COMMENT=	Fast, small AI assistant and agent CLI written in Rust
WWW=		https://github.com/zeroclaw-labs/zeroclaw

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	64-bit only: the release build exceeds 32-bit rustc address space

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	zeroclaw-labs

CARGO_FEATURES=	channel-whatsapp-cloud memory-postgres whatsapp-web

PLIST_FILES=	bin/zeroclaw \
		bin/zeroclaw-acp-bridge

.include <bsd.port.mk>
