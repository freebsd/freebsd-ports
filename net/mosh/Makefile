# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mosh
PORTVERSION=	1.2.5
CATEGORIES=	net
MASTER_SITES=	http://mosh.mit.edu/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Mobile terminal that supports intermittent connectivity

LICENSE=	GPLv3

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-utempter --without-ncurses
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" \
		TINFO_CFLAGS="-I/usr/include"
INSTALL_TARGET=	install-strip
USE_OPENSSL=	yes
USES=		autoreconf:autoconf ncurses perl5 pkgconfig

CONFLICTS_INSTALL=	mosh-0.[2-9].*

PLIST_FILES=	bin/mosh bin/mosh-server bin/mosh-client \
		man/man1/mosh-client.1.gz man/man1/mosh-server.1.gz man/man1/mosh.1.gz

.include <bsd.port.mk>
