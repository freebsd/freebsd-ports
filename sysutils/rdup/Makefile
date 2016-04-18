# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	rdup
PORTVERSION=	1.1.15
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/miekg/rdup/archive/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Tool to generate (incremental) backup file list

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libglib-2.0.so:devel/glib20 \
		libpcre.so:devel/pcre \
		libnettle.so:security/nettle

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		autoreconf gmake libarchive pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
