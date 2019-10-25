# $FreeBSD$

PORTNAME=	kea
PORTVERSION=	${ISCVERSION:S/-P/P/:S/-beta/b/:S/a/.a/:S/rc/.rc/}
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ISC/kea/${ISCVERSION}
DISTNAME=	${PORTNAME}-${ISCVERSION}

MAINTAINER=	apevnev@me.com
COMMENT=	Alternative DHCP implementation by ISC

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblog4cplus.so:devel/log4cplus \
		libboost_system.so:devel/boost-libs

USES=		autoreconf compiler:c++11-lang iconv libtool pathfix ssl cpe

# ISC releases things like 1.4.0-P1, which our versioning doesn't like
ISCVERSION=	1.6.0

CPE_VENDOR=	isc
CPE_VERSION=	${ISCVERSION:C/-.*//}
.if ${ISCVERSION:M*-*}
CPE_UPDATE=	${ISCVERSION:C/.*-//:tl}
.endif

USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} \
		--with-log4cplus=${LOCALBASE} \
		--with-boost-include=${LOCALBASE}/include \
		--with-boost-lib-dir=${LOCALBASE}/lib \
		--without-werror
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	AUTHORS COPYING ChangeLog README \
		CONTRIBUTING.md examples

OPTIONS_DEFINE=	DOCS MYSQL PGSQL
OPTIONS_SUB=	yes
MYSQL_USE=	MYSQL=client
MYSQL_CONFIGURE_ON=	--with-dhcp-mysql=${LOCALBASE}/bin/mysql_config
MYSQL_CONFIGURE_OFF=	--without-dhcp-mysql
PGSQL_USES=	pgsql
WANT_PGSQL=	client
PGSQL_CONFIGURE_ON=	--with-dhcp-pgsql=${LOCALBASE}/bin/pg_config
PGSQL_CONFIGURE_OFF=	--without-dhcp-pgsql

.include <bsd.port.mk>
