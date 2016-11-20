# Created by: dpejesh@yahoo.com
# $FreeBSD$

PORTNAME=	corosync
PORTVERSION=	2.3.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://build.clusterlabs.org/corosync/releases/

MAINTAINER=	dpejesh@yahoo.com
COMMENT=	Corosync Cluster Engine

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libnss3.so:security/nss \
		libqb.so:devel/libqb

USES=		gmake libtool pathfix pkgconfig
USE_GCC=	yes	# segfaults when built with Clang
USE_LDCONFIG=	yes
USE_RC_SUBR=	${PORTNAME} ${PORTNAME}-notifyd
GNU_CONFIGURE=	yes
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
