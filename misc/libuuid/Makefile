PORTNAME=	libuuid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.41
CATEGORIES=	misc

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Library that generates and parses 128-bit Universally Unique IDs (UUIDs)
WWW=		https://github.com/util-linux/util-linux

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Documentation/licenses/COPYING.BSD-3-Clause

USES=		bison meson pkgconfig tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	util-linux
GH_PROJECT=	util-linux

USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
# disable all Meson features because the project has gazillion of them and we only need one
MESON_ARGS=	--auto-features=disabled \
		-Ddefault_library=both \
		-Dbuild-libuuid=enabled \
		-Dallow-32bit-time=true \
		-Dprogram-tests=false

OPTIONS_DEFINE=		MANPAGES
MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor

.include <bsd.port.mk>
