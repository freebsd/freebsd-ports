# Created by: Evgeny Zhirnov <jirnov@gmail.com>
# $FreeBSD$

PORTNAME=	archivemount
DISTVERSION=	0.8.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.cybernoia.de/software/archivemount/

MAINTAINER=	jirnov@gmail.com
COMMENT=	Mount archives with FUSE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse gmake iconv libarchive pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/archivemount \
		man/man1/archivemount.1.gz

.include <bsd.port.mk>
