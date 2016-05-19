# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	slurm
PORTVERSION=	15.08.11
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/development/
PKGNAMESUFFIX=	-wlm

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libsysinfo.so:devel/libsysinfo \
		libmunge.so:security/munge

USERS=		slurm
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	slurmctld slurmd
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
INSTALL_TARGET=	install-strip
USES=		gmake libtool pkgconfig python:build tar:bz2
USE_perl5=	configure

OPTIONS_DEFINE=	CURL DOCS GTK2 HDF5 HWLOC IPMI MYSQL RRD
OPTIONS_DEFAULT=HDF5 HWLOC
OPTIONS_SUB=	yes

CURL_DESC=	Require cURL for elasticsearch plugins
GTK2_DESC=	Build sview GUI config tool
HDF5_DESC=	Job profiling using HDF5
HWLOC_DESC=	Portable hardware locality
IPMI_DESC=	IPMI engergy consumption accounting
RRD_DESC=	RRD external sensor data collection

GTK2_USE=		GNOME=glib20,gtk20

DOCS_BUILD_DEPENDS=	man2html:textproc/man2html

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_with=	libcurl

HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_CONFIGURE_WITH=	hdf5

HWLOC_LIB_DEPENDS=	libhwloc.so:devel/hwloc
HWLOC_CONFIGURE_WITH=	hwloc

IPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
IPMI_CONFIGURE_WITH=	freeipmi

RRD_LIB_DEPENDS=	librrd.so:databases/rrdtool
RRD_CONFIGURE_WITH=	rrdtool

MYSQL_USE=		MYSQL=yes

CFLAGS+=	-I${WRKSRC}/slurm -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lsysinfo -lkvm

# SLURM's configure enables interactive jobs if pty.h exists.  Replacing
# #include <pty.h> with appropriate headers will therefore not work, so instead
# add a pty.h for the build.
post-patch:
	${CP} ${FILESDIR}/pty.h ${WRKSRC}/slurm
	${REINPLACE_CMD} \
		-e 's|/usr/bin/env python|${PYTHON_CMD}|g' \
		${WRKSRC}/doc/html/shtml2html.py \
		${WRKSRC}/doc/man/man2html.py

post-install:
	${INSTALL_DATA} ${FILESDIR}/slurm.conf.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
