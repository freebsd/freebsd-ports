# $FreeBSD$

PORTNAME=	bindfs
DISTVERSION=	1.14.7
CATEGORIES=	sysutils
MASTER_SITES=	https://bindfs.org/downloads/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	doralitze@chaotikum.org
COMMENT=	FUSE based bindfs implementation way more powerful than nullfs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bindfs \
		man/man1/bindfs.1.gz

.include <bsd.port.mk>
