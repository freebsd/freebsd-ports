# Ports collection makefile for:	ganglia-monitor-core
# Date created:				Wed Jan 23, 2003
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ganglia-monitor-core
PORTVERSION=	2.5.6
CATEGORIES=	sysutils net parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ganglia
.if defined (WITHOUT_GMETAD)
PKGNAMESUFFIX=	-nogmetad
.endif

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Ganglia cluster monitor, monitoring daemon

.if !defined (WITHOUT_GMETAD)
LIB_DEPENDS=	rrd.0:${PORTSDIR}/net/rrdtool
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib

.if !defined (WITHOUT_GMETAD)
CONFIGURE_ARGS+=	--with-gmetad
.endif
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
.if defined (WITHOUT_GMETAD)
PLIST_SUB+=	GMETAD="@comment "
.else
PLIST_SUB+=	GMETAD=
.endif
USE_REINPLACE=	yes

MAN1=		gmetric.1 gmond.1 gstat.1
.if !defined (WITHOUT_GMETAD)
MAN1+=		gmetad.1
.endif

CONF_DIR=	${PREFIX}/etc
RC_DIR=		${PREFIX}/etc/rc.d

FIX_CONF_FILES=	${WRKSRC}/lib/ganglia/gmond_config.h \
		${WRKSRC}/mans/gmetad.1 \
		${WRKSRC}/mans/gmond.1 \
		${WRKSRC}/gmetad/cmdline.c \
		${WRKSRC}/gmetad/cmdline.h \
		${WRKSRC}/gmond/cmdline.c \
		${WRKSRC}/gmond/cmdline.h
FIX_DB_FILES=	${WRKSRC}/gmetad/conf.c \
		${WRKSRC}/gmetad/gmetad.conf

post-patch:
	${REINPLACE_CMD} -e "s|/etc/\(gm[a-z]*d.conf\)|${CONF_DIR}/\1|g" \
	    ${FIX_CONF_FILES}
	${REINPLACE_CMD} -e "s|/var/lib/ganglia|/var/db/ganglia|g" \
	    ${FIX_DB_FILES}
	${REINPLACE_CMD} -e 's|-pthread||g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

# Post-install
#

post-install: install-man install-sample-files install-startup-files
	${SH} pkg-install ${PKGNAME} POST-INSTALL

install-man:
	${INSTALL_MAN} ${WRKSRC}/mans/gmetric.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mans/gmond.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mans/gstat.1 ${MANPREFIX}/man/man1
.if !defined (WITHOUT_GMETAD)
	${INSTALL_MAN} ${WRKSRC}/mans/gmetad.1 ${MANPREFIX}/man/man1
.endif

install-sample-files:
	${INSTALL_DATA} ${WRKSRC}/gmond/gmond.conf \
	    ${CONF_DIR}/gmond.conf.sample
.if !defined (WITHOUT_GMETAD)
	${INSTALL_DATA} ${WRKSRC}/gmetad/gmetad.conf \
	    ${CONF_DIR}/gmetad.conf.sample
.endif

install-startup-files:
	${INSTALL_SCRIPT} ${FILESDIR}/gmond.sh.sample ${RC_DIR}
.if !defined (WITHOUT_GMETAD)
	${INSTALL_SCRIPT} ${FILESDIR}/gmetad.sh.sample ${RC_DIR}
.endif

.include <bsd.port.mk>
