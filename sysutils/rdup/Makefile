# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	rdup
PORTVERSION=	1.1.15
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Tool to generate (incremental) backup file list

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libnettle.so:security/nettle

USES=		autoreconf gmake gnome libarchive pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	miekg

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
