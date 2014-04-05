# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	rdup
PORTVERSION=	1.1.14
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.miek.nl/projects/rdup/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Tool to generate (incremental) backup file list

LICENSE=	GPLv3

LIB_DEPENDS=	libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libarchive.so:${PORTSDIR}/archivers/libarchive \
		libnettle.so:${PORTSDIR}/security/nettle

USES=		gmake pkgconfig tar:bzip2
USE_AUTOTOOLS=	autoconf
MAKEFILE=	GNUmakefile

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
