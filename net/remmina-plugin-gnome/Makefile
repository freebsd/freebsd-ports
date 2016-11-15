# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PKGNAMESUFFIX=	-gnome

COMMENT=	Remmina plugin for GNOME Keyring

LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring \
		libsecret-1.so:security/libsecret

USES+=		gettext-runtime

MASTERDIR=	${.CURDIR}/../remmina-plugins

.include "${MASTERDIR}/Makefile"
