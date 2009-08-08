# New ports collection makefile for:	textproc/linux-f8-libxml2
# Date created:				2008-04-10
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libxml2
PORTVERSION=	2.7.2
PORTREVISION=	2
CATEGORIES=	textproc linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library providing XML and HTML support (Linux Fedora 8)

CONFLICTS=	linux-libxml2-[0-9]* linux-f10-libxml2-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	2.fc8
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/xmlcatalog usr/bin/xmllint \
		usr/lib/libxml2.so.2 usr/lib/libxml2.so.${PORTVERSION}
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS ChangeLog.gz Copyright NEWS README TODO
MANPREFIX=	${PREFIX}/usr/share
MAN1=		xmlcatalog.1 xmllint.1
MAN3=		libxml.3
MANCOMPRESSED=	yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
