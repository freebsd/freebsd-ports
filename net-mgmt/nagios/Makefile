# New ports collection makefile for:	nagios
# Date created:				19 May 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	1.2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=nagios

MAINTAINER=	blaz@si.FreeBSD.org
COMMENT=	Extremely powerful network monitoring system

.if defined(WITH_GD1)
LIB_DEPENDS=	gd1.2:${PORTSDIR}/graphics/gd1
.else
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
.endif
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

CPPFLAGS=	${INCGD} -I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS} ${INCGD}" \
		LIBS="-L${LOCALBASE}/lib ${LIBGD}"
CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-grp=www \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-grp=${NAGIOSGROUP} \
		--with-template-objects \
		--with-template-extinfo \
		--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--prefix=${PREFIX}

.if defined(WITH_GD1)
INCGD=		-I${LOCALBASE}/include/gd
LIBGD=		-lgd1
.else
INCGD=		-I${LOCALBASE}/include
LIBGD=		-lgd
.endif

.if defined(WITH_MYSQL)
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

SED_SCRIPT=	-e 's,%%NAGIOSUSER%%,${NAGIOSUSER},g' \
		-e 's,%%NAGIOSGROUP%%,${NAGIOSGROUP},g' \
		-e 's,%%NAGIOSDIR%%,${NAGIOSDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

INSTALL_TARGET=	all install config install-config install-commandmode

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "nagios has the following tunables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_MYSQL=yes		Compile with MySQL suport"
	@${ECHO_MSG} "  WITH_POSTGRES=yes		Compile with PostgreSQL suport"
	@${ECHO_MSG} "  WITH_GD1=yes			Compile with GD1 instead of GD2"
	@${ECHO_MSG} "  NAGIOS_FILE_PERFDATA=yes	Save performance data to files"
	@${ECHO_MSG} ""

pre-build:
	for file in nagios.sh INSTALL DEINSTALL MESSAGE; do \
		${SED} ${SED_SCRIPT} < ${FILESDIR}/$${file}.tmpl >${WRKDIR}/$${file}; \
	done

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/nagios.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
