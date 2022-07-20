PORTNAME=	mc
PORTVERSION=	4.8.28
CATEGORIES=	misc shells
MASTER_SITES=	http://ftp.midnight-commander.org/ \
		https://ftp.osuosl.org/pub/midnightcommander/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	zip:archivers/zip

.if ${:!diff --version 2>/dev/null | grep -c GNU\ diffutils || :!} < 1
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_diffviewer_ydiff.c
RUN_DEPENDS+=	gdiff:textproc/diffutils
.endif

USES=		gmake gnome libtool perl5 pkgconfig python shebangfix tar:xz
SHEBANG_FILES=	${WRKSRC}/src/vfs/extfs/helpers/s3+.in \
		${WRKSRC}/src/vfs/extfs/helpers/uc1541
python_OLD_CMD=	@PYTHON@
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ZIP=${LOCALBASE}/bin/zip UNZIP=${UNZIP_NATIVE_CMD}

PORTDOCS=	AUTHORS FAQ HACKING MAINTAINERS NEWS README *.txt

OPTIONS_DEFINE=	ASPELL DOCS EDITOR EXTATTR ICONV NLS SFTP SUBSHELL X11
OPTIONS_DEFAULT=	EDITOR ICONV SFTP SLANG SUBSHELL X11
OPTIONS_SINGLE=	SCREEN
OPTIONS_SINGLE_SCREEN=	SLANG NCURSES
OPTIONS_SUB=	yes

ASPELL_DESC=	Aspell support for internal editor
EDITOR_DESC=	Build with internal text editor
EXTATTR_DESC=	Extended filesystem attributes support
SCREEN_DESC=	Screen library
SFTP_DESC=	Support for SFTP (via libssh)
SUBSHELL_DESC=	Build with subshell support

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ENABLE=aspell

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

SUBSHELL_CONFIGURE_WITH=subshell
SUBSHELL_SUB_FILES=	pkg-message

X11_CONFIGURE_WITH=	x
X11_USES=		xorg
X11_USE=		xorg=x11,xext
X11_VARS=		CONFLICTS_INSTALL+="mc-nox11"
X11_VARS_OFF=		CONFLICTS_INSTALL+="mc"

post-patch:
	@${REINPLACE_CMD} -e 's|clang||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|x$$UNRAR_VERSION.*x|$$UNRAR_VERSION -ge |' \
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

.include <bsd.port.mk>
