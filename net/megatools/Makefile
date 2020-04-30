# Created by: Max V. Kostikov <max@kostikov.co>
# $FreeBSD$

PORTNAME=	megatools
PORTVERSION=	1.10.3
CATEGORIES=	net
MASTER_SITES=	https://megatools.megous.com/builds/

MAINTAINER=	max@kostikov.co
COMMENT=	Command line tools for MEGA.NZ cloud drive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc
LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		compiler:c11 gettext-runtime gmake gnome libtool pathfix \
		pkgconfig ssl
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto -lssl"

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
# Unsilence build
	${REINPLACE_CMD} -e '/^export\ MAKEFLAGS/s|^|#|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
