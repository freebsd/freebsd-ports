# New ports collection makefile for:	security/linux-f8-libssh2
# Date created:				2009-04-06
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	libssh2
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	security linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The library implementing the SSH2 protocol (Linux Fedora 8)

CONFLICTS=	linux-libssh2-[0-9]* linux-f10-libssh2-[0-9]*

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	openssl
LINUX_DIST_VER=	8
RPMVERSION=	5.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libssh2.so.1 usr/lib/libssh2.so.1.0.0
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
