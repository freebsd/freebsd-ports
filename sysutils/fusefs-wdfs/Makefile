# New ports collection makefile for:	fusefs-wdfs
# Date created:				13 June 2006
# Whom:					Gyorgy Teubel <tgyurci@freemail.hu>
#
# $FreeBSD$
#

PORTNAME=	wdfs
PORTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://noedler.de/projekte/wdfs/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Mount remote WedDAV directories with Fuse

LIB_DEPENDS=	neon.27:${PORTSDIR}/www/neon29

GNU_CONFIGURE=	yes
USE_FUSE=	yes
USE_GNOME=	glib20

PLIST_FILES=	bin/wdfs

.include <bsd.port.mk>
