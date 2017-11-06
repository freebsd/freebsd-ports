# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	corosync
PORTVERSION=	2.4.2
CATEGORIES=	net
MASTER_SITES=	http://build.clusterlabs.org/corosync/releases/

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Corosync Cluster Engine

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libnss3.so:security/nss \
		libqb.so:devel/libqb

USES=		gmake groff libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME} ${PORTNAME}-notifyd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-secure-build
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DBUS SNMP
OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS+=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_ENABLE=	dbus

SNMP_LIB_DEPENDS+=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_ENABLE=	snmp

post-install:
	${RM} ${STAGEDIR}${PREFIX}/etc/init.d/corosync
	${RM} ${STAGEDIR}${PREFIX}/etc/init.d/corosync-notifyd
	${RMDIR} ${STAGEDIR}${PREFIX}/etc/init.d

.include <bsd.port.mk>
