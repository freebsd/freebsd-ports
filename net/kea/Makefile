# $FreeBSD$

PORTNAME=	kea
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ISC/kea/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Alternative DHCP implementation by ISC

LICENSE=	MPL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblog4cplus.so:devel/log4cplus \
		libboost_system.so:devel/boost-libs

USES=		autoreconf compiler:c++11-lang libtool pathfix python:3.3+ ssl
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} \
		--with-log4cplus=${LOCALBASE} \
		--with-boost-include=${LOCALBASE}/include \
		--with-boost-lib-dir=${LOCALBASE}/lib \
		--without-werror
INSTALL_TARGET=	install-strip
PORTDOCS=	AUTHORS COPYING ChangeLog README \
		kea-guide.css kea-guide.html kea-guide.txt \
		kea-messages.html kea-logo-100x70.png \
		examples

OPTIONS_DEFINE=	DOCS MYSQL PGSQL
DOCS_MAKE_ARGS_OFF= \
		INSTALL_STRIP_PROGRAM="${WRKSRC}/install-sh -c -s" \
		INSTALL_STRIP_FLAG="-s" \
		INSTALL_PROGRAM_ENV="STRIPPROG=${STRIP}"
DOCS_INSTALL_TARGET_OFF= \
		install-exec-am \
		install-pkgconfigDATA \
		install-pkgincludeHEADERS
MYSQL_USE=	MYSQL=client
MYSQL_CONFIGURE_ON=	--with-dhcp-mysql=${LOCALBASE}/bin/mysql_config
MYSQL_CONFIGURE_OFF=	--without-dhcp-mysql
PGSQL_USES=	pgsql
WANT_PGSQL=	client
PGSQL_CONFIGURE_ON=	--with-dhcp-pgsql=${LOCALBASE}/bin/pg_config
PGSQL_CONFIGURE_OFF=	--without-dhcp-pgsql

.include <bsd.port.mk>
