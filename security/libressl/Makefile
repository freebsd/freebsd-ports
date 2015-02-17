# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD: head/security/libressl/Makefile 374827 2014-12-16 22:06:33Z vsevolod $

PORTNAME=	libressl
PORTVERSION=	2.1.3
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	LibreSSL

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE

CONFLICTS?=	openssl-*

GNU_CONFIGURE=	yes
USES=	libtool pkgconfig pathfix
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
