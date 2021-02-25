# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	far2l
PORTVERSION=	g20210222
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Port of FAR v2 to Unix-like systems

BUILD_DEPENDS=	gawk:lang/gawk gm4:devel/m4 \
		${LOCALBASE}/include/spdlog/spdlog.h:devel/spdlog
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libpcre.so:devel/pcre \
		libuchardet.so:textproc/uchardet \
		libxerces-c.so:textproc/xerces-c3
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	elfmz
GH_TAGNAME=	3129972

USES=		cmake compiler:c++11-lang libarchive pkgconfig shebangfix ssl
SHEBANG_FILES=	far2l/bootstrap/view.sh

OPTIONS_DEFINE=	NFS SFTP SMB WEBDAV WXGTK
OPTIONS_DEFAULT=	NFS SFTP WEBDAV WXGTK
OPTIONS_SUB=	yes

NFS_LIB_DEPENDS=	libnfs.so:net/libnfs

SFTP_DESC=	SFTP file transfer support
SFTP_LIB_DEPENDS=	libssh.so:security/libssh

SMB_USES=	samba:lib

WEBDAV_DESC=	WebDav protocol support via libneon
WEBDAV_LIB_DEPENDS=	libneon.so:www/neon

WXGTK_CMAKE_OFF=	-DUSEWX:BOOL=OFF
WXGTK_USE=	WX=3.0+

post-patch:
	@${GREP} -Rl --null --include=\*.cpp /bin/bash ${WRKSRC} | ${XARGS} \
		-0 ${REINPLACE_CMD} -e 's,/bin/bash,${LOCALBASE}&,'

.include <bsd.port.mk>
