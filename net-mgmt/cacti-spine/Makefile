PORTNAME=	spine
DISTVERSION=	1.2.30
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.cacti.net/downloads/${PORTNAME}/
DISTNAME=	cacti-${PORTNAME}-${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Multithreaded poller for Cacti written in C
WWW=		https://cacti.net/spine_info.php

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp \
		libpkg.so:${PKG_ORIGIN}

USES=		autoreconf libtool mysql ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE} --with-snmp=${LOCALBASE}
CPPFLAGS+=	`net-snmp-config --cflags` -Wno-error=declaration-after-statement
LDFLAGS+=	`net-snmp-config --libs` -lexecinfo

CONFLICTS_INSTALL=	cacti88

post-patch:
	@${REINPLACE_CMD} \
		's,#define\ *DEFAULT_CONF_FILE .*,#define DEFAULT_CONF_FILE "${PREFIX}/etc/spine.conf",' \
		${WRKSRC}/spine.h

post-install:
	${MV}	${STAGEDIR}${PREFIX}/etc/spine.conf.dist \
		${STAGEDIR}${PREFIX}/etc/spine.conf.sample

.include <bsd.port.mk>
