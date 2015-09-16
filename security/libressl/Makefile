# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD: head/security/libressl/Makefile 397017 2015-09-15 19:22:46Z brnrd $

PORTNAME=	libressl
<<<<<<< HEAD
PORTVERSION=	2.2.3
CATEGORIES=	security devel
MASTER_SITES=	OPENBSD/LibreSSL
=======
PORTVERSION=	2.3.0
CATEGORIES=	security devel
MASTER_SITES=	https://brnrd.eu/pub/OpenBSD/LibreSSL/ \
		OPENBSD/LibreSSL
>>>>>>> 10ca0771a28046affb4f5b25818def3a761c22de

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Free version of the SSL/TLS protocol forked from OpenSSL

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

CPE_VENDOR=	openbsd

<<<<<<< HEAD
CONFLICTS?=	openssl-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-silent-rules
=======
OPTIONS_DEFINE=	API_MAN
OPTIONS_DEFAULT=API_MAN
OPTIONS_SUB=	yes

API_MAN_DESC=	Install API manpages (command manpages always installed)

CONFLICTS?=	openssl-[0-9]* \
		tcltls-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable--silent-rules
>>>>>>> 10ca0771a28046affb4f5b25818def3a761c22de
USES=		cpe libtool pathfix pkgconfig
USE_LDCONFIG=	yes

CFLAGS+=	-Darc4random=libressl_arc4random -Darc4random_buf=libressl_arc4random_buf

INSTALL_TARGET=	install-strip

<<<<<<< HEAD
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.endif

=======
>>>>>>> 10ca0771a28046affb4f5b25818def3a761c22de
regression-test: build
	cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.post.mk>
