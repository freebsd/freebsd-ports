# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	openvas-libraries
PORTVERSION=	8.0.7
CATEGORIES=	security
MASTER_SITES=	http://wald.intevation.org/frs/download.php/2291/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenVAS libraries

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.GPLv2

LIB_DEPENDS=	libhiredis.so:${PORTSDIR}/databases/hiredis \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp \
		libgnutls.so:${PORTSDIR}/security/gnutls \
		libgpgme.so:${PORTSDIR}/security/gpgme \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libksba.so:${PORTSDIR}/security/libksba \
		libssh.so:${PORTSDIR}/security/libssh

USES=		bison cmake:outsource gnome pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20

OPTIONS_DEFINE=	LDAP RADIUS
OPTIONS_DEFAULT=LDAP

LDAP_CMAKE_OFF=	-DBUILD_WITHOUT_LDAP=1
LDAP_USE=	OPENLDAP=yes

RADIUS_CMAKE_ON=-DBUILD_WITH_RADIUS=1
RADIUS_LIB_DEPENDS=	libfreeradius-client.so:${PORTSDIR}/net/freeradius-client

.include <bsd.port.mk>
