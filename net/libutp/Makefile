# New ports collection makefile for: libutp
# Date created: July 26, 2012
# Whom:		Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

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
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
# GitHub will issue a 302 redirect, no way around that, so we
# have to allow fetch(1) to follow the redirect, which is normally
# prevented by the -A flag:
FETCH_ARGS=	-Fpr

pre-su-install:
	${MKDIR} ${PREFIX}/include/libutp

.include <bsd.port.mk>
