# Ports collection makefile for:	ganglia-monitor-core
# Date created:				Wed Jan 23, 2003
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	monitor-core
PORTVERSION=	3.1.7
PORTREVISION=	2
CATEGORIES=	sysutils net parallel
MASTER_SITES=	SF/ganglia/ganglia%20monitoring%20core/${PORTVERSION}
PKGNAMEPREFIX=	ganglia-
.if defined(CLUSTER)
PKGNAMESUFFIX=	-${CLUSTER}
.endif
DISTNAME=	ganglia-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Ganglia cluster monitor, monitoring daemon

LIB_DEPENDS=	apr-1:${PORTSDIR}/devel/apr1 \
		confuse:${PORTSDIR}/devel/libconfuse \
		pcre:${PORTSDIR}/devel/pcre

PKGINSTALL=	${WRKDIR}/pkg-install

OPTIONS+=	GMETAD "include gmetad" on

USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure libmetrics/configure

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-setuid=ganglia --enable-setgid=ganglia
CONFIGURE_ENV=	GANGLIA_ACK_SYSCONFDIR=1 "LDFLAGS=${LDFLAGS}"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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

USE_RC_SUBR=	gmond.sh
.if defined (WITH_GMETAD)
USE_RC_SUBR+=	gmetad.sh
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
		mans/gmetad.1 \
		mans/gmond.1
FIX_GMOND_CONF_DIR=	\
		gmond/modules/conf.d/modpython.conf.in \
		gmond/modules/python/Makefile.in \
		lib/default_conf.h.in
# gmond.conf.5 and gmond.conf.html can be generated from conf.pod, but
# doing so requires perl installed in the build stage.
FIX_USER_FILES=	gmetad/gmetad.conf.in \
		gmond/conf.pod \
		gmond/gmond.conf.5 \
		gmond/gmond.conf.html

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
	${REINPLACE_CMD} -e "s|%%GMONDCONFDIR%%|gmond.conf.d|g" \
	    ${FIX_GMOND_CONF_DIR:S|^|${WRKSRC}/|}
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
