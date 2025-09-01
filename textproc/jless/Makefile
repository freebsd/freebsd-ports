PORTNAME=	jless
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	textproc

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Command-line JSON viewer
WWW=		https://jless.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	libxcb>0:x11/libxcb
LIB_DEPENDS=	libxcb.so:x11/libxcb
RUN_DEPENDS=	libxcb>0:x11/libxcb

USES=		cargo python shebangfix xorg

USE_GITHUB=	yes
GH_ACCOUNT=	PaulJuliusMartinez

USE_XORG=	x11 xcb

SHEBANG_FILES=	cargo-crates/unicode-width-0.1.8/scripts/unicode.py \
		cargo-crates/xcb-0.8.2/rs_client.py

CARGO_ENV=	LIBRARY_PATH=${LOCALBASE}/lib

PLIST_FILES=	bin/jless

post-patch:
	${REINPLACE_CMD} -e 's,%%PYTHON_CMD%%,${PYTHON_CMD},' \
		${WRKSRC}/cargo-crates/xcb-0.8.2/build.rs

.include <bsd.port.mk>
