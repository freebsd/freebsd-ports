# Created by: Inacio <nacho319+freebsdZilla@gmail.com>
# $FreeBSD$

PORTNAME=	super_mediator
PORTVERSION=	1.6.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://tools.netsa.cert.org/releases/

MAINTAINER=	nacho319+freebsdZilla@gmail.com
COMMENT=	IPFIX mediator by CMU CERT generally used with YAF

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfixbuf.so:net/libfixbuf \
		libltdl.so:devel/libltdl

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c11 gnome libtool pathfix perl5 pkgconfig ssl
USE_GNOME=	glib20

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	SPREAD MYSQL SKIPSET
OPTIONS_DEFAULT=	MYSQL SKIPSET

SPREAD_DESC=	Enable Spread libary as a pub/sub distribution capability
MYSQL_DESC=	Enable SuperMediator to directly write into MySQL
SKIPSET_DESC=	Enable SiLK IPSET files for filtering

SKIPSET_LIB_DEPENDS=	libsilk.so:security/silktools
SPREAD_LIB_DEPENDS=	libspread.so:net/spread4
MYSQL_LIB_DEPENDS=	libmysqlclient.so:${_MYSQL_CLIENT}

MYSQL_USES=	mysql

MYSQL_CONFIGURE_WITH=	mysql
SKIPSET_CONFIGURE_WITH=	skipset
SPREAD_CONFIGURE_WITH=	spread

post-install:
.for f in super_mediator.conf
	${MV} ${STAGEDIR}${PREFIX}/etc/$f ${STAGEDIR}${PREFIX}/etc/$f.sample
.endfor

.include <bsd.port.mk>
