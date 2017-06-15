# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	sslsplit
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/rel/sslsplit/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Transparent and scalable SSL/TLS interception

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		gmake pkgconfig tar:bzip2 uidfix
MAKEFILE=	GNUmakefile
MAKE_ENV=	DESTDIR=${STAGEDIR} MANDIR=man INSTALLUID=${UID} INSTALLGID=${GID}
PLIST_FILES=	bin/sslsplit man/man1/sslsplit.1.gz

.include <bsd.port.mk>
