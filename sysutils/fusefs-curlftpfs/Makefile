# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	curlftpfs
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Mount remote ftp directories

LICENSE=	GPLv2

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USES=		fuse pkgconfig
USE_GNOME=	glib20
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/curlftpfs

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000000
EXTRA_PATCHES+= ${FILESDIR}/extra-64-ftpfs.h
.else
EXTRA_PATCHES+= ${FILESDIR}/extra-32-ftpfs.h
.endif
.if ${OSVERSION} < 900000
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-ftpfs.c
.endif

.include <bsd.port.post.mk>
