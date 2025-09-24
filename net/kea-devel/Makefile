PORTNAME=	kea
DISTVERSION=	3.1.2
CATEGORIES=	net
MASTER_SITES=	ISC/kea/cur/3.1
PKGNAMESUFFIX=	-devel

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Alternative DHCP implementation by ISC
WWW=		https://kea.isc.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rst2man:textproc/py-docutils

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		liblog4cplus.so:devel/log4cplus

USES=		compiler:c++11-lang cmake:indirect cpe iconv libtool meson \
		pathfix pkgconfig python tar:xz shebangfix ssl

CPE_VENDOR=	isc
CPE_VERSION=	${DISTVERSION:C/-.*//}
.if ${DISTVERSION:M*-*}
CPE_UPDATE=	${DISTVERSION:C/.*-//:tl}
.endif

USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME}
INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS CONTRIBUTING.md COPYING ChangeLog README SECURITY.md \
		code_of_conduct.md examples platforms.rst

OPTIONS_DEFINE=	DOCS MYSQL PGSQL
OPTIONS_SUB=	yes

MESON_ARGS=	--auto-features=disabled \
		-Dnetconf=disabled \
		-Drunstatedir=/var/run

SHEBANG_GLOB=	*.py *.in
python_OLD_CMD+=@PYTHON@
		
MYSQL_USES=		mysql
MYSQL_MESON_ENABLED=	mysql
MYSQL_SUB_LIST=		REQ_MYSQL=mysql
MYSQL_SUB_LIST_OFF=	REQ_MYSQL=""

PGSQL_USES=		pgsql
PGSQL_MESON_ENABLED=	postgresql
PGSQL_SUB_LIST=		REQ_PGSQL=postgresql
PGSQL_SUB_LIST_OFF=	REQ_PGSQL=""
PGSQL_VARS=		WANT_PGSQL=lib

post-build:
	cd ${WRKSRC}/doc/sphinx/man; \
	for i in *.8.rst; do rst2man $$i > $$(basename $$i .rst); done

post-install:
	@mkdir -p ${STAGEDIR}${PREFIX}/etc/kea ${STAGEDIR}/var/db/kea \
	${STAGEDIR}/var/log/kea ${STAGEDIR}/var/run/kea
	@rm -rf ${STAGEDIR}${PREFIX}/var
	@cd ${WRKSRC}/doc/sphinx/man; \
	cp *.8 ${STAGEDIR}${PREFIX}/share/man/man8
	@cd ${WRKSRC}/_build/src/bin/keactrl; \
	for i in *.conf; do cp $$i ${STAGEDIR}${PREFIX}/etc/kea/$$i.sample; done

.include <bsd.port.mk>
