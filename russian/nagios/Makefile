# New ports collection makefile for:	nagios
# Date created:				04 Feb 2004
# Whom:					Roman Y. Bogdanov <sam@brj.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	1.2
CATEGORIES=	russian net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}:main \
		http://onix.opennet.ru/files/:ruspatch
MASTER_SITE_SUBDIR=nagios
DISTFILES=	nagios-1.2.tar.gz:main nagios_rus_1_2.tar.gz:ruspatch

MAINTAINER=	sam@brj.pp.ru
COMMENT=	Extremely powerful network monitoring system with Russian language

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

BROKEN=		Changes permissions of installed directory
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

CONFLICTS=	nagios-1*

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

pre-patch:
	cd ${WRKDIR} && ${PATCH} < ${WRKSRC}/../russian.cgi.patch

pre-build:
	for f in nagios.sh INSTALL DEINSTALL MESSAGE; do \
		${SED} ${SED_SCRIPT} < ${FILESDIR}/$${f}.tmpl >${WRKDIR}/$${f}; \
	done

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/nagios.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
