# New ports collection makefile for:	textproc/linux-f8-libxml
# Date created:				2008-04-10
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	1.8.17
PORTREVISION=	1
CATEGORIES=	textproc linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Old libXML library for Gnome-1 application compatibility (Linux Fedora 8)

CONFLICTS=	linux-libxml-[0-9]* linux-f10-libxml-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	18.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libxml.so.1 usr/lib/libxml.so.${PORTVERSION}
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING.LIB ChangeLog README TODO
DESCR=		${.CURDIR}/../${PORTNAME}2/pkg-descr

.include <bsd.port.mk>
