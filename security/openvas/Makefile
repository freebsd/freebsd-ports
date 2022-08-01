PORTNAME=	openvas
DISTVERSION=	22.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Open vulnerability assessment scanner

LICENSE=	GPLv2+

BUILD_DEPENDS=	flex:textproc/flex
LIB_DEPENDS=	libgvm_base.so:security/gvm-libs \
		libgcrypt.so:security/libgcrypt \
		libpcap.so.1:net/libpcap \
		libksba.so:security/libksba \
		libgpgme.so:security/gpgme \
		libssh.so:security/libssh \
		libgnutls.so:security/gnutls \
		libnetsnmp.so:net-mgmt/net-snmp
RUN_DEPENDS=	redis-server:databases/redis \
		snmpget:net-mgmt/net-snmp \
		rsync:net/rsync \
		nmap:security/nmap \
		${PYTHON_PKGNAMEPREFIX}impacket>=0:net/py-impacket@${PY_FLAVOR}
USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}-scanner

USES=		bison cmake gnome pkgconfig python:3.5+
USE_GNOME=	glib20

USERS=		gvm
GROUPS=		${USERS}

post-patch:
	@${REINPLACE_CMD} -e 's|g_pattern_match_string|g_pattern_spec_match_string|g' ${WRKSRC}/misc/strutils.c
	@${REINPLACE_CMD} -e 's|-Wunused-but-set-variable|-Wunused-variable|g' ${WRKSRC}/nasl/nasl_grammar.y
	@${REINPLACE_CMD} -e 's|#include <bsd/unistd.h>||g' ${WRKSRC}/src/attack.c ${WRKSRC}/src/nasl_plugins.c
	@${REINPLACE_CMD} -e 's|#include <bsd/unistd.h>|#include <unistd.h>|g' ${WRKSRC}//src/pluginload.c

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/ospd

.include <bsd.port.mk>
