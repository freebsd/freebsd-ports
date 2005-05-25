# New ports collection makefile for:	nagios
# Date created:				19 May 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	1.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=nagios

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Extremely powerful network monitoring system

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	yes
USE_PERL5_BUILD=yes

PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
PKGMESSAGE=	${WRKDIR}/MESSAGE

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

OPTIONS=	MYSQL "MySQL suport" off \
		PGSQL "PostgreSQL suport" off \
		FILE_PERFDATA "Save performance data to files" off

CONFLICTS=	nagios-2*
LATEST_LINK=	nagios12

.include <bsd.port.pre.mk>

CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgd"
CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-grp=www \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-grp=${NAGIOSGROUP} \
		--with-template-objects \
		--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--prefix=${PREFIX}

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-lib=${LOCALBASE}/lib/mysql \
		--with-mysql-inc=${LOCALBASE}/include/mysql \
		--with-mysql-xdata
.else
CONFIGURE_ARGS+=	--with-template-extinfo
.endif

.if defined(WITH_FILE_PERFDATA)
CONFIGURE_ARGS+=--with-file-perfdata
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql-lib=${LOCALBASE}/pgsql \
		--with-pgsql-inc=${LOCALBASE}/pgsql \
		--with-pgsql-xdata
.endif

SED_SCRIPT=	-e 's,%%NAGIOSUSER%%,${NAGIOSUSER},g' \
		-e 's,%%NAGIOSGROUP%%,${NAGIOSGROUP},g' \
		-e 's,%%NAGIOSDIR%%,${NAGIOSDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

INSTALL_TARGET=	all install config install-config install-commandmode

pre-build:
	for file in nagios.sh INSTALL DEINSTALL MESSAGE; do \
		${SED} ${SED_SCRIPT} < ${FILESDIR}/$${file}.tmpl >${WRKDIR}/$${file}; \
	done

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/nagios.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
