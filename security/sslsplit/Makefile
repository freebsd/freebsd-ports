# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	sslsplit
PORTVERSION=	0.4.11
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/rel/sslsplit/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Transparent and scalable SSL/TLS interception

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

USES=		gmake pkgconfig tar:bzip2
MAKEFILE=	GNUmakefile
MAKE_ENV=	DESTDIR=${STAGEDIR} MANDIR=man
PLIST_FILES=	bin/sslsplit man/man1/sslsplit.1.gz

.include <bsd.port.mk>
