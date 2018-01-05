# $FreeBSD$

PORTNAME=	seafile-client
DISTVERSIONPREFIX=	v
DISTVERSION=	${SEAFILE_CLIENT_VER}
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Open Source Cloud Storage (Client)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify \
		libccnet.so:net-mgmt/ccnet-client \
		libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid \
		libjansson.so:devel/jansson
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		bash:shells/bash

USES=		autoreconf iconv libarchive libtool localbase mysql \
		pathfix pkgconfig python:-2.7 shebangfix sqlite ssl
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	seafile

USE_GNOME=	glib20
USE_LDCONFIG=	yes

CONFLICTS=	seafile-server-[0-9]*

SHEBANG_FILES=	*.sh scripts/*.sh app/seaf-cli integration-tests/*.sh

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
CPPFLAGS+=	-I${LOCALBASE}/include/evhtp

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
# Fix P_KTHREAD r295435
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100097
	${REINPLACE_CMD} 's/P_KTHREAD/P_KPROC/' ${WRKSRC}/lib/utils.c
.endif

makesum-all:
.for PORT in net-mgmt/ccnet-client net-mgmt/seafile-client net-mgmt/seafile-gui
	${MAKE} -C "${PORTSDIR}/${PORT}" makesum
.endfor

.include "${.CURDIR}/Makefile.include"

.include <bsd.port.mk>
