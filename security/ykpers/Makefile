PORTNAME=	ykpers
PORTVERSION=	1.19.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubikey-personalization/Releases/

MAINTAINER=	matt@mjslabs.com
COMMENT=	Library and tool for personalization of Yubico's YubiKey

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libyubikey.so:security/libyubikey

USES=		gmake libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PLIST_FILES=	bin/ykchalresp \
		bin/ykinfo \
		bin/ykpersonalize \
		include/ykpers-1/ykcore.h \
		include/ykpers-1/ykdef.h \
		include/ykpers-1/ykpbkdf2.h \
		include/ykpers-1/ykpers.h \
		include/ykpers-1/ykpers-version.h \
		include/ykpers-1/ykstatus.h \
		lib/libykpers-1.so \
		lib/libykpers-1.so.1 \
		lib/libykpers-1.so.${PORTVERSION} \
		libdata/pkgconfig/ykpers-1.pc \
		man/man1/ykchalresp.1.gz \
		man/man1/ykinfo.1.gz \
		man/man1/ykpersonalize.1.gz

OPTIONS_DEFINE=	STATIC

STATIC_CONFIGURE_ENABLE=	static
STATIC_PLIST_FILES=		lib/libykpers-1.a

.include <bsd.port.mk>
