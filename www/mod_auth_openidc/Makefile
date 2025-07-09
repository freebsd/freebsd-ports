PORTNAME=	mod_auth_openidc
PORTVERSION=	2.4.17.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	OpenID Connect Relying Party and OAuth 2.0 Resource Server for Apache
WWW=		https://github.com/pingidentity/mod_auth_openidc/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcjose.so:devel/cjose \
		libcurl.so:ftp/curl \
		libjansson.so:devel/jansson \
		libaprutil-1.so:devel/apr1 \
		libexpat.so:textproc/expat2 \
		libpcre2-8.so:devel/pcre2

USES=		apache autoreconf cpe gmake libtool pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	pingidentity
CPE_VENDOR=	${GH_ACCOUNT}

PLIST_FILES=	${APACHEMODDIR}/mod_auth_openidc.so
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" \
		PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		HIREDIS
HIREDIS_DESC=		Enable using redis to store session data
HIREDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
HIREDIS_CONFIGURE_WITH=	hiredis

.include <bsd.port.options.mk>

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR} \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${PORTNAME}.so
	${INSTALL_DATA} ${WRKSRC}/auth_openidc.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes/auth_openidc.conf.sample

.include <bsd.port.mk>
