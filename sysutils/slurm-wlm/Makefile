# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	slurm
DISTVERSION=	17.02.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/development/
PKGNAMESUFFIX=	-wlm

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libsysinfo.so:devel/libsysinfo \
		libmunge.so:security/munge \
		liblz4.so:archivers/liblz4

USERS=		slurm
GROUPS=		${USERS}

USES=		gmake libtool pkgconfig python:build readline:port shebangfix \
		ssl tar:bz2
USE_LDCONFIG=	yes
USE_PERL5=	configure
USE_RC_SUBR=	slurmctld slurmd

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
SHEBANG_FILES=	doc/html/shtml2html.py doc/man/man2html.py

OPTIONS_DEFINE=	CURL DOCS GTK2 HDF5 HWLOC IPMI MYSQL RRD LINUX
OPTIONS_DEFAULT=HDF5 HWLOC
OPTIONS_SUB=	yes

CURL_DESC=	Require cURL for elasticsearch plugins
GTK2_DESC=	Build sview GUI config tool
HDF5_DESC=	Job profiling using HDF5
HWLOC_DESC=	Portable hardware locality
IPMI_DESC=	IPMI energy consumption accounting
RRD_DESC=	RRD external sensor data collection
LINUX_DESC=	Support jobacct_gather/linux (requires linprocfs)

DOCS_BUILD_DEPENDS=	man2html:textproc/man2html

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

GTK2_USE=		GNOME=cairo,gdkpixbuf2,glib20,gtk20
GTK2_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GTK2_USES=		gettext
# Neither of these work.  See post-patch below.
#GTK2_CONFIGURE_ENV_OFF=	ac_gtk_test=no
#GTK2_CONFIGURE_OFF=	--disable-gtktest

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libsz.so:science/szip
HDF5_CONFIGURE_WITH=	hdf5

HWLOC_LIB_DEPENDS=	libhwloc.so:devel/hwloc
HWLOC_CONFIGURE_WITH=	hwloc

IPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
IPMI_CONFIGURE_WITH=	freeipmi

MYSQL_USES=		mysql
MYSQL_CONFIGURE_with=	mysql
MYSQL_CONFIGURE_OFF=	--with-mysql_config=/nonexistent

RRD_LIB_DEPENDS=	librrd.so:databases/rrdtool
RRD_CONFIGURE_WITH=	rrdtool

LINUX_USES=		linux

CFLAGS+=	-I${WRKSRC}/slurm -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lsysinfo -lkvm

# SLURM's configure enables interactive jobs if pty.h exists.  Replacing
# #include <pty.h> with appropriate headers will therefore not work, so instead
# add a pty.h for the build.
post-patch:
	@${CP} ${FILESDIR}/pty.h ${WRKSRC}/slurm
	@${REINPLACE_CMD} -e 's|sched_setaffinity|cpuset_setaffinity|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/bin/mail|/usr/bin/mail|g' \
		${WRKSRC}/src/common/read_config.h \
		${WRKSRC}/contribs/seff/smail \
		${WRKSRC}/doc/html/configurator.easy.html.in \
		${WRKSRC}/doc/html/configurator.html.in \
		${WRKSRC}/contribs/cray/slurm.conf.template \
		${WRKSRC}/doc/man/man1/strigger.1 \
		${WRKSRC}/doc/man/man5/slurm.conf.5
	@${REINPLACE_CMD} \
		-e 's|=linux|=FreeBSD|g' \
		-e 's|run/slurmctld.pid|run/slurm/slurmctld.pid|' \
		-e 's|run/slurmd.pid|run/slurm/slurd.pid|' \
		-e 's|SlurmdSpoolDir=.*|SlurmdSpoolDir=/var/spool/slurmd|' \
		-e 's|StateSaveLocation=.*|StateSaveLocation=/var/run/slurm|' \
		${WRKSRC}/etc/slurm.conf.example

post-patch-LINUX-on:
	@${REINPLACE_CMD} -e 's|"/proc|"/compat/linux/proc|g' \
		${WRKSRC}/src/slurmd/slurmstepd/req.c \
		${WRKSRC}/src/slurmd/slurmstepd/pdebug.c \
		${WRKSRC}/src/slurmd/slurmd/get_mach_stat.c \
		${WRKSRC}/src/slurmd/slurmd/read_proc.c \
		${WRKSRC}/src/slurmd/common/xcpuinfo.c \
		${WRKSRC}/src/slurmd/common/xcgroup.c \
		${WRKSRC}/src/slurmd/common/set_oomadj.c \
		${WRKSRC}/src/slurmd/common/proctrack.c \
		${WRKSRC}/src/common/callerid.c \
		${WRKSRC}/src/plugins/task/affinity/affinity.c \
		${WRKSRC}/src/plugins/acct_gather_energy/rapl/acct_gather_energy_rapl.c \
		${WRKSRC}/src/plugins/jobacct_gather/cgroup/jobacct_gather_cgroup.c \
		${WRKSRC}/src/plugins/jobacct_gather/common/common_jag.c \
		${WRKSRC}/src/plugins/jobacct_gather/linux/jobacct_gather_linux.c \
		${WRKSRC}/src/plugins/switch/cray/scaling.c \
		${WRKSRC}/src/plugins/proctrack/cray/proctrack_cray.c \
		${WRKSRC}/src/plugins/proctrack/cgroup/proctrack_cgroup.c \
		${WRKSRC}/src/plugins/proctrack/pgid/proctrack_pgid.c \
		${WRKSRC}/src/plugins/proctrack/linuxproc/kill_tree.c \
		${WRKSRC}/src/plugins/proctrack/lua/proctrack_lua.c \
		${WRKSRC}/src/plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c \
		${WRKSRC}/contribs/cray/pam_job.c \
		${WRKSRC}/contribs/lua/proctrack.lua

# Hack around nonfunctional --disable-gtktest flag
post-patch-GTK2-off:
	@${REINPLACE_CMD} -e 's|min_gtk_version=.*|min_gtk_version=2000.0.0|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/slurm.conf.example \
		${STAGEDIR}${PREFIX}/etc/slurm.conf.sample

.include <bsd.port.mk>
