PORTNAME=	kea
DISTVERSION=	2.6.1
CATEGORIES=	net
MASTER_SITES=	ISC/kea/${DISTVERSION}

MAINTAINER=	apevnev@me.com
COMMENT=	Alternative DHCP implementation by ISC
WWW=		https://kea.isc.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		liblog4cplus.so:devel/log4cplus

USES=		autoreconf compiler:c++11-lang cpe iconv libtool pathfix ssl

CPE_VENDOR=	isc
CPE_VERSION=	${DISTVERSION:C/-.*//}
.if ${DISTVERSION:M*-*}
CPE_UPDATE=	${DISTVERSION:C/.*-//:tl}
.endif

USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-boost-include=${LOCALBASE}/include \
		--with-boost-lib-dir=${LOCALBASE}/lib \
		--with-log4cplus=${LOCALBASE} \
		--with-openssl=${OPENSSLBASE} \
		--without-werror
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	AUTHORS CONTRIBUTING.md COPYING ChangeLog README SECURITY.md \
		code_of_conduct.md examples platforms.rst

OPTIONS_DEFINE=	DOCS MYSQL PGSQL SHELL
OPTIONS_SUB=	yes

SHELL_DESC=	Install kea-shell(8) (Python)

MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}/bin/mysql_config
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_SUB_LIST=		REQ_MYSQL=mysql
MYSQL_SUB_LIST_OFF=	REQ_MYSQL=""

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}/bin/pg_config
PGSQL_CONFIGURE_OFF=	--without-pgsql
PGSQL_SUB_LIST=		REQ_PGSQL=postgresql
PGSQL_SUB_LIST_OFF=	REQ_PGSQL=""
PGSQL_VARS=		WANT_PGSQL=client

SHELL_USES=		python
SHELL_CONFIGURE_ON=	--enable-shell

.include <bsd.port.mk>
