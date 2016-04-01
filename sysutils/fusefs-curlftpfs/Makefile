# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	curlftpfs
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Mount remote ftp directories

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USES=		fuse pkgconfig
USE_GNOME=	glib20
PLIST_FILES=	bin/curlftpfs man/man1/${PORTNAME}.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000000
EXTRA_PATCHES+=	${FILESDIR}/extra-64-ftpfs.h
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-32-ftpfs.h
.endif

.include <bsd.port.post.mk>
