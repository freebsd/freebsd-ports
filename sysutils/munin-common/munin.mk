MUNIN_VERSION=	2.0.23
MUNIN_SITES=	SF/${PORTNAME}/stable/${MUNIN_VERSION}
MUNIN_DISTINFO=	${PORTSDIR}/sysutils/munin-common/distinfo
MUNIN_PATCHES=	${PORTSDIR}/sysutils/munin-common/files/patch-Makefile \
		${PORTSDIR}/sysutils/munin-common/files/patch-Makefile.config

PORTSCOUT=	limit:^2\.0\.

DBDIR?=		/var/${PORTNAME}
DBDIRNODE?=	/var/${PORTNAME}
LOGDIR?=	/var/log/${PORTNAME}
STATEDIR?=	/var/run/${PORTNAME}
SPOOLDIR?=	/var/spool/${PORTNAME}
MUNIN_DIRS=	BINDIR=${PREFIX}/bin \
		CGIDIR=${PREFIX}/www/cgi-bin \
		CONFDIR=${ETCDIR} \
		DBDIR=${DBDIR} \
		DBDIRNODE=${DBDIRNODE} \
		DOCDIR=${DOCSDIR} \
		HTMLDIR=${WWWDIR} \
		LIBDIR=${DATADIR} \
		LOGDIR=${LOGDIR} \
		MANDIR=${MANPREFIX}/man \
		SBINDIR=${PREFIX}/sbin \
		STATEDIR=${STATEDIR} \
		SPOOLDIR=${SPOOLDIR}
MAKE_ARGS=	${MUNIN_DIRS} \
		BASH=${LOCALBASE}/bin/bash \
		PERL=${PERL} PERLLIB=${PREFIX}/${SITE_PERL_REL}
USERS=		munin
GROUPS=		munin
PLIST_SUB=	${MUNIN_DIRS} USER=${USERS} GROUP=${GROUPS}
