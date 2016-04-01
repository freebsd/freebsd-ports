# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-telepathy

COMMENT=	Remmina plugin for Telepathy support

USE_GNOME+=	gtk30
LIB_DEPENDS=	libtelepathy-glib.so:net-im/telepathy-glib

MASTERDIR=	${.CURDIR}/../remmina-plugins

PLIST_SUB+=	ICONS="@comment "

.include "${MASTERDIR}/Makefile"
