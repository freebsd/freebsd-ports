# Created by: Max V. Kostikov <max@kostikov.co>
# $FreeBSD$

PORTNAME=	megatools
PORTVERSION=	1.9.98
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://megatools.megous.com/builds/

MAINTAINER=	max@kostikov.co
COMMENT=	Command line tools for MEGA.NZ cloud drive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl
BUILD_DEPENDS=	asciidoc:textproc/asciidoc

CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"
USES=		gettext-runtime gmake libtool pathfix pkgconfig ssl
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

INSTALL_TARGET=	install-strip

post-patch:
# Unsilence build
	${REINPLACE_CMD} -e '/^export\ MAKEFLAGS/s|^|#|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
