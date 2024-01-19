PORTNAME=	super_mediator
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.netsa.cert.org/releases/

MAINTAINER=	nacho319+freebsdZilla@gmail.com
COMMENT=	IPFIX mediator by CMU CERT generally used with YAF
WWW=		https://tools.netsa.cert.org/super_mediator/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfixbuf.so:net/libfixbuf \
		libltdl.so:devel/libltdl

USES=		compiler:c11 gnome libtool pathfix perl5 pkgconfig ssl
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	SPREAD MYSQL SKIPSET
OPTIONS_DEFAULT=	MYSQL SKIPSET

MYSQL_DESC=	Enable SuperMediator to directly write into MySQL
SKIPSET_DESC=	Enable SiLK IPSET files for filtering
SPREAD_DESC=	Enable Spread libary as a pub/sub distribution capability

MYSQL_LIB_DEPENDS=	libmysqlclient.so:${_MYSQL_CLIENT}
MYSQL_USES=	mysql
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_VARS=	IGNORE_WITH_MYSQL="80 81"
SKIPSET_LIB_DEPENDS=	libsilk.so:security/silktools
SKIPSET_CONFIGURE_WITH=	skipset
SPREAD_LIB_DEPENDS=	libspread.so:net/spread4
SPREAD_CONFIGURE_WITH=	spread

post-install:
.for f in super_mediator.conf
	${MV} ${STAGEDIR}${PREFIX}/etc/$f ${STAGEDIR}${PREFIX}/etc/$f.sample
.endfor

.include <bsd.port.mk>
