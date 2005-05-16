# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	libhome
PORTVERSION=	0.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pll

MAINTAINER=	kiwi@oav.net
COMMENT=	Library providing a getpwname() emulation

OPTIONS+=	LDAP "Support for LDAP queries" on
OPTIONS+=	MYSQL "Support for MySQL queries" on
OPTIONS+=	DB3 "Support for DB3" on
OPTIONS+=	DB4 "Support for DB4" off
OPTIONS+=	PAM "Support for PAM (Experimental)" off
OPTIONS+=	PROXY "Support for Proxy Driver (Experimental)" off
OPTIONS+=	PGSQL "Support for PostgreSQL (Experimental)" off

HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_DB3) && defined(WITH_DB4)
.error You cannot use DB3 and DB4 in the same time.
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if !defined(WITHOUT_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}/include/mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if !defined(WITHOUT_DB3)
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=	--with-db3=${LOCALBASE}/include/db3 --without-db4
.else
CONFIGURE_ARGS+=	--without-db3
.endif

.if defined(WITH_DB4)
LIB_DEPENDS+=	db4:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=	--with-db4=${LOCALBASE}/include/db4 --without-db3
.else
CONFIGURE_ARGS+=	--without-db4
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif

.if defined(WITH_PROXY)
CONFIGURE_ARGS+=	--with-proxy
.else
CONFIGURE_ARGS+=	--without-proxy
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql
USE_PGSQL=	YES
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

GNU_CONFIGURE=	YES
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" home_finger

MAN5=		home.conf.5

post-install:
	${INSTALL_DATA} ${WRKSRC}/home.conf ${PREFIX}/etc/home.conf.dist

.include <bsd.port.post.mk>
