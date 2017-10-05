# Created by: ache
# $FreeBSD$

PORTNAME=	fspclient
PORTVERSION=	0.93.0
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Ftp-like client for the FSP service

CONFLICTS_INSTALL=	alliance-*
USES=		tar:bzip2 scons
MAKE_ARGS=	prefix=${PREFIX}

PLIST_FILES=	bin/fsp man/man1/fsp.1.gz
INSTALL_TARGET=	install prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
