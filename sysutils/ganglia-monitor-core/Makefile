# Ports collection makefile for:	ganglia-monitor-core
# Date created:				Wed Jan 23, 2003
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	monitor-core
PORTVERSION=	3.0.1
PORTREVISION=	2
CATEGORIES=	sysutils net parallel
.if !defined(PORTDEV)
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
.else
MASTER_SITES=	http://matt-massie.com/%SUBDIR%/
.endif
MASTER_SITE_SUBDIR=	ganglia
PKGNAMEPREFIX=	ganglia-
.if defined(CLUSTER)
PKGNAMESUFFIX=	-${CLUSTER}
.endif
DISTNAME=	ganglia-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Ganglia cluster monitor, monitoring daemon

PKGINSTALL=	${WRKDIR}/pkg-install

OPTIONS+=	GMETAD "include gmetad" on \
		LIBGANGLIA "include libganglia" off

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${_CFLAGS}" LDFLAGS="${_LDFLAGS}"
_CFLAGS=	${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
_LDFLAGS=	${LDFLAGS} -L${LOCALBASE}/lib

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	ganglia.sh

SUB_FILES=	pkg-install

.if defined (GMETAD_CONF)
.if !exists (${GMETAD_CONF})
IGNORE=		 "GMETAD_CONF must point to an existing file when defined"
.endif
.else
GMETAD_CONF=	${WRKSRC}/gmetad/gmetad.conf
.endif

.if defined (GMOND_CONF)
.if !exists (${GMOND_CONF})
IGNORE=		"GMOND_CONF must point to an existing file when defined"
.endif
.else
GMOND_CONF=	${WRKDIR}/gmond.conf
.endif

.include <bsd.port.pre.mk>

.if defined (WITH_GMETAD)
LIB_DEPENDS=	rrd.2:${PORTSDIR}/net/rrdtool
CONFIGURE_ARGS+=	--with-gmetad
PLIST_SUB+=	GMETAD=
SUB_LIST+=	GMETAD=
.else
PLIST_SUB+=	GMETAD="@comment "
SUB_LIST+=	GMETAD="\#"
.endif

.if defined (WITH_LIBGANGLIA)
INSTALLS_SHLIB=	yes
PLIST_SUB+=	LIBGANGLIA=
.else
PLIST_SUB+=	LIBGANGLIA="@comment "
.endif

MAN1=		gmetric.1 gmond.1 gstat.1
.if defined (WITH_GMETAD)
MAN1+=		gmetad.1
.endif
MAN5=		gmond.conf.5

CONF_DIR=	${PREFIX}/etc

FIX_CONF_FILES=	ganglia.pod \
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

post-patch:
	${REINPLACE_CMD} -e "s|/etc/\(gm[a-z]*d.conf\)|${PREFIX}/etc/\1|g" \
	    ${FIX_CONF_FILES:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e "s|/var/lib/ganglia|/var/db/ganglia|g" \
	    ${FIX_DB_FILES:S|^|${WRKSRC}/|}

post-build:
	${WRKSRC}/gmond/gmond -t > ${WRKDIR}/gmond.conf

do-install:
.if defined (WITH_GMETAD)
	cd ${WRKSRC}/gmetad && make install
	${INSTALL_SCRIPT} ${FILESDIR}/gmetasnap.sh ${PREFIX}/sbin/gmetasnap
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${GMETAD_CONF} ${PREFIX}/etc/gmetad.conf.sample
.endif
	cd ${WRKSRC}/gmetric && make install
	${INSTALL_MAN} ${WRKSRC}/mans/gmetric.1 ${MANPREFIX}/man/man1
	cd ${WRKSRC}/gmond && make install
	${INSTALL_MAN} ${WRKSRC}/mans/gmond.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/gmond/gmond.conf.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/mans/gstat.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${GMOND_CONF} ${PREFIX}/etc/gmond.conf.sample
.if defined (WITH_LIBGANGLIA)
	cd ${WRKSRC}/lib && make install
	${INSTALL_SCRIPT} ${WRKSRC}/ganglia-config ${PREFIX}/bin
.endif

post-install:
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
