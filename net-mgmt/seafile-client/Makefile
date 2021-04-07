PORTNAME=	seafile-client
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.9
CATEGORIES=	net-mgmt

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Open Source Cloud Storage (Client)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify \
		libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid \
		libjansson.so:devel/jansson
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		bash:shells/bash

USES=		autoreconf gnome iconv libarchive libtool localbase \
		pathfix pkgconfig python:3.6+ shebangfix sqlite ssl
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

post-patch:
# Fix P_KTHREAD r295435
	${REINPLACE_CMD} 's/P_KTHREAD/P_KPROC/' ${WRKSRC}/lib/utils.c

.include <bsd.port.mk>
