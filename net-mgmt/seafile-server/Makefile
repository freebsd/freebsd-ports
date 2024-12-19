PORTNAME=	seafile-server
DISTVERSIONPREFIX=	v
DISTVERSION=	${SEAFILE_VER}
PORTREVISION=	1
DISTVERSIONSUFFIX=	-server
CATEGORIES=	net-mgmt

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Open Source Cloud Storage (Server)
WWW=		https://github.com/haiwen/seafile-server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libevhtp.so:www/libevhtp \
		libzdb.so:databases/libzdb \
		libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify \
		libevent.so:devel/libevent \
		libuuid.so:misc/libuuid \
		libjansson.so:devel/jansson \
		libjwt.so:www/libjwt \
		libonig.so:devel/oniguruma
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		bash:shells/bash

CONFLICTS=	seafile

USES=		autoreconf compiler:c11 gnome iconv libarchive libtool localbase mysql \
		pathfix pgsql pkgconfig python shebangfix sqlite ssl vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
USE_GNOME=	glib20
USE_RC_SUBR=	seafile

SHEBANG_FILES=	tools/seafile-admin
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl \
		-lcrypto" PKG_CONFIG_PATH="${WRKDIR}/pkgconfig"
CFLAGS+=	-Wno-error=incompatible-function-pointer-types

PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include/evhtp

SUB_FILES=	pkg-message

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		FUSE LDAP NLS
OPTIONS_DEFAULT=	FUSE LDAP
OPTIONS_EXCLUDE_DragonFly=	FUSE
OPTIONS_SUB=		yes

FUSE_DESC=		Use file system in userspace

FUSE_CONFIGURE_ENABLE=	fuse
FUSE_LIB_DEPENDS=	libfuse.so:filesystems/fusefs-libs

LDAP_CONFIGURE_ENABLE=	ldap
LDAP_USES=		ldap

NLS_USES=		gettext

.include <bsd.port.pre.mk>

_PKGCONFIGDIR=	${WRKDIR}/pkgconfig

post-patch:
# Fix P_KTHREAD r295435
	${REINPLACE_CMD} 's/P_KTHREAD/P_KPROC/' ${WRKSRC}/lib/utils.c

# Fix python hardcodings
	${REINPLACE_CMD} 's/python3\.[0-9]/${PYTHON_VERSION}/g; s/python3 /${PYTHON_VERSION} / ; \
			s/PYTHON=python3/PYTHON=${PYTHON_VERSION}/ ; s|/python3/|/${PYTHON_VERSION}/|g' \
		${WRKSRC}/controller/seafile-controller.c

	@${MKDIR} ${_PKGCONFIGDIR}
.if ${MYSQL_FLAVOUR} == mariadb
# If mariadb is the selected flavor, link the pc file as
# mysqlclient so PKG_CHECK_MODULES can find it. Mariadb
# doesn't supply this file in the same way other flavours do.
	@${LN} -sf ${LOCALBASE}/libdata/pkgconfig/libmariadb.pc \
		${_PKGCONFIGDIR}/mysqlclient.pc
.elif ${SSL_DEFAULT} == base
# Add bogus pc file to satisfy mysqlclient depend for ssl=base
	@${PRINTF} 'Name:\nDescription:\nVersion:' \
		>${_PKGCONFIGDIR}/openssl.pc
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SEABIN} ${STAGEDIR}${PREFIX}/${SEALIB}
.for SERVPROG in seaf-fsck seafserv-gc seaf-fuse seaf-migrate \
		seaf-server seaf-server-init seafile-controller
	if [ -e "${STAGEDIR}${PREFIX}/bin/${SERVPROG}" ]; then \
		${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/${SERVPROG} ${STAGEDIR}${PREFIX}/${SEABIN}; \
		${RM} ${STAGEDIR}${PREFIX}/bin/${SERVPROG}; \
	fi
.endfor
.for SERVPROG in seafile-controller seaf-server
	${LN} -s "../${SEABIN}/${SERVPROG}" ${STAGEDIR}${PREFIX}/bin/${SERVPROG}
.endfor

	(cd ${STAGEDIR}${PREFIX}/lib && \
		${COPYTREE_SHARE} ${PYTHON_VERSION} ${STAGEDIR}${PREFIX}/${SEALIB})
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION} \
		${STAGEDIR}${PREFIX}/bin/seafile-admin
	(cd ${WRKSRC}/scripts && \
		${COPYTREE_SHARE} "sql" ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER})

makesum-all:
.for PORT in net-mgmt/seafile-server www/py-seafdav www/py-seafobj www/seahub
	${MAKE} -C "${PORTSDIR}/${PORT}" makesum
.endfor

.include "${.CURDIR}/Makefile.include"

.include <bsd.port.post.mk>
