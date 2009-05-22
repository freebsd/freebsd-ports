# New ports collection makefile for:	libhome
# Date created:				Fri Aug 14 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	libhome
PORTVERSION=	0.10.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.oav.net/pll/ SF/pll

MAINTAINER=	kiwi@oav.net
COMMENT=	Library providing a getpwname() emulation

OPTIONS+=	LDAP "Support for LDAP queries" on
OPTIONS+=	MYSQL "Support for MySQL queries" on
OPTIONS+=	BDB "Support for Berkeley DB" on
OPTIONS+=	PAM "Support for PAM (Experimental)" off
OPTIONS+=	PGSQL "Support for PostgreSQL (Experimental)" off

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(LIBHOME_WITH_BDB_VER)
WITH_BDB_VER=	${LIBHOME_WITH_BDB_VER}
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

.if defined(WITH_DB3) || defined(WITH_DB4)
WITH_BDB=		yes
OBSOLETE_BDB_VAR=	WITH_DB3 WITH_DB4
IGNORE=	Use 'make config' to select Berkeley DB.
.endif

.if defined(WITH_BDB)
USE_BDB=		yes
INVALID_BDB_VER=	2
. if defined(WITH_BDB_VER) && ${WITH_BDB_VER} == 3
CONFIGURE_ARGS+=	--with-db3=${BDB_INCLUDE_DIR} --without-db4
. else
CONFIGURE_ARGS+=	--without-db3 --with-db4=${BDB_INCLUDE_DIR}
. endif
CONFIGURE_ARGS+=	--with-db-libdir=${BDB_LIB_DIR}
.else
CONFIGURE_ARGS+=	--without-db3 --without-db4
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

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig ${WRKSRC}/configure
.if defined(WITH_BDB)
	@${REINPLACE_CMD} -e 's;db-4.3 db-4.2;${BDB_LIB_NAME};g' \
		${WRKSRC}/configure
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/home.conf ${PREFIX}/etc/home.conf.dist
	${INSTALL_SCRIPT} ${WRKSRC}/rc/freebsd/home_proxy.sh ${PREFIX}/etc/rc.d/home_proxy.sh

.include <bsd.port.post.mk>
