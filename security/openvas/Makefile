PORTNAME=	openvas
DISTVERSION=	22.7.0
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
		libjson-glib-1.0.so:devel/json-glib
RUN_DEPENDS=	redis-server:databases/redis \
		snmpget:net-mgmt/net-snmp \
		rsync:net/rsync \
		nmap:security/nmap \
		${PYTHON_PKGNAMEPREFIX}impacket>=0:net/py-impacket@${PY_FLAVOR}

USES=		bison cmake gnome pkgconfig python:3.5+ ssl
USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}-scanner
USE_GNOME=	glib20

USERS=		gvm
GROUPS=		${USERS}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=strict-prototypes -Wno-error=unused-but-set-variable -Wno-error=invalid-utf8
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|#include <bsd/unistd.h>||g' ${WRKSRC}/src/attack.c ${WRKSRC}/src/nasl_plugins.c
	@${REINPLACE_CMD} -e 's|#include <bsd/unistd.h>|#include <unistd.h>|g' ${WRKSRC}//src/pluginload.c
	@${REINPLACE_CMD} -e 's|vendor_version_get ()|vendor_version_get (void)|g' ${WRKSRC}/misc/vendorversion.c

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/ospd

.include <bsd.port.post.mk>
