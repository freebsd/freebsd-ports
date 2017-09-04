# $FreeBSD$

PORTNAME=	seafile-server
DISTVERSIONPREFIX=	v
DISTVERSION=	${SEAFILE_VER}
DISTVERSIONSUFFIX=	-server
CATEGORIES=	net-mgmt

MAINTAINER=	ultima@FreeBSD.org
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
		libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid \
		libjansson.so:devel/jansson
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3 \
		bash:shells/bash

CONFLICTS=	seafile-[0-9]*

USES=		autoreconf iconv libarchive libtool localbase mysql \
		pathfix pgsql pkgconfig python:-2.7 shebangfix sqlite ssl
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_RC_SUBR=	seafile

SHEBANG_FILES=	scripts/*.sh scripts/upgrade/*.sh *.sh scripts/build/*.py \
		scripts/*.py scripts/upgrade/*.py tools/seafile-admin
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"

PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include/evhtp

SUB_FILES=	pkg-message

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		FUSE NLS
OPTIONS_DEFAULT=	FUSE
OPTIONS_EXCLUDE_DragonFly=	FUSE
OPTIONS_SUB=		yes

FUSE_DESC=		Use file system in userspace

FUSE_CONFIGURE_ENABLE=	fuse
FUSE_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs

NLS_USES=		gettext

.include <bsd.port.options.mk>

post-patch:
# Fix P_KTHREAD r295435
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100097
	${REINPLACE_CMD} 's/P_KTHREAD/P_KPROC/' ${WRKSRC}/lib/utils.c
.endif
	${REINPLACE_CMD} 's/python/${PYTHON_VERSION}/' \
		${WRKSRC}/scripts/upgrade/regenerate_secret_key.sh
	${REINPLACE_CMD} -e 's|^INSTALL.*|INSTALLPATH="${PREFIX}/${SEAFILE_SERVER}/seafile"|' \
			${WRKSRC}/scripts/seaf-cli-wrapper.sh
	${REINPLACE_CMD} 's/<evhtp.h>/<evhtp\/evhtp.h>/' ${WRKSRC}/server/upload-file.c \
			${WRKSRC}/server/access-file.c ${WRKSRC}/server/http-server.c
	${REINPLACE_CMD} -E 's/stat.+\$$/stat -f %Su $$/' ${WRKSRC}/scripts/seafile.sh
	${REINPLACE_CMD} 's/%%SEAFILE_USER%%/${USERS:[1]}/ ; s/%%SEAFILE_GROUP%%/${GROUPS:[1]}/' \
			${WRKSRC}/scripts/setup-seafile.sh ${WRKSRC}/scripts/setup-seafile-mysql.py
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
	${LN} -s "../${SEABIN}/${SERVPROG}" ${STAGEDIR}${PREFIX}/bin/${SERVPROG}
.endfor

	(cd ${STAGEDIR}${PREFIX}/lib && \
		${COPYTREE_SHARE} ${PYTHON_VERSION} ${STAGEDIR}${PREFIX}/${SEALIB})
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION} \
		${STAGEDIR}${PREFIX}/bin/seafile-admin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.[ps][yh] ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/upgrade/*.[ps][yh] \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/upgrade
	${INSTALL_DATA} ${WRKSRC}/doc/seafile-tutorial.doc \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/seafile/share/doc/seafile/
	(cd ${WRKSRC}/scripts/upgrade && \
		${COPYTREE_SHARE} sql ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/upgrade)

makesum-all:
.for PORT in net-mgmt/ccnet-server net-mgmt/seafile-server www/py-seafdav www/py-seafobj www/seahub
	${MAKE} -C "${PORTSDIR}/${PORT}" makesum
.endfor

.include "${.CURDIR}/Makefile.include"

.include <bsd.port.mk>
