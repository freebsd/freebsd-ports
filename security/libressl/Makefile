# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libressl
PORTVERSION=	2.0.0
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	LibreSSL

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE

CONFLICTS?=	openssl-*

GNU_CONFIGURE=	yes
USES=	libtool
USE_LDCONFIG=	yes

test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
