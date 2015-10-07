# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libressl
PORTVERSION=	2.2.3
CATEGORIES=	security devel
MASTER_SITES=	OPENBSD/LibreSSL

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CPE_VENDOR=	openbsd

CONFLICTS?=	openssl-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-silent-rules
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

regression-test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.post.mk>
