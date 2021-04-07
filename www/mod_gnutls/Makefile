PORTNAME=	mod_gnutls
PORTVERSION=	0.8.4
PORTREVISION=	2
CATEGORIES=	www security
MASTER_SITES=	https://mod.gnutls.org/downloads/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Extension for Apache httpd using GnuTLS library to provide HTTPS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgnutls.so:security/gnutls

GNU_CONFIGURE=	yes
USES=		apache:2.4 compiler:c++11-lang libtool pkgconfig tar:bzip2

DBDIR=		${PREFIX}/var/db/${PORTNAME}
PLIST_SUB=	SED="${SED}" WWWGRP=${WWWGRP} WWWOWN=${WWWOWN}
SUB_FILES=	pkg-message
SUB_LIST=	DBDIR="${DBDIR}"

CFLAGS+=	-Wno-deprecated-declarations
CONFIGURE_ARGS=	--with-apxs="${APXS}"

post-install:
	${MKDIR} "${STAGEDIR}${DBDIR}"

.include <bsd.port.mk>
