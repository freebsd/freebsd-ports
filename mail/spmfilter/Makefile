# $FreeBSD$

PORTNAME=	spmfilter
PORTVERSION=	0.6.3
CATEGORIES=	mail
MASTER_SITES=	http://www.${PORTNAME}.org/files/

MAINTAINER=	ast@treibsand.com
COMMENT=	Spmfilter is a high-performance mail filtering framework, written in C

LICENSE=	LGPL3

BUILD_DEPENDS=	libcmime>=0.1:${PORTSDIR}/mail/libcmime \
		libesmtp>=1.0:${PORTSDIR}/mail/libesmtp

RUN_DEPENDS=	libcmime>=0.1:${PORTSDIR}/mail/libcmime \
		libesmtp>=1.0:${PORTSDIR}/mail/libesmtp

SMFUSER?=	nobody
SMFGROUP?=	mail
SMFDIR?=	/var/spool/spmfilter

USES=		cmake pkgconfig
CMAKE_ARGS+=	--no-warn-unused-cli \
		-DCMAKE_INCLUDE_PATH="${LOCALBASE}/include" \
		-DCMAKE_LIBRARY_PATH="${LOCALBASE}/lib"
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	DB4 DEBUG LDAP MYSQL PGSQL
OPTIONS_DEFAULT=	DB4
DB4_DESC=	DB4 backend

# Default requirement for spmfilter rc script
_REQUIRE=	LOGIN

NO_STAGE=	yes

SUB_FILES=	pkg-install pkg-deinstall

SUB_LIST+=	SMFUSER=${SMFUSER} \
		SMFGROUP=${SMFGROUP} \
		SMFDIR=${SMFDIR} \

PLIST_SUB=	LIB_VERSION=${PORTVERSION}

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
.else
CMAKE_ARGS+=	-DWITHOUT_LDAP=TRUE
.endif

.if ${PORT_OPTIONS:MMYSQL}
LIB_DEPENDS+=	zdb:${PORTSDIR}/databases/libzdb
USE_MYSQL=	yes
_REQUIRE+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
LIB_DEPENDS+=	zdb:${PORTSDIR}/databases/libzdb
USE_PGSQL=	yes
_REQUIRE+=	postgresql
.endif

.if !${PORT_OPTIONS:MMYSQL} && !${PORT_OPTIONS:MPGSQL}
CMAKE_ARGS+=	-DWITHOUT_ZDB=TRUE
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
	@${REINPLACE_CMD} -E -e 's|\$${CMAKE_INSTALL_LIBDIR}(/pkgconfig)|$${CMAKE_INSTALL_PREFIX}/libdata\1|' \
		-e 's|(COMMON_LIBS )db|\1${BDB_LIB_NAME}|' \
		${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|clamav;spamassassin||' \
		${WRKSRC}/spmfilter.conf.sample

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${PREFIX}/etc/
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}.conf ; \
	fi

.include <bsd.port.mk>
