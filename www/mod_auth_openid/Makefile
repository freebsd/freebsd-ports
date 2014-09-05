# Created by: Sutra Zhou <zhoushuqun@gmail.com>
# $FreeBSD$

PORTNAME=	mod_auth_openid
PORTVERSION=	0.8
CATEGORIES=	www
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Authentication module for the Apache 2 webserver with OpenID

LIB_DEPENDS=	libopkele.so:${PORTSDIR}/devel/libopkele \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	bmuller
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	22d1719

PLIST_FILES=	${APACHEMODDIR}/mod_auth_openid.so

USE_APACHE=	22+
USES=		gmake pkgconfig libtool
USE_AUTOTOOLS=	aclocal libtoolize autoconf automake autoheader
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre=${LOCALBASE}

CFLAGS+=	-I${LOCALBASE}/include -I/usr/include/openssl

post-patch:
	@${REINPLACE_CMD} -e 's|$${APXS} -i|$${APXS} -S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR} -i|' \
		${WRKSRC}/src/Makefile.am

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

.include <bsd.port.mk>
