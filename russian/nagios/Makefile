# New ports collection makefile for:	nagios
# Date created:				04 Feb 2004
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	1.1
CATEGORIES=	russian net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}:main \
		http://onix.opennet.ru/files/:ruspatch
MASTER_SITE_SUBDIR=nagios
DISTFILES=	nagios-1.1.tar.gz:main nagios_rus_1_1.tar.gz:ruspatch

MAINTAINER=	sam@brj.pp.ru
COMMENT=	Extremely powerful network monitoring system with Russian language

LIB_DEPENDS=    gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

CONFLICTS=	nagios-1*

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes

CPPFLAGS=	${INCGD} -I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS} ${INCGD}" \
		LIBS="-L${LOCALBASE}/lib ${LIBGD}"
CONFIGURE_ARGS+=	\
		--with-command-user=nagios \
		--with-command-grp=www \
		--with-nagios-user=nagios \
		--with-nagios-grp=nagios \
		--with-template-objects \
		--with-template-extinfo \
		--with-init-dir=${PREFIX}/etc/rc.d \
		--with-gd-lib=${LOCALBASE}/lib \
		--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=/var/spool/nagios \

.if defined(WITH_MYSQL)||defined(WITH_NAGMIN)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-lib=${LOCALBASE}/lib/mysql \
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

pre-patch:
	${CP} -R ${WRKSRC}/../nagios_rus_1_1/cgi/* ${WRKSRC}/cgi/
	${CP} -R ${WRKSRC}/../nagios_rus_1_1/html/* ${WRKSRC}/html/
	${CP} -R ${WRKSRC}/../nagios_rus_1_1/html/images/* ${WRKSRC}/html/images/

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
