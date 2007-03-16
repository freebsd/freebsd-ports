# New ports collection makefile for:	fusefs-wdfs
# Date created:				13 June 2006
# Whom:					Gyorgy Teubel <tgyurci@freemail.hu>
#
# $FreeBSD$
#

PORTNAME=	wdfs
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://noedler.de/projekte/wdfs/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	tgyurci@freemail.hu
COMMENT=	Mount remote WedDAV directories with Fuse

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs \
		neon.26:${PORTSDIR}/www/neon
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

GNU_CONFIGURE=	yes
USE_GNOME=	glib20

PLIST_FILES=	bin/wdfs

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
IGNORE=	depends on kernel module that requires FreeBSD 6 or later
.endif

.include <bsd.port.post.mk>
