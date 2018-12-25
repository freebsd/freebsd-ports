# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME?=	openvas8-libraries
PORTVERSION?=	8.0.9
CATEGORIES=	security
MASTER_SITES?=	http://wald.intevation.org/frs/download.php/2433/
DISTNAME?=	${PORTNAME:S/${OPENVAS_VER}//}-${PORTVERSION}
DIST_SUBDIR=	openvas${OPENVAS_VER}

MAINTAINER=	acm@FreeBSD.org
COMMENT?=	OpenVAS 8 libraries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv2

LIB_DEPENDS=	libhiredis.so:databases/hiredis \
		libuuid.so:misc/e2fsprogs-libuuid \
		libnetsnmp.so:net-mgmt/net-snmp \
		libgnutls.so:security/gnutls \
		libgpgme.so:security/gpgme \
		libgcrypt.so:security/libgcrypt \
		libksba.so:security/libksba \
		libssh.so:security/libssh

CONFLICTS?=	${PORTNAME:S/${OPENVAS_VER}/9/}-*

USES=		bison cmake gnome pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20

OPENVAS_VER?=	8

OPTIONS_DEFINE=	LDAP RADIUS
OPTIONS_DEFAULT=LDAP

LDAP_CMAKE_OFF=	-DBUILD_WITHOUT_LDAP=1
LDAP_USE=	OPENLDAP=yes

RADIUS_CMAKE_ON=-DBUILD_WITH_RADIUS=1
RADIUS_LIB_DEPENDS=	libfreeradius-client.so:net/freeradius-client

.include <bsd.port.mk>
