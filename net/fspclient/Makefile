# Created by: ache
# $FreeBSD$

PORTNAME=	fspclient
PORTVERSION=	0.93.1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Ftp-like client for the FSP service

CONFLICTS_INSTALL=	alliance-*
USES=		tar:bzip2 scons:python2
MAKE_ARGS=	prefix=${PREFIX}

PLIST_FILES=	bin/fsp share/man/man1/fsp.1.gz
INSTALL_TARGET=	install prefix=${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
