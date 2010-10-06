# New ports collection makefile for:	freeipmi
# Date created:				20/Oct/2004
# Whom:					Dmitry Frolov <frol@nov.net>
#
# $FreeBSD$
#
# Available KNOBs:
#
# WITH_DEBUG   - Enable debugging features.
# WITH_IOPERM  - Use i386_set_ioperm(2) instead of io(4) to gain access
#                to I/O ports (i386/amd64 only).
#

PORTNAME=	freeipmi
PORTVERSION=	0.8.10
CATEGORIES=	sysutils
MASTER_SITES=	GNU/${PORTNAME}/ \
		http://ftp.gluster.com/pub/${PORTNAME}/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and tools to support IPMI-capable hardware

LIB_DEPENDS=	argp:${PORTSDIR}/devel/argp-standalone \
		gcrypt:${PORTSDIR}/security/libgcrypt

CONFIGURE_ARGS=	--disable-init-scripts \
		--disable-logdir \
		--disable-logrotate-config \
		--localstatedir=/var \
		--sysconfdir=${CONF_DIR} \
		--with-ipmi-monitoring-sdr-cache-dir=${CACHE_DIR}/ipmimonitoringsdrcache
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" PTHREAD_LIBS=${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"invokes i386 asm"
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_LDCONFIG=	yes

OPTIONS=	DEBUG	"Debugging features" off \
		IOPERM	"Use i386_set_ioperm (i386/amd64 only)" off

INFO=		freeipmi-faq
MAN3=		libfreeipmi.3 libipmiconsole.3 libipmidetect.3 libipmimonitoring.3
MAN5=		bmc-config.conf.5 freeipmi.conf.5 ipmi_monitoring_sensors.conf.5 \
		ipmiconsole.conf.5 ipmidetect.conf.5 ipmidetectd.conf.5 \
		ipmimonitoring.conf.5 ipmimonitoring_sensors.conf.5 \
		ipmipower.conf.5 libipmimonitoring.conf.5
MAN7=		freeipmi.7
MAN8=		bmc-config.8 bmc-device.8 bmc-info.8 bmc-watchdog.8 \
		ipmi-chassis-config.8 ipmi-chassis.8 ipmi-dcmi.8 ipmi-fru.8 \
		ipmi-locate.8 ipmi-oem.8 ipmi-pef-config.8 ipmi-raw.8 ipmi-sel.8 \
		ipmi-sensors-config.8 ipmi-sensors.8 ipmiconsole.8 ipmidetect.8 \
		ipmidetectd.8 ipmimonitoring.8 ipmiping.8 ipmipower.8 \
		pef-config.8 rmcpping.8
PLIST_SUB+=	FREEIPMI_SHLIBVER=${FREEIPMI_SHLIBVER} \
		IPMICONSOLE_SHLIBVER=${IPMICONSOLE_SHLIBVER} \
		IPMIDETECT_SHLIBVER=${IPMIDETECT_SHLIBVER} \
		IPMIMONITORING_SHLIBVER=${IPMIMONITORING_SHLIBVER} \
		CACHE_DIR=${CACHE_DIR} LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR}

CACHE_DIR?=	/var/db/${PORTNAME}
LOG_DIR=	/var/log/${PORTNAME}
RUN_DIR=	/var/lib/${PORTNAME}
CONF_DIR?=	${PREFIX}/etc/${PORTNAME}
FREEIPMI_SHLIBVER=		10
IPMICONSOLE_SHLIBVER=		3
IPMIDETECT_SHLIBVER=		0
IPMIMONITORING_SHLIBVER=	4

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug --enable-trace
.endif

.if defined(WITH_IOPERM)
.if ${ARCH} == "amd64" && ${OSVERSION} < 800000
BROKEN=		IOPERM option is not available on FreeBSD/amd64 7.x and below
.else
CPPFLAGS+=	-DUSE_IOPERM
.endif
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.man' -o -name '*.pre.in' | ${XARGS} -I % ${REINPLACE_CMD} -e '/^\.\\\"/ s|$$|"|' %
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s| install-docDATA||' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	@${MKDIR} ${LOG_DIR}
	@${CHMOD} 0700 ${CACHE_DIR} ${LOG_DIR} ${RUN_DIR}

.include <bsd.port.post.mk>
