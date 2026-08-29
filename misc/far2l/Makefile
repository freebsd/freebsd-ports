PORTNAME=	far2l
PORTVERSION=	2.9.0
DISTVERSIONPREFIX=	v_
CATEGORIES=	misc shells

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Port of FAR v2 to Unix-like systems
WWW=		https://github.com/elfmz/far2l

LICENSE=	GPLv2

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo \
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

OPTIONS_DEFINE=	NEON NFS SDL SFTP SMB WXGTK X11
OPTIONS_DEFAULT=	NEON NFS SFTP WXGTK X11
OPTIONS_SUB=	yes

NEON_DESC=	AWS S3 and WebDAV protocol support
NEON_LIB_DEPENDS=	libneon.so:www/neon

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs

SDL_DESC=	SDL GUI backend (experimental)
SDL_CMAKE_ON=	-DUSESDL:BOOL=ON
SDL_USES=	sdl
SDL_USE=	SDL=sdl2

SFTP_DESC=	SFTP file transfer support
SFTP_LIB_DEPENDS=	libssh.so:security/libssh

SMB_USES=	samba:lib

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
# Show icon in graphical mode (https://github.com/elfmz/far2l/issues/1143)
	@${REINPLACE_CMD} -e '/SetBackgroundColour/ { x; \
		s|^|\tSetIcon(wxIcon(wxStandardPaths::Get().GetInstallPrefix()\
		+ "/share/icons/far2l.svg", wxBITMAP_TYPE_ICO));|; H; x; }' \
			${WRKSRC}/WinPort/src/Backend/WX/wxMain.cpp
	@${REINPLACE_CMD} -e '/defined(_LITTLE_ENDIAN)/d' \
		${WRKSRC}/plugins/arclite/src/7z/h/C/CpuArch.h \
		${WRKSRC}/plugins/multiarc/src/formats/7z/C/CpuArch.h

post-stage:
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/far2l/Plugins/NetRocks/plug/FISHPLUS
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/far2l/Plugins/NetRocks/plug/SHELL
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/far2l/Plugins/calc/plug/units
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/far2l/Plugins/transformer/plug/formats
	${RMDIR} ${STAGEDIR}${DATADIR}/Plugins/SimpleIndent/plug
	${RMDIR} ${STAGEDIR}${DATADIR}/Plugins/SimpleIndent
	${RM} ${STAGEDIR}${DATADIR}/wslgclip.*

.include <bsd.port.mk>
