# New ports collection makefile for:	textproc/linux-f10-libxml
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	1.8.17
CATEGORIES=	textproc linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Old libXML library for Gnome-1 application compatibility (Linux Fedora 10)

CONFLICTS=	linux-libxml-[0-9]* linux-f8-libxml-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	20.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libxml.so.1 usr/lib/libxml.so.${PORTVERSION}
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING.LIB ChangeLog README TODO
DESCR=		${.CURDIR}/../${PORTNAME}2/pkg-descr

.include <bsd.port.mk>
