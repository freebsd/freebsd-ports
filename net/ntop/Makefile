# New ports collection makefile for:   ntop
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ntop
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Network monitoring tool with command line and web interfaces

LIB_DEPENDS=	gd1.2:${PORTSDIR}/graphics/gd1 \
		gdbm:${PORTSDIR}/databases/gdbm

DBDIR?=		/var/db

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_OPENSSL=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB+=	DBDIR=${DBDIR}
CONFIGURE_ENV=	LIBS="-lcrypto -L${LOCALBASE}/lib ${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=${DBDIR} \
		--with-ossl-root=${OPENSSLBASE} \
		--with-gdbm-root=${LOCALBASE} \
		--with-gdchart-lib=${WRKSRC}/../gdchart0.94c \
		--with-gdchart-include=${WRKSRC}/../gdchart0.94c \
		--with-gd-root=${LOCALBASE} \
		--with-libpng-root=${LOCALBASE} \
		--with-zlib-root=/usr

MAN8=		ntop.8

##
## Available knobs:
##    WITH_LOCALE:        Enable locale (i18n) support.
##    WITH_LSOF:          Add lsof as dependency.
##    WITH_PCAP:          Enable libpcap support.
##    WITH_PCAP_PORT:     Use libpcap from ports.
##    WITH_RRD:           Enable rrdtool support.
##    WITH_XMLDUMP:       Enable XML Dump support.
##
##    WITHOUT_TCPWRAPPER: Disable TCP wrapper support.
##
OPTIONS=	LOCALE "Enable locale (i18n) support." Off \
		LSOF "Add lsof as dependency." Off \
		PCAP "Enable libpcap support." Off \
		PCAP_PORT "Use libpcap from ports." Off \
		RRD "Enablerrdtool support." Off \
		XMLDUMP "Enable XML Dump support." Off \
		TCPWRAPPER "Enable TCP wrapper support" On

.include <bsd.port.pre.mk>

.if defined(WITH_TCPWRAPPER)
CONFIGURE_ARGS+=	--with-tcpwrap
.endif

.if defined(WITH_PCAP)
.    if defined(WITH_PCAP_PORT)
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
PCAP_ROOT=		${LOCALBASE}
.    else
PCAP_ROOT=		/usr
.    endif
CONFIGURE_ARGS+=	--with-pcap-root=${PCAP_ROOT}
.endif

.if defined(WITH_RRD)
LIB_DEPENDS+=		rrd.0:${PORTSDIR}/net/rrdtool
CONFIGURE_ARGS+=	--enable-rrd \
			--with-rrd-root=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-rrd-root
.endif

.if defined(WITH_LSOF)
RUN_DEPENDS+=		lsof:${PORTSDIR}/sysutils/lsof
.endif

.if defined(WITH_LOCALE)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-i18n \
			--with-localedir=${LOCALBASE}/share/locale
.endif

.if defined(WITH_XMLDUMP)
LIB_DEPENDS+=		gdome.8:${PORTSDIR}/textproc/gdome2
CONFIGURE_ARGS+=	--enable-xmldump \
			--with-xml2-lib=${LOCALBASE}/lib \
			--with-xml2-include=${LOCALBASE}/include/libxml2/libxml \
			--with-gdome-lib=${LOCALBASE}/lib \
			--with-gdome-include=${LOCALBASE}/include/libgdome \
			--with-glib-lib=${LOCALBASE}/lib \
			--with-glib-include=${LOCALBASE}/include/glib12
CONFIGURE_ENV+=		"CPPFLAGS=-I${LOCALBASE}/include/libxml2 "
.endif

pre-everything:: show-options

show-options:
	@${SED} -ne 's/^##//p' ${.CURDIR}/Makefile

# This part is a little bit dirty, but configure script need gdchart linked against
# libgd1.
pre-configure:
	@${CP} ${FILESDIR}/Makefile.gdchart ${WRKSRC}/../gdchart0.94c/Makefile
	@(cd ${WRKSRC}/../gdchart0.94c ; ${SETENV} ${MAKE_ENV} ${MAKE})

post-install:
	@${MKDIR} ${DBDIR}/ntop
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${SED} -e "s#%%PREFIX%%#${PREFIX}#g" \
		-e "s#%%LOGDIR%%#${LOGDIR}#g" ${FILESDIR}/ntop.sh > \
		${WRKDIR}/ntop.sh
	@${INSTALL_DATA} ${WRKDIR}/ntop.sh ${PREFIX}/etc/rc.d
.if !defined(BATCH)
	@${SED} "s,%%LOCALBASE%%,${LOCALBASE},g" < ${PKGMESSAGE}
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
