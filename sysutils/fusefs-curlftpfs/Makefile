PORTNAME=	curlftpfs
PORTVERSION=	0.9.2
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Mount remote FTP directories
WWW=		https://curlftpfs.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		fuse gnome pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/curlftpfs \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
