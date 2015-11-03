# $FreeBSD$

PORTNAME=	ccnet
PORTVERSION=	4.0.6
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-server
PORTREVISION=	6
CATEGORIES=	net-mgmt devel

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Framework for writing networked applications

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libsearpc.so:${PORTSDIR}/devel/libsearpc \
		libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libgobject-2.0.so:${PORTSDIR}/devel/glib20 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libzdb.so:${PORTSDIR}/databases/libzdb \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libevent.so:${PORTSDIR}/devel/libevent2 \
		libjansson.so:${PORTSDIR}/devel/jansson \
		libldap.so:${PORTSDIR}/net/openldap24-client

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

USES=		autoreconf libtool pkgconfig pathfix python:2
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/event2
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/event2
CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-server --enable-ldap
INSTALL_TARGET=	install-strip

USE_OPENSSL=	yes

HAIWENDIR=	www/haiwen
SEAFILE_SERVER=	${HAIWENDIR}/seafile-server
SEABIN=		${SEAFILE_SERVER}/seafile/bin
SEALIB=		${SEAFILE_SERVER}/seafile/lib

SEAFILE_USERNAME?=	www
SEAFILE_GROUPNAME?=	${SEAFILE_USERNAME}

PLIST_SUB=	SEAFILE_USERNAME=${SEAFILE_USERNAME} \
		SEAFILE_GROUPNAME=${SEAFILE_GROUPNAME} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		HAIWENDIR=${HAIWENDIR}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SEABIN} ${STAGEDIR}${PREFIX}/${SEALIB}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/ccnet-init ${STAGEDIR}${PREFIX}/${SEABIN}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/ccnet-server ${STAGEDIR}${PREFIX}/${SEABIN}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/ccnet-servtool ${STAGEDIR}${PREFIX}/${SEABIN}
	${RM} ${STAGEDIR}${PREFIX}/bin/ccnet-init \
		${STAGEDIR}${PREFIX}/bin/ccnet-server \
		${STAGEDIR}${PREFIX}/bin/ccnet-servtool
	(cd ${STAGEDIR}${PREFIX}/lib && \
		${COPYTREE_SHARE} ${PYTHON_VERSION} ${STAGEDIR}${PREFIX}/${SEALIB})
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}

.include <bsd.port.mk>
