# New ports collection makefile for:	nagios
# Date created:				19 May 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=nagios

MAINTAINER=	blaz@si.FreeBSD.org
COMMENT=	Extremely powerful network monitoring system

.if defined(WITH_GD1)
LIB_DEPENDS=	gd1.2:${PORTSDIR}/graphics/gd1
.else
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
.endif
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net/nagios-plugins

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes

CPPFLAGS=	${INCGD} -I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS} ${INCGD}" \
		LIBS="-L${LOCALBASE}/lib ${LIBGD}"
CONFIGURE_ARGS=	--with-command-user=nagios \
		--with-command-grp=www \
		--with-nagios-user=nagios \
		--with-nagios-grp=nagios \
		--with-template-objects \
		--with-template-extinfo \
		--with-init-dir=${PREFIX}/etc/rc.d \
		--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=/var/spool/nagios \
		--prefix=${PREFIX}

.if defined(WITH_GD1)
INCGD=		-I${LOCALBASE}/include/gd
LIBGD=		-lgd1
.else
INCGD=		-I${LOCALBASE}/include
LIBGD=		-lgd
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
CONFIGURE_ARGS+=--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-inc=${LOCALBASE}/include/mysql \
		--with-mysql-xdata
.endif

.if defined(NAGIOS_FILE_PERFDATA)
CONFIGURE_ARGS+=--with-file-perfdata
.endif

.if defined(WITH_POSTGRES)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
CONFIGURE_ARGS+=--with-pgsql-lib=${LOCALBASE}/pgsql \
		--with-pgsql-inc=${LOCALBASE}/pgsql \
		--with-pgsql-xdata
.endif

INSTALL_TARGET=	all install config install-config install-daemoninit install-commandmode

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
