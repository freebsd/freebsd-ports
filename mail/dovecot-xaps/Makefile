PORTNAME=	dovecot-xaps
DISTVERSION=	g20210623
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	PopularMoment@protonmail.com
COMMENT=	Apple push notifications plugin for dovecot
WWW=		https://github.com/freswa/dovecot-xaps-plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dovecot>=2.3.17:mail/dovecot
RUN_DEPENDS=	dovecot>=2.3.17:mail/dovecot \
		xapsd:net/xapsd

USES=		cmake compiler:c11
CMAKE_BUILD_TYPE=	Release
CMAKE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	freswa
GH_PROJECT=	dovecot-xaps-plugin
GH_TAGNAME=	197d68e

LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/dovecot

PLIST_FILES=	etc/dovecot/example-config/conf.d/95-xaps.conf \
		lib/dovecot/lib25_xaps_imap_plugin.so \
		lib/dovecot/lib25_xaps_push_notification_plugin.so

post-stage:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dovecot/example-config/conf.d/
	${INSTALL_DATA} ${WRKSRC}/xaps.conf \
		 ${STAGEDIR}${PREFIX}/etc/dovecot/example-config/conf.d/95-xaps.conf

.include <bsd.port.mk>
