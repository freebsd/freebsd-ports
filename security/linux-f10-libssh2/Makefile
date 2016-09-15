# Created by: bsam
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	security linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol (Linux Fedora 10)

CONFLICTS=	linux-f8-libssh2-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	openssl

RPMVERSION=	7.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libssh2.so.1 usr/lib/libssh2.so.1.0.0
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
