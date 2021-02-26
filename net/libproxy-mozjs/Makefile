# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	4
CATEGORIES=	net www
PKGNAMESUFFIX=	-${LIBPROXY_SLAVE}


COMMENT=	Mozilla JavaScript plug-in for libproxy

USES=		compiler:c++11-lib
USE_CXXSTD=	gnu++11
LIB_DEPENDS=	libmozjs-52.so:lang/spidermonkey52

EXTRA_PATCHES=	${FILESDIR}/libproxy-0.4.15-mozjs52.patch:-p1

LIBPROXY_SLAVE=	mozjs
MASTERDIR=	${.CURDIR}/../libproxy

# See https://github.com/libproxy/libproxy/commit/2203f710988eaa3061e75b083296944e34e17d59
DEPRECATED=	Discouraged by upstream, will be marked broken in next update
EXPIRATION_DATE=	2021-03-31

.include "${MASTERDIR}/Makefile"
