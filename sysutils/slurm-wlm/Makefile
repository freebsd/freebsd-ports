# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	slurm
PORTVERSION=	14.11.9
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/development/
PKGNAMESUFFIX=	-wlm

MAINTAINER=	jrm@ftfl.ca
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsysinfo.so:${PORTSDIR}/devel/libsysinfo \
		libhwloc.so:${PORTSDIR}/devel/hwloc \
		libmunge.so:${PORTSDIR}/security/munge \
		librrd.so:${PORTSDIR}/databases/rrdtool \
		libhdf5.so:${PORTSDIR}/science/hdf5

USERS=		slurm
GROUPS=		${USERS}

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	slurmctld slurmd
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
INSTALL_TARGET=	install-strip
USES=		gmake libtool perl5 pkgconfig python tar:bz2
GTK2_USE=	GNOME=glib20,gtk20
MYSQL_USE=	MYSQL=yes
CFLAGS+=	-I${WRKSRC}/slurm -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lsysinfo -lkvm

OPTIONS_DEFINE=	DOCS MYSQL GTK2
OPTIONS_SUB=	yes

GTK2_DESC=	Build GUI config tool sview

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
	${INSTALL_DATA} ${FILESDIR}/slurm.conf.example ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
