PORTNAME=	archivemount
DISTVERSION=	0.8.12
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.cybernoia.de/software/archivemount/

MAINTAINER=	jirnov@gmail.com
COMMENT=	Mount archives with FUSE

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse iconv libarchive pkgconfig
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/archivemount \
		man/man1/archivemount.1.gz \
		sbin/mount_archive

SUB_FILES=	pkg-message

post-install:
		${RLN} ${STAGEDIR}${PREFIX}/bin/archivemount \
		    ${STAGEDIR}${PREFIX}/sbin/mount_archive

.include <bsd.port.mk>
