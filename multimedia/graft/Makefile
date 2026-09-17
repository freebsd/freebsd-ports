PORTNAME=	graft
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	multimedia

MAINTAINER=	abinashsena@gmail.com
COMMENT=	Incremental compiler for video composition
WWW=		https://github.com/eonik-ai/graft

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eonik-ai

CARGO_BUILD_ARGS=	--bin graft
CARGO_INSTALL_PATH=	crates/graft

PLIST_FILES=		bin/${PORTNAME}

.include <bsd.port.mk>
