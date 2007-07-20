# Ports collection makefile for:	libmrss
# Date created:			Jan 2, 2007
# Whom:				Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmrss
PORTVERSION=	0.18.0
CATEGORIES=	textproc
MASTER_SITES=	http://www5.autistici.org/bakunin/libmrss/ GENTOO/distfiles

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A C library for parsing, writing, and creating RSS

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl \
		nxml.18:${PORTSDIR}/textproc/libnxml

GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

USE_LDCONFIG=	yes
WANT_GNOME=	yes

pre-patch:
		${gnomehack_PRE_PATCH}

.include <bsd.port.mk>
