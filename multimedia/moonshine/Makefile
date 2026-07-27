PORTNAME=	moonshine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0-freebsd
CATEGORIES=	multimedia

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Self-hosted game stream host for Moonlight
WWW=		https://github.com/hgaiser/moonshine

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	game-streaming compositor host, tested on amd64 only

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libgbm.so:graphics/mesa-libs
RUN_DEPENDS=	Xwayland:x11-servers/xwayland

USES=		cargo localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	ocochard
GH_TAGNAME=	${DISTVERSIONPREFIX}${DISTVERSION}
USE_RC_SUBR=	moonshine

SUB_FILES=	pkg-message

PLIST_FILES=	bin/moonshine \
		"@sample etc/moonshine/moonshine.toml.sample"

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/moonshine
	${INSTALL_DATA} ${FILESDIR}/moonshine.toml.sample \
		${STAGEDIR}${PREFIX}/etc/moonshine/moonshine.toml.sample

.include <bsd.port.mk>
