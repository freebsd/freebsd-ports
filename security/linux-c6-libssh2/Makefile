# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	libssh2
PORTVERSION=	1.4.2
PORTREVISION=	4
CATEGORIES=	security linux
MASTER_SITES=	CENTOS_LINUX

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library implementing the SSH2 protocol (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-libssh2-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
RPMVERSION=	1.el6_6.1
USE_LINUX=	c6
USE_LINUX_APPS=	openssl

USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
