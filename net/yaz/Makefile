# Created by: Dmitry Sivachenko <dima@Chg.RU>
# $FreeBSD$

PORTNAME=	yaz
DISTVERSION=	5.28.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ftp.indexdata.dk/pub/yaz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Z39.50/SR client and API library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libgnutls.so:security/gnutls

USES=		gnome iconv libtool ncurses pathfix pkgconfig readline \
		shebangfix tcl
SHEBANG_FILES=	util/yaz-asncomp
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2 libxslt
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--enable-shared --with-iconv=${ICONV_PREFIX} \
		--with-xml2=${LOCALBASE} --with-xslt=${LOCALBASE} \
		--with-icu=${LOCALBASE} --enable-tcpd
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lexecinfo

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS MEMCACHED REDIS

MEMCACHED_DESC=		Memcached distributed cache system support
MEMCACHED_CONFIGURE_WITH=	memcached
MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached

REDIS_CONFIGURE_WITH=	redis
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis

post-patch:
	@${REINPLACE_CMD} 's|tclsh |tclsh8.6 |' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's,[$$]{datarootdir}/man,${PREFIX}/man,' \
		${WRKSRC}/doc/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.*

.include <bsd.port.mk>
