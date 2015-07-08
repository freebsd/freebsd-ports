# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libressl
PORTVERSION=	2.2.1
CATEGORIES=	security devel
MASTER_SITES=	OPENBSD/LibreSSL

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE

CPE_VENDOR=	openbsd

CONFLICTS?=	openssl-*

GNU_CONFIGURE=	yes
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
