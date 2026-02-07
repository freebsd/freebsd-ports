PORTNAME=	yaz
DISTVERSION=	5.35.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://ftp.indexdata.dk/pub/${PORTNAME}/

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Z39.50/SR client and API library
WWW=		https://www.indexdata.com/resources/software/yaz/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libgnutls.so:security/gnutls

USES=		autoreconf gnome iconv libtool ncurses pathfix \
		localbase:ldflags pkgconfig readline shebangfix tcl:build,run
SHEBANG_FILES=	src/yaz-asncomp
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

USE_CSTD=	c89
CFLAGS+=	-Wno-error=int-conversion
LIBS+=		-lexecinfo

PORTDOCS=	*

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--enable-shared \
		--enable-tcpd \
		--with-iconv=${ICONV_PREFIX} \
		--with-icu \
		--with-xml2 \
		--with-xslt

OPTIONS_DEFINE=	DOCS MEMCACHED REDIS

MEMCACHED_DESC=		Memcached distributed cache system support

MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached
MEMCACHED_CONFIGURE_WITH=	memcached

REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_CONFIGURE_WITH=	redis

.include <bsd.port.mk>
