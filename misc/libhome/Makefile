# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	libhome
PORTVERSION=	0.7.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pll

MAINTAINER=	kiwi@oav.net
COMMENT=	Library providing a getpwname() emulation

LIB_DEPENDS+=	ldap:${PORTSDIR}/net/openldap21-client \
		mysqlclient:${PORTSDIR}/databases/mysql323-client \
		db3.3:${PORTSDIR}/databases/db3

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-db3=${LOCALBASE}/include/db3 --without-db4 \
		--with-ldap=${LOCALBASE}/include \
		--with-mysql=${LOCALBASE}/include/mysql
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" home_finger

MAN5=		home.conf.5

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/home_finger ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/home.conf ${PREFIX}/etc/home.conf.dist

.include <bsd.port.mk>
