PORTNAME=	mc
PORTVERSION=	6.0.3
CATEGORIES=	misc shells
MASTER_SITES=	${WWW}/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	${PORTVERSION:R:R}
DISTNAME=	${PKGNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Midnight Commander fork with panel plugins
WWW=		https://github.com/ilia-maslakov/mcdev

LICENSE=	GPLv3+

CONFLICTS_INSTALL=	mc

USES=		libarchive gnome libtool perl5 pkgconfig python:run
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	FAQ HACKING NEWS* PLUGINS README TODO

OPTIONS_DEFINE=	CURL DOCS EDITOR EXTATTR NLS SFTP SLANG SMB SUBSHELL X11
OPTIONS_DEFAULT=CURL EDITOR SFTP SUBSHELL X11
OPTIONS_SUB=	yes

EDITOR_DESC=	Build with internal text editor
EXTATTR_DESC=	Extended filesystem attributes support
SFTP_DESC=	Support for SFTP (via libssh2)
SUBSHELL_DESC=	Build with subshell support
X11_DESC=	X11 events support (if available)

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=	--enable-panel-plugin-ftp=no \
			--enable-panel-plugin-s3=no

EDITOR_CONFIGURE_WITH=	internal-edit

EXTATTR_LIB_DEPENDS=	libe2p.so:filesystems/e2fsprogs-core
EXTATTR_CONFIGURE_OFF=	--enable-ext2fs-attr=no

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

SFTP_LIB_DEPENDS=	libssh2.so:security/libssh2
SFTP_CONFIGURE_ENABLE=	vfs-sftp

SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_CONFIGURE_OFF=	--with-screen=ncurses

SMB_USES=		samba:lib
SMB_CONFIGURE_OFF=	--enable-panel-plugin-samba=no

SUBSHELL_CONFIGURE_WITH=subshell

X11_BUILD_DEPENDS=	${LOCALBASE}/include/X11/Xlib.h:x11/libX11
X11_CONFIGURE_WITH=	x

post-patch-EDITOR-off:
	@${REINPLACE_CMD} -e 's, mcedit\.1,,' ${WRKSRC}/doc/man/sr/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
