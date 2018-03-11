# Created by: Sutra Zhou <zhoushuqun@gmail.com>
# $FreeBSD$

PORTNAME=	mod_auth_openid
PORTVERSION=	0.8
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Authentication module for the Apache 2 webserver with OpenID

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libopkele.so:devel/libopkele \
		libsqlite3.so:databases/sqlite3

USES=		apache:2.2+ autoreconf cpe gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	bmuller

PLIST_FILES=	${APACHEMODDIR}/mod_auth_openid.so
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include -I/usr/include/openssl

CPE_VENDOR=	findingscience

post-patch:
	@${REINPLACE_CMD} -e 's|$${APXS} -i|$${APXS} -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} -i|' \
		${WRKSRC}/src/Makefile.am

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/${PORTNAME}.so

.include <bsd.port.mk>
