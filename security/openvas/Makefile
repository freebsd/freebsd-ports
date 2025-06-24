PORTNAME=	openvas
DISTVERSION=	23.20.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open vulnerability assessment scanner
WWW=		https://github.com/greenbone/openvas

LICENSE=	GPLv2+

BUILD_DEPENDS=	flex:textproc/flex
LIB_DEPENDS=	libgvm_base.so:security/gvm-libs \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libpcap.so.1:net/libpcap \
		libksba.so:security/libksba \
		libgpgme.so:security/gpgme \
		libssh.so:security/libssh \
		libgnutls.so:security/gnutls \
		libnetsnmp.so:net-mgmt/net-snmp \
		libjson-glib-1.0.so:devel/json-glib \
		libcurl.so:ftp/curl
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}impacket>=0:net/py-impacket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenbone-feed-sync>0:security/py-greenbone-feed-sync@${PY_FLAVOR} \
		redis-server:databases/redis \
		snmpget:net-mgmt/net-snmp \
		rsync:net/rsync \
		nmap:security/nmap

USES=		bison cmake gnome gssapi:mit pkgconfig python ssl
USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}-scanner
USE_GNOME=	glib20

CMAKE_ARGS+=	-DINSTALL_OLD_SYNC_SCRIPT=OFF

USERS=		gvm
GROUPS=		${USERS}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=strict-prototypes -Wno-error=unused-but-set-variable -Wno-error=invalid-utf8 -Wno-implicit-function-declaration
.endif

# The struct this error is about is only ever accessed using bcopy() and memset(),
# so the unaligned structure doesn't matter.  Disable the error, but keep it as a
# warning so we can see where it is.
CFLAGS_armv6=	-Wno-error=unaligned-access
CFLAGS_armv7=	-Wno-error=unaligned-access

post-patch:
	@${REINPLACE_CMD} -e 's|#include <bsd/unistd.h>||g' ${WRKSRC}/src/nasl_plugins.c
	@${REINPLACE_CMD} -e 's|#include <bsd/unistd.h>|#include <unistd.h>|g' ${WRKSRC}/src/pluginload.c
	@${REINPLACE_CMD} -e 's|vendor_version_get ()|vendor_version_get (void)|g' ${WRKSRC}/misc/vendorversion.c

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/ospd

.include <bsd.port.post.mk>
