# New ports collection makefile for: 	spmfilter
# Date created:				2010-04-12
# Whom:					Frank Wall <fw@moov.de>
#
# $FreeBSD$
#

PORTNAME=	spmfilter
PORTVERSION=	0.4.1
CATEGORIES=	mail
MASTER_SITES=	http://www.${PORTNAME}.org/attachments/download/54/

MAINTAINER=	fw@moov.de
COMMENT=	Spmfilter is a high-performance mail filtering framework, written in C

BUILD_DEPENDS=	gmime-24>=2.4:${PORTSDIR}/mail/gmime24 \
		libesmtp>=1.0:${PORTSDIR}/mail/libesmtp \
		glib>=2.14:${PORTSDIR}/devel/glib20

RUN_DEPENDS=	gmime-24>=2.4:${PORTSDIR}/mail/gmime24 \
		libesmtp>=1.0:${PORTSDIR}/mail/libesmtp \
		glib>=2.14:${PORTSDIR}/devel/glib20

USE_CMAKE=	yes
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

OPTIONS=	DB4 	"Enable DB4 backend" 	on  \
		DEBUG 	"Enable Debugging" 	off \
		LDAP 	"Enable LDAP backend" 	off \
		MYSQL 	"Enable MYSQL backend" 	off \
		PGSQL	"Enable PGSQL backend"	off

# Default requirement for spmfilter rc script
_REQUIRE=	LOGIN

.include <bsd.port.pre.mk>

.if !defined(WITH_DB4) || defined(WITHOUT_DB4)
CMAKE_ARGS+=	-DWITHOUT_DB4=TRUE
.else
USE_BDB=	yes
CMAKE_ARGS+=	-DDB4_INCLUDE_DIR="${BDB_INCLUDE_DIR}"
.endif

.if defined(WITH_DEBUG)
CMAKE_ARGS+=	-DENABLE_DEBUG=TRUE
.endif

.if !defined(WITH_LDAP) || defined(WITHOUT_LDAP)
CMAKE_ARGS+=	-DWITHOUT_LDAP=TRUE
.else
USE_OPENLDAP=	yes
.if defined(WITH_OPENLDAP_VER)
WANT_OPENLDAP_VER=	${WITH_OPENLDAP_VER}
.endif
_REQUIRE+=	slapd
.endif

.if !defined(WITH_MYSQL) && !defined(WITH_PGSQL)
CMAKE_ARGS+=	-DWITHOUT_ZDB=TRUE
.else
LIB_DEPENDS+=	zdb:${PORTSDIR}/databases/libzdb
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
_REQUIRE+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
_REQUIRE+=	postgresql
.endif

MAN1=		${PORTNAME}.1
MAN5=		${PORTNAME}.conf.5
MANCOMPRESSED=	yes

SUB_LIST+=	REQUIRE="${_REQUIRE}"

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

.include <bsd.port.post.mk>
