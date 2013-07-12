# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pacman
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.archlinux.org/other/pacman/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Package manager from ArchLinux

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		gm4:${PORTSDIR}/devel/m4

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
CONFIGURE_ARGS=	--with-root-dir="${PACMAN_ROOT}" \
		--localstatedir=/var
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message
SUB_LIST=	PACMAN_ROOT="${PACMAN_ROOT}"
PLIST_SUB=	PACMAN_ROOT="${PACMAN_ROOT}"

PACMAN_ROOT?=	"${PREFIX}/pacman"

PORTEXAMPLES=	*

MAN3=		libalpm.3
MAN5=		PKGBUILD.5 makepkg.conf.5 pacman.conf.5
MAN8=		makepkg.8 pacman-key.8 pacman.8 pkgdelta.8 repo-add.8 vercmp.8
MLINKS=		repo-add.8 repo-remove.8

OPTIONS_DEFINE=	CURL GPGME EXAMPLES NLS
OPTIONS_DEFAULT=CURL GPGME EXAMPLES NLS
CURL_DESC=	Use libcurl fetcher instead of external curl/wget
GPGME_DESC=	Use GPGME for PGP signature verification

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCURL}
CONFIGURE_ARGS+=--with-libcurl=${LOCALBASE}
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.else
CONFIGURE_ARGS+=--without-libcurl
.endif

.if ${PORT_OPTIONS:MGPGME}
CONFIGURE_ARGS+=--with-gpgme
LIB_DEPENDS+=	gpgme:${PORTSDIR}/security/gpgme
CFLAGS+=	-I${LOCALBASE}/include/gpgme
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
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/${f}.dist
	if [ ! -f ${PREFIX}/etc/${f} ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/${f}.dist ${PREFIX}/etc/${f}; \
	fi
.endfor
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/PKGBUILD-example.txt ${EXAMPLESDIR}/
.endif
	${MKDIR} ${PACMAN_ROOT}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
