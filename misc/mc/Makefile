# Created by: torstenb@FreeBSD.org

PORTNAME=	mc
PORTVERSION=	4.8.26
PORTREVISION=	2
CATEGORIES=	misc shells
MASTER_SITES=	http://ftp.midnight-commander.org/ \
		https://ftp.osuosl.org/pub/midnightcommander/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander Clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	zip:archivers/zip

USES=		gmake gnome libtool perl5 pkgconfig python shebangfix tar:xz
SHEBANG_FILES=	${WRKSRC}/src/vfs/extfs/helpers/s3+.in \
		${WRKSRC}/src/vfs/extfs/helpers/uc1541
python_OLD_CMD=	@PYTHON@
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ZIP=${LOCALBASE}/bin/zip UNZIP=${UNZIP_NATIVE_CMD}

PORTDOCS=	AUTHORS FAQ HACKING MAINTAINERS NEWS README *.txt

OPTIONS_DEFINE=	DOCS EDITOR EXTATTR ICONV NLS SFTP SMB SUBSHELL X11
OPTIONS_DEFAULT=	EDITOR ICONV SFTP SLANG SMB SUBSHELL X11
OPTIONS_SINGLE=	SCREEN
OPTIONS_SINGLE_SCREEN=	SLANG NCURSES
OPTIONS_SUB=	yes

EDITOR_DESC=	Build with internal editor
EXTATTR_DESC=	Extended attributes support
SCREEN_DESC=	Screen library
SFTP_DESC=	Support for SFTP (via libssh)
SUBSHELL_DESC=	Build with subshell support

EDITOR_CONFIGURE_WITH=	internal-edit

EXTATTR_LIB_DEPENDS=	libe2p.so:sysutils/e2fsprogs

ICONV_USES=		iconv
ICONV_CONFIGURE_ENABLE=	charset

NCURSES_CONFIGURE_ON=	--with-screen=ncurses
NCURSES_CFLAGS+=	-DNCURSES_WIDECHAR

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib

SFTP_LIB_DEPENDS=	libssh2.so:security/libssh2
SFTP_CONFIGURE_ENABLE=	vfs-sftp

SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_CONFIGURE_ON=	--with-screen=slang --with-slang-includes=${LOCALBASE}/include

SMB_CONFIGURE_ENABLE=	vfs-smb
SMB_CONFIGURE_WITH=	smb-configdir=${LOCALBASE}/etc \
			smb-codepagedir=${LOCALBASE}/etc/codepages

SUBSHELL_CONFIGURE_WITH=subshell
SUBSHELL_SUB_FILES=	pkg-message

X11_CONFIGURE_ENABLE=	x
X11_USES=		xorg
X11_USE=		xorg=x11,xext
X11_VARS=		CONFLICTS_INSTALL+="mc-nox11-[0-9]*"
X11_VARS_OFF=		CONFLICTS_INSTALL+="mc-[0-9]*"

post-patch:
	@${REINPLACE_CMD} -e 's|missing-parameter-type|unused-variable|; \
		s|but-set-variable|variable|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|x$$UNRAR_VERSION = x|$$UNRAR_VERSION -ge |' \
		${WRKSRC}/src/vfs/extfs/helpers/urar.in

post-patch-EXTATTR-off:
	@${REINPLACE_CMD} -e '/found_e2p=/s|yes|disabled|; /e2p library/ \
		{ s| or|,|; s|)|&, or disabled|; }' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${LN} -sf ../${PORTDOCS:[1]} ${WRKSRC}/doc
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

post-install-X11-on:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200030
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_diffviewer_ydiff.c
RUN_DEPENDS+=	gdiff:textproc/diffutils
.endif

.include <bsd.port.post.mk>
