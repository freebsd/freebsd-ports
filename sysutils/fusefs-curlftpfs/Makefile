# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	curlftpfs
PORTVERSION=	0.9.2
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Mount remote FTP directories

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		fuse gnome pkgconfig
USE_GNOME=	glib20
PLIST_FILES=	bin/curlftpfs man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
