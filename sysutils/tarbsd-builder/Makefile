PORTNAME=	tarbsd-builder
DISTVERSION=	26.01.25
CATEGORIES=	sysutils
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DIST_SUBDIR=	${DISTNAME}-${DISTVERSION}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Minimal FreeBSD image builder
WWW=		https://github.com/pavetheway91/tarbsd

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	Generated images are amd64 only at the moment, aarch64 planned but no others

RUN_DEPENDS=	${LOCALBASE}/sbin/pkg:${PKG_ORIGIN}

USES=		php:flavors,build
USE_GITHUB=	yes
GH_ACCOUNT=	pavetheway91
GH_PROJECT=	tarbsd
USE_PHP=	ctype filter mbstring pcntl phar zlib

NO_ARCH=	yes

_TARBSD_COMPILE_ARGS=	--ports --version-tag=${PORTVERSION} \
			--prefix=${LOCALBASE}

PLIST_FILES=	bin/tarbsd
PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES PIGZ QEMU_TOOLS
OPTIONS_DEFAULT=	EXAMPLES PIGZ

PIGZ_DESC=		Better kernel compression
QEMU_TOOLS_DESC=	Export image to hypervisor formats

PIGZ_RUN_DEPENDS=	pigz:archivers/pigz
QEMU_TOOLS_RUN_DEPENDS=	qemu-img:emulators/qemu@tools

do-build:
	${LOCALBASE}/bin/php -d phar.readonly=0 ${WRKSRC}/stubs/compile.php \
		${_TARBSD_COMPILE_ARGS}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/out/tarbsd \
		${STAGEDIR}${PREFIX}/bin/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
