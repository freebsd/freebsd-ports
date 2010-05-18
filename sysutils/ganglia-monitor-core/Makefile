# Ports collection makefile for:	ganglia-monitor-core
# Date created:				Wed Jan 23, 2003
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	monitor-core
PORTVERSION=	3.1.1
PORTREVISION=	5
CATEGORIES=	sysutils net parallel
MASTER_SITES=	SF/ganglia/ganglia%20monitoring%20core/${PORTVERSION}%20%28Wien%29
PKGNAMEPREFIX=	ganglia-
.if defined(CLUSTER)
PKGNAMESUFFIX=	-${CLUSTER}
.endif
DISTNAME=	ganglia-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Ganglia cluster monitor, monitoring daemon

LIB_DEPENDS+=	confuse:${PORTSDIR}/devel/libconfuse
LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr1

PKGINSTALL=	${WRKDIR}/pkg-install

OPTIONS+=	GMETAD "include gmetad" on

USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	configure libmetrics/configure

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${_CFLAGS}" LDFLAGS="${_LDFLAGS}"
_CFLAGS=	${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
_LDFLAGS=	${LDFLAGS} -L${LOCALBASE}/lib

SUB_FILES=	pkg-install

.if defined (GMETAD_CONF)
.if !exists (${GMETAD_CONF})
IGNORE=		the variable GMETAD_CONF must point to a file when defined
.endif
.else
GMETAD_CONF=	${WRKSRC}/gmetad/gmetad.conf
.endif

.if defined (GMOND_CONF)
.if !exists (${GMOND_CONF})
IGNORE=		the variable GMOND_CONF must point to a file when defined
.endif
.else
GMOND_CONF=	${WRKDIR}/gmond.conf
.endif

.include <bsd.port.pre.mk>

# The daemons should use seperate scripts, but prior to 6.1 they won't
# run in the right order.  In those cases we use the old monolythic
# script.
.if (${OSVERSION} >= 700007 || ( ${OSVERSION} < 700000 && ${OSVERSION} >= 600101))
USE_RC_SUBR=	gmond.sh
.if defined (WITH_GMETAD)
USE_RC_SUBR+=	gmetad.sh
.endif
.else
USE_RC_SUBR=	ganglia.sh
.endif

.if defined (WITH_GMETAD)
LIB_DEPENDS+=	rrd:${PORTSDIR}/databases/rrdtool
CONFIGURE_ARGS+=	--with-gmetad
PLIST_SUB+=	GMETAD=
SUB_LIST+=	GMETAD=
.else
PLIST_SUB+=	GMETAD="@comment "
SUB_LIST+=	GMETAD="\#"
.endif

USE_LDCONFIG=	yes

MAN1=		gmetric.1 gmond.1 gstat.1
.if defined (WITH_GMETAD)
MAN1+=		gmetad.1
.endif
MAN5=		gmond.conf.5

CONF_DIR=	${PREFIX}/etc

FIX_CONF_FILES=	README \
		ganglia.pod \
		mans/gmetad.1 \
		mans/gmond.1 \
		gmetad/cmdline.c \
		gmetad/cmdline.h \
		gmond/g25_config.h \
		gmetric/cmdline.c \
		gmetric/cmdline.h \
		gmond/cmdline.c \
		gmond/cmdline.h
FIX_DB_FILES=	ganglia.pod \
		gmetad/conf.c \
		gmetad/gmetad.conf
FIX_USER_FILES=	ganglia.pod \
		gmetad/conf.c.in \
		gmetad/conf.c \
		gmetad/gmetad.conf \
		gmetad/gmetad.conf.in \
		gmond/conf.pod \
		gmond/gmond.conf.5 \
		gmond/gmond.conf.html \
		gmond/g25_config.c \
		lib/libgmond.c \
		lib/default_conf.h.in

MODULES=	modcpu.so \
		moddisk.so \
		modload.so \
		modmem.so \
		modmulticpu.so \
		modnet.so \
		modproc.so \
		modpython.so \
		modsys.so

post-patch:
	${REINPLACE_CMD} -e "s|/etc/ganglia/\(gm[a-z]*d.conf\)|${PREFIX}/etc/\1|g" \
	    ${FIX_CONF_FILES:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e "s|/var/lib/ganglia|/var/db/ganglia|g" \
	    ${FIX_DB_FILES:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e "s|nobody|ganglia|g" \
	    ${FIX_USER_FILES:S|^|${WRKSRC}/|}

post-build:
	${WRKSRC}/gmond/gmond -t > ${WRKDIR}/gmond.conf

post-install:
.if defined(WITH_GMETAD)
	${INSTALL_SCRIPT} ${FILESDIR}/gmetasnap.sh ${PREFIX}/sbin/gmetasnap
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${GMETAD_CONF} ${PREFIX}/etc/gmetad.conf.sample
.endif
	${INSTALL_MAN} ${WRKSRC}/mans/gmetric.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mans/gmond.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/gmond/gmond.conf.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/mans/gstat.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${GMOND_CONF} ${PREFIX}/etc/gmond.conf.sample
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
