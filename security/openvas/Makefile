# $FreeBSD$

PORTNAME=	openvas
DISTVERSION=	20.8.1
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
		${PYTHON_PKGNAMEPREFIX}impacket>=0:net/py-impacket@${PY_FLAVOR}
USE_GITHUB=	yes
GH_ACCOUNT=	greenbone

USES=		bison cmake gnome pkgconfig python:3.5+
USE_GNOME=	glib20

USERS=		gvm
GROUPS=		${USERS}

WRKSRC=		${WRKDIR}/${PORTNAME}-scanner-${DISTVERSION}

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/ospd

.include <bsd.port.mk>
