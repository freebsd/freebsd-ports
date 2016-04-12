# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	rdup
PORTVERSION=	1.1.14
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.miek.nl/projects/rdup/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Tool to generate (incremental) backup file list

LICENSE=	GPLv3

LIB_DEPENDS=	libglib-2.0.so:devel/glib20 \
		libpcre.so:devel/pcre \
		libnettle.so:security/nettle

USES=		gmake libarchive pkgconfig tar:bzip2
USE_AUTOTOOLS=	autoconf
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
