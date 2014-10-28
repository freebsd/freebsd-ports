# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	yaz
PORTVERSION=	5.4.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Z39.50/SR client and API library

LIB_DEPENDS=	libicuuc.so:${PORTSDIR}/devel/icu

USES=		iconv libtool pathfix pkgconfig shebangfix tcl
SHEBANG_FILES=	util/yaz-asncomp
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=--enable-shared --with-openssl=${OPENSSLBASE} \
		--with-iconv=${ICONV_PREFIX} --with-xml2=${LOCALBASE} \
		--with-xslt=${LOCALBASE} --with-icu=${LOCALBASE} \
		--enable-tcpd

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS MEMCACHED REDIS

MEMCACHED_DESC=		Memcached distributed cache system support
MEMCACHED_CONFIGURE_WITH=	memcached
MEMCACHED_LIB_DEPENDS=	libmemcached.so:${PORTSDIR}/databases/libmemcached

REDIS_CONFIGURE_WITH=	redis
REDIS_LIB_DEPENDS=	libhiredis.so:${PORTSDIR}/databases/hiredis
REDIS_LDFLAGS=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} 's|tclsh |tclsh8.6 |' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's,[$$]{datarootdir}/man,${PREFIX}/man,' \
		${WRKSRC}/doc/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.5

.include <bsd.port.mk>
