PORTNAME=	slurm
DISTVERSION=	25.11.0
PORTREVISION=	1
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

LIB_DEPENDS=	libhttp_parser.so:www/http-parser \
		libjson-c.so:devel/json-c \
		libjwt.so:www/libjwt \
		liblz4.so:archivers/liblz4 \
		libmunge.so:security/munge \
		librdkafka.so:net/librdkafka \
		libsysinfo.so:devel/libsysinfo \
		libunwind.so:devel/libunwind \
		libyaml.so:textproc/libyaml

USES=		compiler:c11 cpe gmake libtool localbase lua mysql:client perl5 \
		pkgconfig python:build readline shebangfix ssl tar:bz2
CPE_VENDOR=	schedmd
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_RC_SUBR=	slurmctld slurmd

SHEBANG_FILES=	doc/html/shtml2html.py doc/man/man2html.py

GNU_CONFIGURE=	yes
# FreeBSD Infiniband support is still experimental
# slurmrestd does not build on FreeBSD
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-slurmrestd \
		--docdir=${DOCSDIR} \
		--htmldir=${DOCSDIR} \
		--sysconfdir=${ETCDIR} \
		--with-mysql_config=${LOCALBASE}/bin
CONFIGURE_ENV=	MAKE=${GMAKE}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CFLAGS+=	-I${WRKSRC}/slurm
LDFLAGS+=	-lsysinfo -lprocstat -fcommon

SUB_FILES=	pkg-message

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_SUB=	GROUPS=${GROUPS} \
		USERS=${USERS}
PORTDOCS=	*

OPTIONS_DEFINE=		CURL DOCS GUI HDF5 HWLOC IPMI
OPTIONS_DEFAULT=	HDF5 HWLOC
OPTIONS_SUB=		yes

CURL_DESC=	Require cURL for elasticsearch plugins
GUI_DESC=	Build sview GUI config tool
HDF5_DESC=	Job profiling using HDF5
HWLOC_DESC=	Portable hardware locality
IPMI_DESC=	IPMI energy consumption accounting

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

DOCS_BUILD_DEPENDS=	man2html:textproc/man2html

GUI_BUILD_DEPENDS=	itstool:textproc/itstool
GUI_USES=		gnome
GUI_USE=		GNOME=cairo,gdkpixbuf,glib20,gtk20,pango
GUI_CONFIGURE_ENABLE=	glibtest gtktest x11

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5 \
			libhdf5_hl.so:science/hdf5
HDF5_CONFIGURE_WITH=	hdf5
HDF5_CONFIGURE_ENV=	H5CC=${LOCALBASE}/bin/h5cc \
			H5FC=${LOCALBASE}/bin/h5fc
HDF5_LDFLAGS=		-lhdf5_hl

HWLOC_LIB_DEPENDS=	libhwloc.so.15:devel/hwloc2
HWLOC_CONFIGURE_WITH=	hwloc

IPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi \
			libipmimonitoring.so:sysutils/freeipmi
IPMI_CONFIGURE_WITH=	freeipmi

_ARCH=	${ARCH:S|aarch64|aarch64elf|:S|amd64|elf_amd64|:S|powerpc64le|elf64lppc|:S|powerpc64|elf64ppc|:S|riscv64|elf64lriscv|}

# SLURM's configure enables interactive jobs if pty.h exists.  Replacing
# #include <pty.h> with appropriate headers will therefore not work, so instead
# add a pty.h for the build.
pre-configure:
	${CP} ${FILESDIR}/pty.h ${WRKSRC}/slurm
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/configure
# Make /proc => /compat/linux/proc edits only in files that exist & contain "/proc"
	(cd ${WRKSRC} && \
		${GREP} -RIl '"/proc' src | ${XARGS} ${REINPLACE_CMD} \
			-e 's|"/proc|"/compat/linux/proc|g' \
			 -e 's|(/proc)|(/compat/linux/proc)|g')
	@if ${WHICH} sbatch > /dev/null; then \
		${ECHO_CMD} "********************************************"; \
		${ECHO_CMD} "Build may fail while slurm-wlm is installed."; \
		${ECHO_CMD} "Deinstall slurm-wlm and run make again."; \
		${ECHO_CMD} "********************************************"; \
		false; \
	fi
# Fix lld binary-blob rule: add -m ${_ARCH} wherever --format=binary is used
	${FIND} ${WRKSRC} -name Makefile.in -print0 | \
		${XARGS} -0 ${GREP} -Il -- '--format=binary' | \
		${XARGS} ${REINPLACE_CMD} -e 's|$$(LD) -r -o|$$(LD) -r -m ${_ARCH} -o|'
	${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${REINPLACE_CMD} -e 's|htmldir = \$${datadir.*$$|htmldir = @htmldir@|'

# Hack around nonfunctional --disable-gtktest flag
pre-configure-GUI-off:
	 ${REINPLACE_CMD} -e 's|min_gtk_version=.*|min_gtk_version=2000.0.0|' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}/var/spool/slurmctld \
		  ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/slurm.conf.example \
		${STAGEDIR}${ETCDIR}/slurm.conf.sample

.include <bsd.port.mk>
