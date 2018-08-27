# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PKGNAMESUFFIX=	-secret

COMMENT=	Remmina plugin for GNOME Keyring

LIB_DEPENDS=	libsecret-1.so:security/libsecret
RUN_DEPENDS=	gnome-keyring:security/gnome-keyring

USES+=		gettext-runtime

MASTERDIR=	${.CURDIR}/../remmina-plugins

.include "${MASTERDIR}/Makefile"
