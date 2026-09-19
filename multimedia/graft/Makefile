PORTNAME=	graft
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	multimedia

MAINTAINER=	abinashsena@gmail.com
COMMENT=	Change the hook. Keep the body
WWW=		https://github.com/eonik-ai/graft

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg
BUILD_DEPENDS=	rustc:lang/rust

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eonik-ai

CARGO_BUILD_ARGS=	--bin graft
CARGO_INSTALL_PATH=	crates/graft
PLIST_FILES=		bin/graft

.include <bsd.port.mk>
