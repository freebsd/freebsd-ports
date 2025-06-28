PORTNAME=	libuuid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.41.1
CATEGORIES=	misc

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Library to generate or parse 128-bit Universally Unique IDs (UUIDs)
WWW=		https://github.com/util-linux/util-linux

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Documentation/licenses/COPYING.BSD-3-Clause

USES=		bison meson pkgconfig tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	util-linux
GH_PROJECT=	util-linux

USE_LDCONFIG=	yes
# disable all Meson features because the project has gazillion of them and we only need one
MESON_ARGS=	--auto-features=disabled \
		-Dallow-32bit-time=true \
		-Dbuild-libuuid=enabled \
		-Ddefault_library=both \
		-Dprogram-tests=false

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes
MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

.include <bsd.port.mk>
