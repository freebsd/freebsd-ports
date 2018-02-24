# $FreeBSD$

PORTNAME=	mod_gnutls
PORTVERSION=	0.8.3
CATEGORIES=	www security
MASTER_SITES=	https://mod.gnutls.org/downloads/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Extension for Apache httpd using GnuTLS library to provide HTTPS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgnutls.so:security/gnutls

GNU_CONFIGURE=	yes
USES=		libtool pkgconfig tar:bzip2
USE_APACHE=	24

DBDIR=		${PREFIX}/var/db/${PORTNAME}
PLIST_SUB=	SED="${SED}" WWWGRP=${WWWGRP} WWWOWN=${WWWOWN}
SUB_FILES=	pkg-message
SUB_LIST=	DBDIR="${DBDIR}"

CFLAGS+=	-Wno-deprecated-declarations
CONFIGURE_ARGS=	--with-apxs="${APXS}"

post-install:
	${MKDIR} "${STAGEDIR}${DBDIR}"

.include <bsd.port.mk>
