# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	far2l
PORTVERSION=	g20200622
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Port of FAR v2 to Unix-like systems

BUILD_DEPENDS=	gawk:lang/gawk gm4:devel/m4
LIB_DEPENDS=	libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	elfmz
GH_TAGNAME=	43057bd

USES=		cmake compiler:c++11-lang libarchive pkgconfig shebangfix ssl
SHEBANG_FILES=	far2l/bootstrap/roots.sh

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
WXGTK_USE=	WX=3.0

.include <bsd.port.mk>
