PORTNAME=	cyrus-sasl2-xoauth2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	security

MAINTAINER=	thierry.dussuet@protonmail.com
COMMENT=	XOAUTH2 plugin for cyrus-sasl2
WWW=		https://github.com/moriyoshi/cyrus-sasl-xoauth2/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	moriyoshi
GH_PROJECT=	cyrus-sasl-xoauth2
USE_LDCONFIG=	${PREFIX}/lib/sasl2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cyrus-sasl=${PREFIX}

post-extract:
	${MKDIR} ${WRKSRC}/m4

post-install:
	${INSTALL_LIB} ${WRKSRC}/.libs/libxoauth2.so.0.0.0 ${STAGEDIR}${PREFIX}/lib/sasl2
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libxoauth2.a ${STAGEDIR}${PREFIX}/lib/sasl2

PLIST_FILES=	lib/sasl2/libxoauth2.a \
		lib/sasl2/libxoauth2.so \
		lib/sasl2/libxoauth2.so.0 \
		lib/sasl2/libxoauth2.so.0.0.0

.include <bsd.port.mk>
