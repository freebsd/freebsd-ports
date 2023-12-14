PORTNAME=	mosh
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Mobile terminal that supports intermittent connectivity
WWW=		https://mosh.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

USES=		autoreconf compiler:c++17-lang ncurses perl5 pkgconfig ssl
USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-utempter --without-ncurses
CONFIGURE_ENV+=	OpenSSL_CFLAGS="-I${OPENSSLINC}" OpenSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" \
		TINFO_CFLAGS="-I/usr/include" ac_cv_have_decl_bswap64=yes
INSTALL_TARGET=	install-strip
USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	mobile-shell

CONFLICTS_INSTALL=	mosh-0.[2-9].*

PLIST_FILES=	bin/mosh bin/mosh-server bin/mosh-client \
		man/man1/mosh-client.1.gz man/man1/mosh-server.1.gz man/man1/mosh.1.gz

.include <bsd.port.mk>
