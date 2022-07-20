PORTNAME=	mod_amd
PORTVERSION=	g20150926
CATEGORIES=	net

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Asterisk app_amd for FreeSWITCH

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreeswitch.so:net/freeswitch

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	seanbright
GH_TAGNAME=	60daa7e

MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX}

PLIST_FILES=	etc/freeswitch/autoload_configs/amd.conf.xml \
		lib/freeswitch/mod/mod_amd.so

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/freeswitch/autoload_configs
	${INSTALL_DATA} ${FILESDIR}/amd.conf.xml \
		${STAGEDIR}${PREFIX}/etc/freeswitch/autoload_configs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/freeswitch/mod/mod_amd.so

.include <bsd.port.mk>
