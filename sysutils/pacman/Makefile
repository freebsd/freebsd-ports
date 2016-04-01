# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pacman
PORTVERSION=	4.2.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.archlinux.org/other/pacman/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Package manager from ArchLinux

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		bash:shells/bash
RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libarchive.so.13:archivers/libarchive

USES=		gmake libtool perl5 pkgconfig shebangfix
SHEBANG_FILES=	${WRKSRC}/scripts/makepkg-template.pl.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-root-dir="${PACMAN_ROOT}" \
		--localstatedir=/var
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message pkg-deinstall
SUB_LIST=	PACMAN_ROOT="${PACMAN_ROOT}" PREFIX="${PREFIX}"
PLIST_SUB=	PACMAN_ROOT="${PACMAN_ROOT:C/^${PREFIX}//}"

PACMAN_ROOT?=	"${PREFIX}/pacman"

PORTEXAMPLES=	*

OPTIONS_DEFINE=	CURL GPGME EXAMPLES NLS
OPTIONS_DEFAULT=CURL GPGME
CURL_DESC=	Use libcurl fetcher instead of external curl/wget
GPGME_DESC=	Use GPGME for PGP signature verification

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
CONFIGURE_ARGS+=--with-libcurl=${LOCALBASE}
LIB_DEPENDS+=	libcurl.so:ftp/curl
.else
CONFIGURE_ARGS+=--without-libcurl
.endif

.if ${PORT_OPTIONS:MGPGME}
CONFIGURE_ARGS+=--with-gpgme
LIB_DEPENDS+=	libgpgme.so:security/gpgme
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|m4|gm4|' ${WRKSRC}/scripts/Makefile.in
	@${REINPLACE_CMD} -e '2 s/.*/exit 0/' ${WRKSRC}/build-aux/missing
	@${REINPLACE_CMD} -e '/INSTALL_DATA.*sysconfdir/ d' ${WRKSRC}/etc/Makefile.in
.for tool in curl wget rsync lftpget
	@${REINPLACE_CMD} -e 's|/usr/bin/${tool}|${LOCALBASE}/bin/${tool}|' \
		${WRKSRC}/etc/pacman.conf.in ${WRKSRC}/etc/makepkg.conf.in
.endfor
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e '/^Architecture/ s|auto|i686|' ${WRKSRC}/etc/pacman.conf.in
.endif
.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -e '/^Architecture/ s|auto|x86_64|' ${WRKSRC}/etc/pacman.conf.in
.endif

post-install:
.for f in makepkg.conf pacman.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${STAGEDIR}${PREFIX}/etc/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/PKGBUILD-example.txt ${STAGEDIR}${EXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${PACMAN_ROOT}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libalpm.so

.include <bsd.port.mk>
