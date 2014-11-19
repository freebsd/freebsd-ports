# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	slurm
PORTVERSION=	2.6.4
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/development/
PKGNAMESUFFIX=	-hpc

MAINTAINER=	jwbacon@tds.net
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	GPLv1

LIB_DEPENDS=	libsysinfo.so:${PORTSDIR}/devel/libsysinfo \
		libhwloc.so:${PORTSDIR}/devel/hwloc \
		libmunge.so:${PORTSDIR}/security/munge \
		librrd.so:${PORTSDIR}/databases/rrdtool \
		libhdf5.so:${PORTSDIR}/science/hdf5

GNU_CONFIGURE=	yes
USES=		gmake libtool perl5 python tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS MYSQL PGSQL GTK2

USERS=		slurm
GROUPS=		${USERS}

USE_RC_SUBR=	slurmctld slurmd
SUB_FILES+=	slurm.conf

# This is a new and complex port.  Allow debugging.
STRIP_CMD=	# NONE
CFLAGS+=	-I${LOCALBASE}/include -g -O1
LDFLAGS+=	-L${LOCALBASE}/lib -lsysinfo -lkvm

post-install:
	${INSTALL_DATA} ${WRKDIR}/slurm.conf ${STAGEDIR}${PREFIX}/etc/slurm.conf.sample

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes	# Job accounting
PLIST_FILES+=	lib/slurm/accounting_storage_mysql.a \
		lib/slurm/accounting_storage_mysql.la \
		lib/slurm/accounting_storage_mysql.so \
		lib/slurm/jobcomp_mysql.a \
		lib/slurm/jobcomp_mysql.la \
		lib/slurm/jobcomp_mysql.so
.else
# Can't disable configure test, so make it fail
CONFIGURE_ARGS+=--with-mysql_config=/nomysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes	# Job accounting
PLIST_FILES+=	lib/slurm/accounting_storage_pgsql.a \
		lib/slurm/accounting_storage_pgsql.la \
		lib/slurm/accounting_storage_pgsql.so \
		lib/slurm/jobcomp_pgsql.a \
		lib/slurm/jobcomp_pgsql.la \
		lib/slurm/jobcomp_pgsql.so
.else
# Can't disable configure test, so make it fail
CONFIGURE_ARGS+=--with-pg_config=/nopostgres
.endif

.if ${PORT_OPTIONS:MGTK2}
# Note: Configure could not find pcre when building with no ports
# preinstalled on 9.1-RELEASE.  Worked fine on second try.
USE_GNOME=	glib20 gtk20	# sview
PLIST_FILES+=	bin/sview
.endif

post-patch:
# Can't disable configure test, so make it fail
.if ! ${PORT_OPTIONS:MGTK2}
	${REINPLACE_CMD} -e 's|min_gtk_version=2.7.1|min_gtk_version=200.7.1|' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
		${WRKSRC}/doc/html/shtml2html.py \
		${WRKSRC}/doc/man/man2html.py

.include <bsd.port.mk>
