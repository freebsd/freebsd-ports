PORTNAME=	seafile-client
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.6
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Open Source Cloud Storage (Client)
WWW=		https://github.com/haiwen/seafile

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libcurl.so:ftp/curl \
		libinotify.so:devel/libinotify \
		libevent.so:devel/libevent \
		libuuid.so:misc/libuuid \
		libjansson.so:devel/jansson \
		libwebsockets.so:net/libwebsockets
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		bash:shells/bash

USES=		autoreconf gnome iconv libarchive libtool localbase \
		pathfix pkgconfig python shebangfix sqlite ssl vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	seafile

USE_GNOME=	glib20
USE_LDCONFIG=	yes

CONFLICTS=	seafile-server

SHEBANG_FILES=	*.sh scripts/*.sh app/seaf-cli integration-tests/*.sh

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
CPPFLAGS+=	-I${LOCALBASE}/include/evhtp

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

post-patch:
# Fix P_KTHREAD r295435
	${REINPLACE_CMD} 's/P_KTHREAD/P_KPROC/' ${WRKSRC}/lib/utils.c

.include <bsd.port.mk>
