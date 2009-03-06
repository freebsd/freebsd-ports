# New ports collection makefile for:	fusefs-curlftpfs
# Date created:		25 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	curlftpfs
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Mount remote ftp directories

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		curl.5:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

GNU_CONFIGURE=	yes
USE_GNOME=	glib20
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/curlftpfs

.include <bsd.port.mk>
