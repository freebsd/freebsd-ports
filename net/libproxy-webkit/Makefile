# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net www
PKGNAMESUFFIX=	-${LIBPROXY_SLAVE}


COMMENT=	WebKit JavaScript plug-in for libproxy

LIB_DEPENDS=	libwebkitgtk-1.0.so:www/webkit-gtk2

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=2019-03-24

LIBPROXY_SLAVE=	webkit
MASTERDIR=	${.CURDIR}/../libproxy

.include "${MASTERDIR}/Makefile"
