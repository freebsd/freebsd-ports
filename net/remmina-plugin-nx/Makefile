# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PKGNAMESUFFIX=	-nx

COMMENT=	Remmina plugin for NX

USE_GNOME+=	cairo
USE_XORG+=	x11 xkbfile

MASTERDIR=	${.CURDIR}/../remmina-plugins

LIB_DEPENDS+=	libssh_threads.so:security/libssh

PLIST_SUB+=	ICONS="" SSH="@comment "

.include "${MASTERDIR}/Makefile"
