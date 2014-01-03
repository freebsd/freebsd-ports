# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	bittorrent-libutp
PORTVERSION=	0.20120526
DISTVERSION=	d4685a3
CATEGORIES=	net devel
MASTER_SITES=	https://github.com/bittorrent/libutp/tarball/${DISTVERSION}/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	The uTorrent Transport Protocol library

LICENSE=	MIT

USE_DOS2UNIX=	yes
MAKEFILE=	${FILESDIR}/BSDmakefile
USE_LDCONFIG=	yes
NO_STAGE=	yes

pre-su-install:
	${MKDIR} ${PREFIX}/include/libutp

.include <bsd.port.mk>
