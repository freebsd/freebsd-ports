# Created by: Gyorgy Teubel <tgyurci@freemail.hu>
# $FreeBSD$

PORTNAME=	wdfs
PORTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://noedler.de/projekte/wdfs/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mount remote WedDAV directories with Fuse

LIB_DEPENDS=	libneon.so:${PORTSDIR}/www/neon29

GNU_CONFIGURE=	yes
USES=		fuse pkgconfig
USE_GNOME=	glib20

PLIST_FILES=	bin/wdfs

NO_STAGE=	yes
.include <bsd.port.mk>
