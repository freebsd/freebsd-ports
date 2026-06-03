PORTNAME=	deltachat-rpc-server
DISTVERSIONPREFIX=	v
DISTVERSION=	2.49.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	feld@FreeBSD.org
COMMENT=	JSON-RPC server for DeltaChat
WWW=		https://github.com/chatmail/core

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	aarch64
NOT_FOR_ARCHS_REASON=	Dependency update needed to fix the build

USES=		cargo gmake perl5 ssl

USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	chatmail
GH_PROJECT=	core

CARGO_BUILD_ARGS+=	--locked -p ${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
