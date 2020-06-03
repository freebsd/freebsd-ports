# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mosh
PORTVERSION=	1.3.2
PORTREVISION=	13
CATEGORIES=	net
MASTER_SITES=	https://mosh.org/ \
		ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Mobile terminal that supports intermittent connectivity

LICENSE=	GPLv3

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-utempter --without-ncurses
CONFIGURE_ENV+=	CRYPTO_CFLAGS="-I${OPENSSLINC}" CRYPTO_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" \
		TINFO_CFLAGS="-I/usr/include"
INSTALL_TARGET=	install-strip
USES=		compiler:c++11-lang ncurses perl5 pkgconfig ssl
USE_CXXSTD=	c++11

CONFLICTS_INSTALL=	mosh-0.[2-9].*

PLIST_FILES=	bin/mosh bin/mosh-server bin/mosh-client \
		man/man1/mosh-client.1.gz man/man1/mosh-server.1.gz man/man1/mosh.1.gz

.include <bsd.port.mk>
