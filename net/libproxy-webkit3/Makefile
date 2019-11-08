# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net www
PKGNAMESUFFIX=	-${LIBPROXY_SLAVE}

COMMENT=	WebKit JavaScript plug-in for libproxy

LIB_DEPENDS=	libjavascriptcoregtk-4.0.so:www/webkit2-gtk3

USES=		gettext-runtime gnome
USE_GNOME=	glib20

LIBPROXY_SLAVE=	webkit3
MASTERDIR=	${.CURDIR}/../libproxy

.include "${MASTERDIR}/Makefile"
