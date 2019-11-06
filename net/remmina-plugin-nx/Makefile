# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PKGNAMESUFFIX=	-nx

COMMENT=	Remmina plugin for NX

USES=		gnome xorg
USE_GNOME=	cairo
USE_XORG=	x11 xkbfile

MASTERDIR=	${.CURDIR}/../remmina-plugins

LIB_DEPENDS=	libssh.so:security/libssh

.include "${MASTERDIR}/Makefile"
