PORTNAME=	pacman
DISTVERSION=	6.0.2
CATEGORIES=	sysutils
MASTER_SITES=	https://sources.archlinux.org/other/${PORTNAME}/

MAINTAINER=	vishwin@vishwin.info
COMMENT=	Package manager from Arch Linux
WWW=		https://archlinux.org/pacman/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

FLAVORS=	default archlinux
FLAVORS_SUB=	yes

default_CONFLICTS_INSTALL=	archlinux-pacman

archlinux_PKGNAMEPREFIX=	archlinux-
archlinux_CONFLICTS_INSTALL=	pacman

USES=		cpe libarchive localbase meson perl5 pkgconfig python:build shebangfix ssl \
		tar:xz
CPE_VENDOR=	${PORTNAME}_project
SHEBANG_FILES=	${WRKSRC}/scripts/makepkg-template.pl.in \
		${WRKSRC}/scripts/libmakepkg/lint_config.sh.in
BINARY_ALIAS=	python3=${PYTHON_CMD}
MESON_ARGS=	-Droot-dir=${PACMAN_ROOT} \
		-Dlocalstatedir=${PACMAN_ROOT}/var \
		-Dsysconfdir=${PREFIX}/etc \
		-Dcrypto=openssl
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PACMAN_ROOT="${PACMAN_ROOT}" PREFIX="${PREFIX}"
PLIST_SUB=	PACMAN_ROOT="${PACMAN_ROOT:C/^${PREFIX}//}"

PORTEXAMPLES=	*
PKGMESSAGE=	${PKGDIR}/pkg-message-${FLAVOR:U}

OPTIONS_DEFINE=	CURL DOCS GPGME EXAMPLES NLS
OPTIONS_DEFAULT=CURL DOCS GPGME
OPTIONS_EXCLUDE=NLS # XXX: meson cannot find ngettext(3) despite gettext-runtime
OPTIONS_SUB=	yes

CURL_DESC=	Use libcurl fetcher instead of external curl/wget
CURL_MESON_ENABLED=	curl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

DOCS_MESON_ENABLED=	doc
DOCS_BUILD_DEPENDS=	a2x:textproc/asciidoc

GPGME_DESC=	Use GPGME for PGP signature verification
GPGME_MESON_ENABLED=	gpgme
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme

NLS_USES=		gettext-runtime gettext-tools
NLS_MESON_TRUE=	i18n

.if ${FLAVOR:U} == default
PACMAN_ROOT=	${PREFIX}/pacman
.elif ${FLAVOR:U} == archlinux
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Arch Linux itself only supports amd64
PACMAN_ROOT=	/compat/archlinux
PLIST_DIRS+=	%%PACMAN_ROOT%%/var/cache \
		%%PACMAN_ROOT%%/var \
		/compat
.endif

.include <bsd.port.options.mk>

post-patch:
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e '/^Architecture/ s|auto|i686|' ${WRKSRC}/etc/pacman.conf.in
.endif
.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -e '/^Architecture/ s|auto|x86_64|' ${WRKSRC}/etc/pacman.conf.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pacman.d

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/PKGBUILD-example.txt ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
