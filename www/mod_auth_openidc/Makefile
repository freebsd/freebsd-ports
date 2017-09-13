# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_auth_openidc
PORTVERSION=	2.3.1
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

USE_GITHUB=	yes
GH_ACCOUNT=	pingidentity

PLIST_FILES=	${APACHEMODDIR}/mod_auth_openidc.so

USE_APACHE=	22+
USES=		autoreconf:autoconf gmake libtool pkgconfig ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-hiredis
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto" \
		PKG_CONFIG_PATH="${LOCALBASE}/libdata/pkgconfig"
SUB_FILES=	pkg-message

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
