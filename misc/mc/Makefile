# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	mc
PORTVERSION=	4.8.18
CATEGORIES=	misc shells
MASTER_SITES=	http://ftp.midnight-commander.org/ \
		http://ftp.osuosl.org/pub/midnightcommander/ \
		SF/nemysisfreebsdp/misc/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander Clone

LICENSE=	GPLv3

CONFLICTS=	mc-light-4*

USES=		gmake shebangfix perl5 pkgconfig tar:xz libtool
SHEBANG_FILES=	misc/mcedit.menu.in configure configure.ac \
		${WRKSRC}/src/vfs/extfs/helpers/Makefile.in \
		${WRKSRC}/src/vfs/extfs/helpers/s3+.in \
		${WRKSRC}/src/vfs/extfs/helpers/uc1541.in
python_OLD_CMD=	@PYTHON@
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ZIP=${ZIP_CMD} UNZIP=${UNZIP_CMD}

OPTIONS_DEFINE=	DOCS EDITOR ICONV NLS SFTP SMB SUBSHELL X11

OPTIONS_SINGLE=	SCREEN
OPTIONS_SINGLE_SCREEN=	SLANG NCURSES

OPTIONS_DEFAULT=EDITOR ICONV SFTP SLANG SMB SUBSHELL X11

EDITOR_DESC=	Build with internal editor
SFTP_DESC=	Support for SFTP (via libssh)
SUBSHELL_DESC=	Build with subshell support

OPTIONS_SUB=	yes

EDITOR_CONFIGURE_WITH=	internal-edit

ICONV_USES=		iconv
ICONV_CONFIGURE_ENABLE=	charset

NCURSES_CONFIGURE_ON=	--with-screen=ncurses

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

X11_CONFIGURE_ENABLE=	x
X11_USE=		xorg=x11,xext

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS NEWS README

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	FAQ HACKING MAINTAINERS *.txt

post-patch:
	@${REINPLACE_CMD} -e 's|missing-parameter-type|unused-variable|; \
		s|but-set-variable|variable|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|SUBDIRS = intl|SUBDIRS =|' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
