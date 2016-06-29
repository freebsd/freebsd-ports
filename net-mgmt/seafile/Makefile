# $FreeBSD$

PORTNAME=	seafile
PORTVERSION=	5.1.3
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-server
CATEGORIES=	net-mgmt

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Open Source Cloud Storage (Server)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libevhtp.so:www/libevhtp \
		libzdb.so:databases/libzdb \
		libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify \
		libccnet.so:net-mgmt/ccnet \
		libevent.so:devel/libevent2 \
		libuuid.so:misc/e2fsprogs-libuuid \
		libjansson.so:devel/jansson
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

USES=		autoreconf gettext iconv libarchive libtool mysql pathfix \
		pkgconfig python:-2.7 shebangfix sqlite
USE_GNOME=	glib20
SHEBANG_FILES=	scripts/*.sh scripts/upgrade/*.sh  tests/*.py tests/basic/*.sh \
		tests/sync-auto-test/*.template *.sh scripts/build/*.py \
		scripts/*.py *.py scripts/upgrade/*.py app/seaf-cli \
		tools/seafile-admin
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

PATHFIX_MAKEFILEIN=	Makefile.am

CONFIGURE_ARGS=	--enable-server
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/evhtp
LDFLAGS+=	-L${LOCALBASE}/lib

HAIWENDIR=	www/haiwen
SEAFILE_SERVER=	${HAIWENDIR}/seafile-server
SEABIN=		${SEAFILE_SERVER}/seafile/bin
SEALIB=		${SEAFILE_SERVER}/seafile/lib

USERS=		seafile
GROUPS=		${USERS}

USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		HAIWENDIR=${HAIWENDIR}

SUB_FILES=	pkg-message

SUB_LIST+=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		HAIWENDIR=${HAIWENDIR}

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		FUSE RIAK
OPTIONS_SUB=		yes

FUSE_DESC=		Use file system in userspace
RIAK_DESC=		Use distributed noSQL database

FUSE_CONFIGURE_ENABLE=	fuse
FUSE_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs

RIAK_CONFIGURE_ENABLE=	riak
RIAK_RUN_DEPENDS=	riak:databases/riak

OPTIONS_DEFAULT=	FUSE
.if defined(DFLYVERSION)
OPTIONS_DEFAULT=
.endif

.include <bsd.port.options.mk>

post-patch:
# Fix P_KTHREAD r295435
.if ${OSVERSION} >= 1100097
	${REINPLACE_CMD} 's/P_KTHREAD/P_KPROC/' ${WRKSRC}/lib/utils.c
.endif
	${REINPLACE_CMD} 's/python/${PYTHON_VERSION}/' \
		${WRKSRC}/scripts/upgrade/regenerate_secret_key.sh
	${REINPLACE_CMD} -e 's|^INSTALL.*|INSTALLPATH="${PREFIX}/${SEAFILE_SERVER}/seafile"|' \
			${WRKSRC}/scripts/seaf-cli-wrapper.sh
	${REINPLACE_CMD} 's/<evhtp.h>/<evhtp\/evhtp.h>/' ${WRKSRC}/server/upload-file.c \
			${WRKSRC}/server/access-file.c ${WRKSRC}/server/http-server.c
post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SEABIN} ${STAGEDIR}${PREFIX}/${SEALIB} \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/seafile/share/doc/seafile \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/upgrade
.for SERVPROG in seaf-fsck seafserv-gc seaf-fuse seaf-migrate \
		seaf-server seaf-server-init seafile-controller
	if [ -e "${STAGEDIR}${PREFIX}/bin/${SERVPROG}" ]; then \
		${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/${SERVPROG} ${STAGEDIR}${PREFIX}/${SEABIN}; \
		${RM} ${STAGEDIR}${PREFIX}/bin/${SERVPROG}; \
	fi
.endfor
.for SERVPROG in seafile-controller seaf-server
	${LN} -s ${PREFIX}/${SEABIN}/${SERVPROG} ${STAGEDIR}${PREFIX}/bin/
.endfor

	${INSTALL_SCRIPT} ${STAGEDIR}${PREFIX}/bin/seaf-cli ${STAGEDIR}${PREFIX}/${SEABIN}/seaf-cli.py
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/seaf-cli-wrapper.sh ${STAGEDIR}${PREFIX}/bin/seaf-cli
	(cd ${STAGEDIR}${PREFIX}/lib && \
		${COPYTREE_SHARE} ${PYTHON_VERSION} ${STAGEDIR}${PREFIX}/${SEALIB})
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION} \
		${WRKSRC}/scripts/seaf-cli-wrapper.sh \
		${WRKSRC}/scripts/sqlite2mysql.[ps][yh] \
		${WRKSRC}/scripts/setup-seafile.sh \
		${STAGEDIR}${PREFIX}/bin/seafile-admin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.[ps][yh] ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/upgrade/*.[ps][yh] \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/upgrade
	${INSTALL_DATA} ${WRKSRC}/doc/seafile-tutorial.doc \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/seafile/share/doc/seafile/
	(cd ${WRKSRC}/scripts/upgrade && \
		${COPYTREE_SHARE} sql ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/upgrade)

.include <bsd.port.mk>
