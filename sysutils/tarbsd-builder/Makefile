PORTNAME=	tarbsd-builder
DISTVERSION=	25.08.17
CATEGORIES=	sysutils
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DIST_SUBDIR=	${DISTNAME}-${DISTVERSION}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Minimal FreeBSD image builder
WWW=		https://github.com/pavetheway91/tarbsd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:flavors,build
USE_GITHUB=	yes
GH_ACCOUNT=	pavetheway91
GH_PROJECT=	tarbsd
USE_PHP=	pcntl phar zlib

IGNORE_WITH_PHP=	81
NO_ARCH=	yes

_TARBSD_COMPILE_ARGS=--ports --version-tag=${DISTVERSION}

PLIST_FILES=	bin/tarbsd

OPTIONS_DEFINE=		INTL MBSTRING QEMU_TOOLS ZOPFLI
OPTIONS_DEFAULT=	MBSTRING ZOPFLI

INTL_DESC=	Intl extension instead of a polyfill
MBSTRING_DESC=	Mbstring extension instead of a polyfill
QEMU_TOOLS_DESC=	Export image to hypervisor formats
ZOPFLI_DESC=	Better kernel compression

INTL_USE=		PHP=intl
MBSTRING_USE=		PHP=mbstring
QEMU_TOOLS_RUN_DEPENDS=	qemu-img:emulators/qemu@tools
ZOPFLI_RUN_DEPENDS=	zopfli:archivers/zopfli

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMBSTRING}
_TARBSD_COMPILE_ARGS+=	--np-iconv
.endif

do-build:
	${LOCALBASE}/bin/php \
		-d phar.readonly=0 \
		${WRKSRC}/stubs/compile.php ${_TARBSD_COMPILE_ARGS}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/out/tarbsd \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
