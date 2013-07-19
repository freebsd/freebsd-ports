# $FreeBSD$

PORTNAME=	spmfilter
PORTVERSION=	0.4.2
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://www.${PORTNAME}.org/attachments/download/60/

MAINTAINER=	ast@treibsand.com
COMMENT=	Spmfilter is a high-performance mail filtering framework, written in C

LICENSE=	LGPL3

BUILD_DEPENDS=	gmime-24>=2.4:${PORTSDIR}/mail/gmime24 \
		libesmtp>=1.0:${PORTSDIR}/mail/libesmtp \
		glib>=2.14:${PORTSDIR}/devel/glib20

RUN_DEPENDS=	gmime-24>=2.4:${PORTSDIR}/mail/gmime24 \
		libesmtp>=1.0:${PORTSDIR}/mail/libesmtp \
		glib>=2.14:${PORTSDIR}/devel/glib20

USES=		cmake pkgconfig
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	DB4 DEBUG LDAP MYSQL PGSQL
OPTIONS_DEFAULT=	DB4
DB4_DESC=	DB4 backend

# Default requirement for spmfilter rc script
_REQUIRE=	LOGIN

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDB4}
USE_BDB=	yes
CMAKE_ARGS+=	-DDB4_INCLUDE_DIR="${BDB_INCLUDE_DIR}"
.else
CMAKE_ARGS+=	-DWITHOUT_DB4=TRUE
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=	-DENABLE_DEBUG=TRUE
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	yes
.if ${PORT_OPTIONS:MOPENLDAP_VER}
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif
_REQUIRE+=	slapd
.else
CMAKE_ARGS+=	-DWITHOUT_LDAP=TRUE
.endif

.if ${PORT_OPTIONS:MMYSQL}
LIB_DEPENDS+=	zdb:${PORTSDIR}/databases/libzdb
USE_MYSQL=	yes
_REQUIRE+=	mysql
.else
CMAKE_ARGS+=	-DWITHOUT_ZDB=TRUE
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
_REQUIRE+=	postgresql
.endif

MAN1=		${PORTNAME}.1
MAN5=		${PORTNAME}.conf.5
MANCOMPRESSED=	yes

SUB_LIST+=	REQUIRE="${_REQUIRE}"

PLIST_SUB=	LIB_VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' \
		${WRKSRC}/cmake/Modules/SMFMacros.cmake
	@${REINPLACE_CMD} -E -e 's|(HAVE_DB4 )db|\1${BDB_LIB_NAME}|' \
		${WRKSRC}/cmake/Modules/FindDB4.cmake
	@${REINPLACE_CMD} -E -e 's|\$${LIBDIR}(/pkgconfig)|$${CMAKE_INSTALL_PREFIX}/libdata\1|' \
		-e 's|(COMMON_LIBS )db|\1${BDB_LIB_NAME}|' \
		${WRKSRC}/src/CMakeLists.txt

post-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${PREFIX}/etc/
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf ; \
	fi

.include <bsd.port.mk>
