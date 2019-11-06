# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	mc
PORTVERSION=	4.8.22
PORTREVISION=	2
CATEGORIES=	misc shells
MASTER_SITES=	http://ftp.midnight-commander.org/ \
		https://ftp.osuosl.org/pub/midnightcommander/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Midnight Commander, a free Norton Commander Clone

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	mc-light-4*

USES=		gmake gnome libtool perl5 pkgconfig python:2.7,run shebangfix tar:xz
SHEBANG_FILES=	${WRKSRC}/src/vfs/extfs/helpers/s3+.in \
		${WRKSRC}/src/vfs/extfs/helpers/uc1541.in
python_OLD_CMD=	@PYTHON@
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ZIP=${ZIP_CMD} UNZIP=${UNZIP_CMD}

OPTIONS_DEFINE=	DOCS EDITOR ICONV NLS SFTP SMB SUBSHELL X11
OPTIONS_DEFAULT=EDITOR ICONV SFTP SLANG SMB SUBSHELL X11
OPTIONS_SINGLE=	SCREEN
OPTIONS_SINGLE_SCREEN=	SLANG NCURSES
OPTIONS_SUB=	yes

EDITOR_DESC=	Build with internal editor
SFTP_DESC=	Support for SFTP (via libssh)
SUBSHELL_DESC=	Build with subshell support

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
X11_USES=		xorg
X11_USE=		xorg=x11,xext
X11_VARS=		CONFLICTS_INSTALL+="mc-nox11-[0-9]*"
X11_VARS_OFF=		CONFLICTS_INSTALL+="mc-[0-9]*" PKGNAMESUFFIX=-nox11

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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

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
