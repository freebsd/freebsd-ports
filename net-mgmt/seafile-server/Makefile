# $FreeBSD$

PORTNAME=	seafile-server
PORTVERSION=	6.0.7
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
		libccnet.so:net-mgmt/ccnet-server \
		libevent.so:devel/libevent2 \
		libuuid.so:misc/e2fsprogs-libuuid \
		libjansson.so:devel/jansson
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3 \
		bash:shells/bash

CONFLICTS=	seafile-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

USES=		autoreconf gettext iconv libarchive libtool mysql pathfix \
		pgsql pkgconfig python:-2.7 shebangfix sqlite ssl
USE_GNOME=	glib20
SHEBANG_FILES=	scripts/*.sh scripts/upgrade/*.sh *.sh scripts/build/*.py \
		scripts/*.py scripts/upgrade/*.py tools/seafile-admin
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/evhtp
LDFLAGS+=	-L${LOCALBASE}/lib

HAIWENDIR=	www/haiwen
SEAFILE_SERVER=	${HAIWENDIR}/seafile-server
SEABIN=		${SEAFILE_SERVER}/seafile/bin
SEALIB=		${SEAFILE_SERVER}/seafile/lib

USERS=		seafile
GROUPS=		${USERS}

USE_RC_SUBR=	seafile
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

OPTIONS_DEFINE=		FUSE
OPTIONS_SUB=		yes

FUSE_DESC=		Use file system in userspace

FUSE_CONFIGURE_ENABLE=	fuse
FUSE_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs

OPTIONS_DEFAULT=	FUSE
OPTIONS_EXCLUDE_DragonFly=	FUSE

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

	(cd ${STAGEDIR}${PREFIX}/lib && \
		${COPYTREE_SHARE} ${PYTHON_VERSION} ${STAGEDIR}${PREFIX}/${SEALIB})
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION} \
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
