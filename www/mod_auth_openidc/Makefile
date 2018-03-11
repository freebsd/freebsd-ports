# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_auth_openidc
PORTVERSION=	2.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	OpenID Connect Relying Party and OAuth 2.0 Resource Server for Apache

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcjose.so:devel/cjose \
		libcurl.so:ftp/curl \
		libjansson.so:devel/jansson \
		libpcre.so:devel/pcre

USES=		apache:2.2+ autoreconf cpe gmake libtool pkgconfig ssl
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

post-patch:
	@${REINPLACE_CMD} -e \
		's|@APXS2@ @APXS2_OPTS@ -i|@APXS2@ @APXS2_OPTS@ -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} -i|' \
		${WRKSRC}/Makefile.in

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR} \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${PORTNAME}.so
	${INSTALL_DATA} ${WRKSRC}/auth_openidc.conf \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes/auth_openidc.conf.sample

.include <bsd.port.mk>
