# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	libhome
PORTVERSION=	0.10.1
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
OPTIONS+=	PGSQL "Support for PostgreSQL (Experimental)" off

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_DB3) && defined(WITH_DB4)
.error You cannot use DB3 and DB4 in the same time.
.endif

CONFIGURE_ARGS+=	--with-proxy --with-nss

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
CONFIGURE_ARGS+=	--with-db3=${LOCALBASE}/include/db3 --with-db-libdir=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--without-db4
.else
CONFIGURE_ARGS+=	--without-db3
.endif

.if defined(WITH_DB4)
LIB_DEPENDS+=	db4:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=	--with-db4=${LOCALBASE}/include/db4 --with-db-libdir=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--without-db3
.else
CONFIGURE_ARGS+=	--without-db4
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
.else
CONFIGURE_ARGS+=	--without-pam
.endif

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=	--with-pgsql
USE_PGSQL=	YES
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

MAN5=		home.conf.5
MAN8=		home_proxy.8

.if ${OSVERSION} < 500000
PLIST_SUB=	NSS="@comment "
.else
PLIST_SUB=	NSS=""
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/home.conf ${PREFIX}/etc/home.conf.dist
	${INSTALL_SCRIPT} ${WRKSRC}/rc/freebsd/home_proxy.sh ${PREFIX}/etc/rc.d/home_proxy.sh

.include <bsd.port.post.mk>
