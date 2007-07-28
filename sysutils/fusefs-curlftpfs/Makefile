# New ports collection makefile for:	fusefs-curlftpfs
# Date created:		25 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	curlftpfs
PORTVERSION=	0.9.1
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Mount remote ftp directories

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		curl.4:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
USE_GNOME=	glib20
MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/curlftpfs

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=		depends on kernel module that requires FreeBSD 6 or later
.endif

.include <bsd.port.post.mk>
