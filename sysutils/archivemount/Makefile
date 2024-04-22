PORTNAME=	archivemount
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://www.cybernoia.de/software/archivemount/

MAINTAINER=	jirnov@gmail.com
COMMENT=	Mount archives with FUSE
WWW=		https://www.cybernoia.de/software/archivemount.html

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fuse iconv libarchive pkgconfig
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/archivemount \
		share/man/man1/archivemount.1.gz \
		sbin/mount_archive

SUB_FILES=	pkg-message

post-install:
		${RLN} ${STAGEDIR}${PREFIX}/bin/archivemount \
		    ${STAGEDIR}${PREFIX}/sbin/mount_archive

.include <bsd.port.mk>
