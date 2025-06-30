PORTNAME=	far2l
PORTVERSION=	2.6.5
PORTREVISION=	1
DISTVERSIONPREFIX=	v_
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Port of FAR v2 to Unix-like systems
WWW=		https://github.com/elfmz/far2l

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libuchardet.so:textproc/uchardet
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	elfmz

USES=		cmake compiler:c++11-lang desktop-file-utils gnome \
		libarchive perl5 pkgconfig shebangfix ssl
USE_GNOME=	libxml2
USE_PERL5=	build
SHEBANG_FILES=	far2l/bootstrap/view.sh

CMAKE_OFF=	UNRAR	# libarchive handles *.rar files just fine

OPTIONS_DEFINE=	NFS SFTP SMB WEBDAV WXGTK X11
OPTIONS_DEFAULT=	NFS SFTP WEBDAV WXGTK X11
OPTIONS_SUB=	yes

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs

SFTP_DESC=	SFTP file transfer support
SFTP_LIB_DEPENDS=	libssh.so:security/libssh

SMB_USES=	samba:lib

WEBDAV_DESC=	WebDav protocol support via libneon
WEBDAV_LIB_DEPENDS=	libneon.so:www/neon

WXGTK_CMAKE_OFF=	-DUSEWX:BOOL=OFF
WXGTK_USE=	WX=3.0+
WXGTK_VARS=	WANT_WXGTK_VER=2

X11_DESC=	Build with TTY X11 extensions
X11_CMAKE_OFF=	-DTTYX:BOOL=OFF
X11_USES=	xorg
X11_USE=	XORG=ice,sm,x11,xext,xi

post-patch:
	@${REINPLACE_CMD} -e \
		's,pkg_search_module\(([[:alpha:]]*\)[^)]*,find_package\1,' \
			${WRKSRC}/CMakeLists.txt
	@${GREP} -Rl --null --include=\*.cpp /bin/bash ${WRKSRC} | ${XARGS} \
		-0 ${REINPLACE_CMD} -e 's,/bin/bash,${LOCALBASE}&,'
	@${REINPLACE_CMD} -e '/SetBackgroundColour/ { x; \
		s|^|SetIcon(wxIcon(wxStandardPaths::Get().GetInstallPrefix()\
		+ "/share/icons/far2l.svg", wxBITMAP_TYPE_ICO));|; H; x; }' \
			${WRKSRC}/WinPort/src/Backend/WX/wxMain.cpp

post-stage:
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/far2l/Plugins/NetRocks/plug/SHELL
	${RM} ${STAGEDIR}${DATADIR}/wslgclip.*

.include <bsd.port.mk>
