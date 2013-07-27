# Created by: Charlie Kester <corky1951@comcast.net>
# $FreeBSD$

PORTNAME=	rdup
PORTVERSION=	1.1.14
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://miek.nl/projects/rdup/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Tool to generate (incremental) backup file list

LICENSE=	GPLv3

LIB_DEPENDS=	glib-2.0:${PORTSDIR}/devel/glib20 \
		pcre:${PORTSDIR}/devel/pcre \
		archive:${PORTSDIR}/archivers/libarchive \
		nettle:${PORTSDIR}/security/nettle

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_AUTOTOOLS=	autoconf
MAKEFILE=	GNUmakefile

LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/rdup \
		bin/rdup-simple \
		bin/rdup-tr \
		bin/rdup-up

MAN1=		rdup.1 \
		rdup-simple.1 \
		rdup-tr.1 \
		rdup-up.1

MAN7=		rdup-backups.7

.include <bsd.port.mk>
