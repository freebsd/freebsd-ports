# Ports collection makefile for:	ganglia-monitor-core
# Date created:				Wed Jan 23, 2003
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	monitor-core
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	sysutils net parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ganglia
PKGNAMEPREFIX=	ganglia-
DISTNAME=	ganglia-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Ganglia cluster monitor, monitoring daemon

PKGINSTALL=	${WRKSRC}/pkg-install

OPTIONS+=	GMETAD "include gmetad" on

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${_CFLAGS}" LDFLAGS="${_LDFLAGS}"
_CFLAGS=	${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
_LDFLAGS=	${LDFLAGS} -L${LOCALBASE}/lib

USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	ganglia.sh

SUB_FILES=	pkg-install

.include <bsd.port.pre.mk>

.if defined (WITH_GMETAD)
LIB_DEPENDS=	rrd.0:${PORTSDIR}/net/rrdtool
CONFIGURE_ARGS+=	--with-gmetad
.endif
INSTALLS_SHLIB=	yes
.if !defined (WITH_GMETAD)
PLIST_SUB+=	GMETAD="@comment "
SUB_LIST+=	GMETAD="\#"
.else
PLIST_SUB+=	GMETAD=
SUB_LIST+=	GMETAD=
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

post-install:
	${INSTALL_MAN} ${WRKSRC}/mans/gmetric.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mans/gmond.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/gmond/gmond.conf.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/mans/gstat.1 ${MANPREFIX}/man/man1
.if defined (WITH_GMETAD)
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 ${MANPREFIX}/man/man1
.endif
	${INSTALL_DATA} ${WRKDIR}/gmond.conf ${PREFIX}/etc/gmond.conf.sample
.if defined (WITH_GMETAD)
	${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf \
	    ${PREFIX}/etc/gmetad.conf.sample
	@if [ ! -f ${CONF_DIR}/gmetad.conf ]; then \
		${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf ${CONF_DIR} ;\
	fi
.endif
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
