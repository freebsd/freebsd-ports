PORTNAME=	slurm
DISTVERSION=	23.11.7
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	https://download.schedmd.com/slurm/
PKGNAMESUFFIX=	-wlm

MAINTAINER=	rikka.goering@outlook.de
COMMENT=	Simple Linux Utility for Resource Management
WWW=		https://slurm.schedmd.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=		armv6 armv7 i386 mips powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	32-bit support is deprecated

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libsysinfo.so:devel/libsysinfo \
		libmunge.so:security/munge \
		liblz4.so:archivers/liblz4 \
		libze_loader.so:devel/level-zero \
		libhttp_parser.so:www/http-parser \
		libunwind.so:devel/libunwind \
		librdkafka.so:net/librdkafka \
		libyaml.so:textproc/libyaml \
		libdbus-1.so:devel/dbus \
		libcheck.so:devel/check \
		libtbb.so:devel/onetbb \
		libjwt.so:www/libjwt

USES=		compiler:c11 cpe gmake gnome libtool localbase lua mysql:client	\
		perl5 pkgconfig python:build readline shebangfix ssl tar:bz2
USE_PERL5=	build
CPE_VENDOR=	schedmd
USE_LDCONFIG=	yes
USE_RC_SUBR=	slurmctld slurmd

USERS=		slurm
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
PLIST_SUB=	PORTVERSION="${DISTVERSION}" VER="${DISTVERSION:R}"	\
		USERS=${USERS} GROUPS=${GROUPS}
SHEBANG_FILES=	doc/html/shtml2html.py doc/man/man2html.py
PORTDOCS=	*

OPTIONS_DEFINE=		CURL DOCS GUI HDF5 HWLOC IPMI RRD
OPTIONS_DEFAULT=	HDF5 HWLOC
OPTIONS_SUB=		yes

CURL_DESC=	Require cURL for elasticsearch plugins
GUI_DESC=	Build sview GUI config tool
HDF5_DESC=	Job profiling using HDF5
HWLOC_DESC=	Portable hardware locality
IPMI_DESC=	IPMI energy consumption accounting
RRD_DESC=	RRD external sensor data collection

DOCS_BUILD_DEPENDS=	man2html:textproc/man2html

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

GUI_USE=		GNOME=cairo,gdkpixbuf,glib20,gtk20,pango
GUI_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
GUI_USES=		gettext
GUI_CONFIGURE_ENABLE=	glibtest gtktest x11

HDF5_LIB_DEPENDS=	libhdf5_cpp.so:science/hdf5 \
			libsz.so:science/libaec
HDF5_CONFIGURE_WITH=	hdf5
HDF5_CONFIGURE_ENV=	H5CC=${LOCALBASE}/bin/h5cc

HWLOC_LIB_DEPENDS=	libhwloc.so.15:devel/hwloc2
HWLOC_CONFIGURE_WITH=	hwloc

IPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
IPMI_CONFIGURE_WITH=	freeipmi

RRD_LIB_DEPENDS=	librrd.so:databases/rrdtool
RRD_CONFIGURE_WITH=	rrdtool

# FreeBSD Infiniband support is still experimental
# slurmrestd does not build on FreeBSD
CONFIGURE_ARGS=	--disable-slurmrestd --with-mysql_config=${LOCALBASE}/bin \
		--docdir=${DOCSDIR} --htmldir=${DOCSDIR}

CFLAGS+=	-I${WRKSRC}/slurm -I${LOCALBASE}/include	\
		-I${LOCALBASE}/include/level_zero		\
		-I${LOCALBASE}/include/librdkafka		\
		-fcommon -D__BSD_VISIBLE=1
LDFLAGS+=	-L${LOCALBASE}/lib -lsysinfo -lprocstat -fcommon

PROC2FIX=	common/callerid.c common/fd.c common/fetch_config.c	\
		interfaces/proctrack.c	\
		plugins/acct_gather_energy/rapl/acct_gather_energy_rapl.c	\
		plugins/acct_gather_filesystem/lustre/acct_gather_filesystem_lustre.c	\
		plugins/burst_buffer/common/burst_buffer_common.c	\
		plugins/cgroup/v1/xcgroup.c plugins/cgroup/v2/cgroup_v2.c	\
		plugins/gpu/nvml/gpu_nvml.c	\
		plugins/job_container/tmpfs/job_container_tmpfs.c	\
		plugins/jobacct_gather/cgroup/jobacct_gather_cgroup.c	\
		plugins/jobacct_gather/common/common_jag.c	\
		plugins/jobacct_gather/linux/jobacct_gather_linux.c	\
		plugins/node_features/knl_generic/node_features_knl_generic.c	\
		plugins/proctrack/cgroup/proctrack_cgroup.c	\
		plugins/proctrack/cray_aries/proctrack_cray_aries.c	\
		plugins/proctrack/linuxproc/kill_tree.c	\
		plugins/proctrack/pgid/proctrack_pgid.c	\
		plugins/switch/cray_aries/scaling.c	\
		plugins/task/affinity/affinity.c slurmd/common/set_oomadj.c	\
		slurmd/common/xcpuinfo.c slurmd/slurmstepd/pdebug.c	\
		slurmctld/controller.c	\
		slurmd/slurmd/slurmd.c	\
		slurmd/slurmstepd/req.c

LLD2FIX=	api plugins/openapi sacctmgr sackd scontrol scrontab scrun	\
		slurmctld slurmd/slurmd squeue

.include <bsd.port.options.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/src/plugins/task/pgid
# Use an existing plugin's Makefile.in as a template
	@${CP}	${WRKSRC}/src/plugins/task/cray_aries/Makefile.in \
		${WRKSRC}/src/plugins/task/pgid/Makefile.in

# Hack around nonfunctional --disable-gtktest flag
pre-configure-GUI-off:
	${REINPLACE_CMD} -e 's|min_gtk_version=.*|min_gtk_version=2000.0.0|' \
		${WRKSRC}/configure

# SLURM's configure enables interactive jobs if pty.h exists.  Replacing
# #include <pty.h> with appropriate headers will therefore not work, so instead
# add a pty.h for the build.
pre-configure:
	${CP} ${FILESDIR}/pty.h ${WRKSRC}/slurm
	${REINPLACE_CMD} -e 's|sched_setaffinity|cpuset_setaffinity|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/configure
.for src in ${PROC2FIX}
	${REINPLACE_CMD} -e 's|"/proc|"/compat/linux/proc|g' \
		-e 's|(/proc)|(/compat/linux/proc)|g' \
		${WRKSRC}/src/${src}
.endfor
	@if ${WHICH} sbatch > /dev/null; then \
		${ECHO_CMD} "********************************************"; \
		${ECHO_CMD} "Build may fail while slurm-wlm is installed."; \
		${ECHO_CMD} "Deinstall slurm-wlm and run make again."; \
		${ECHO_CMD} "********************************************"; \
		false; \
	fi
.if ${ARCH} == powerpc64le
	${FIND} ${LLD2FIX:C|^|${WRKSRC}/src/|} -name Makefile.in | ${XARGS}	\
		${REINPLACE_CMD} -e 's|-r -o|-r -m elf64lppc -o|'
.elif ${ARCH} == powerpc64
	${FIND} ${LLD2FIX:C|^|${WRKSRC}/src/|} -name Makefile.in | ${XARGS}	\
		${REINPLACE_CMD} -e 's|-r -o|-r -m elf64ppc -o|'
.elif ${ARCH} == aarch64
	${FIND} ${LLD2FIX:C|^|${WRKSRC}/src/|} -name Makefile.in | ${XARGS}	\
		${REINPLACE_CMD} -e 's|-r -o|-r -m aarch64elf -o|'
.else
	${FIND} ${LLD2FIX:C|^|${WRKSRC}/src/|} -name Makefile.in | ${XARGS}	\
		${REINPLACE_CMD} -e 's|-r -o|-r -m elf_${ARCH} -o|'
.endif
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS}	\
		${REINPLACE_CMD} -e 's|htmldir = \$${datadir.*$$|htmldir = @htmldir@|'

post-install:
	@${MKDIR} ${STAGEDIR}/var/spool/slurmctld
	@${CHMOD} 700 ${STAGEDIR}/var/spool/slurmctld
	${INSTALL_DATA} ${WRKSRC}/etc/slurm.conf.example \
		${STAGEDIR}${PREFIX}/etc/slurm.conf.sample

.include <bsd.port.mk>
