# New ports collection makefile for:	freeipmi
# Date created:				20/Oct/2004
# Whom:					Dmitry Frolov <frol@nov.net>
#
# $FreeBSD$
#

PORTNAME=	freeipmi
PORTVERSION=	1.1.7
CATEGORIES=	sysutils
MASTER_SITES=	GNU/${PORTNAME}/ \
		http://ftp.gluster.com/pub/${PORTNAME}/${PORTVERSION}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and tools to support IPMI-capable hardware

LICENSE=	GPLv3

LIB_DEPENDS=	argp:${PORTSDIR}/devel/argp-standalone \
		gcrypt:${PORTSDIR}/security/libgcrypt

OPTIONS_DEFINE=	DEBUG DOCS IOPERM
IOPERM_DESC=	Use i386_set_ioperm (i386/amd64 only)

CONFIGURE_ARGS=	--disable-init-scripts \
		--disable-logdir \
		--disable-logrotate-config \
		--localstatedir=/var \
		--sysconfdir=${CONF_DIR} \
		--with-ipmi-monitoring-sdr-cache-dir=${CACHE_DIR}/ipmimonitoringsdrcache \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	"invokes i386 asm"
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

INFO=		freeipmi-faq
MAN3=		libfreeipmi.3 libipmiconsole.3 libipmidetect.3 libipmimonitoring.3
MAN5=		bmc-config.conf.5 freeipmi.conf.5 freeipmi_interpret_sel.conf.5 \
		freeipmi_interpret_sensor.conf.5 ipmi_monitoring_sensors.conf.5 \
		ipmiconsole.conf.5 ipmidetect.conf.5 ipmidetectd.conf.5 \
		ipmimonitoring.conf.5 ipmimonitoring_sensors.conf.5 \
		ipmipower.conf.5 libipmiconsole.conf.5 libipmimonitoring.conf.5
MAN7=		freeipmi.7
MAN8=		bmc-config.8 bmc-device.8 bmc-info.8 bmc-watchdog.8 \
		ipmi-chassis-config.8 ipmi-chassis.8 ipmi-console.8 \
		ipmi-dcmi.8 ipmi-detect.8 ipmi-fru.8 ipmi-locate.8 ipmi-oem.8 \
		ipmi-pef-config.8 ipmi-pet.8 ipmi-ping.8 ipmi-power.8 \
		ipmi-raw.8 ipmi-sel.8 ipmi-sensors-config.8 ipmi-sensors.8 \
		ipmiconsole.8 ipmidetect.8 ipmidetectd.8 ipmimonitoring.8 \
		ipmiping.8 ipmipower.8 pef-config.8 rmcp-ping.8 rmcpping.8
PLIST_SUB=	CACHE_DIR=${CACHE_DIR} CONF_DIR=${ETCDIR:S/^${PREFIX}\///} \
		LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR}

CACHE_DIR?=	/var/db/${PORTNAME}
CONF_DIR?=	${ETCDIR}
LOG_DIR=	/var/log/${PORTNAME}
RUN_DIR=	/var/lib/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug --enable-trace
.endif

.if ${PORT_OPTIONS:MIOPERM}
CPPFLAGS+=	-DUSE_IOPERM
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIOPERM} && ${ARCH} == "amd64" && ${OSVERSION} < 800000
BROKEN=		IOPERM option is not available on FreeBSD/amd64 7.x
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.man' -o -name '*.pre.in' | ${XARGS} -I % ${REINPLACE_CMD} -e '/^\.\\\"/ s|$$|"|' %
	@${REINPLACE_CMD} \
		-e '/^FREEIPMI_SYSCONFDIR/ s|/freeipmi/$$||' \
		-e '/FREEIPMI_CONFIG_FILE_DEFAULT_TMP1=/ s|freeipmi.conf|&.sample|' \
			${WRKSRC}/configure
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-docDATA||' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	${MKDIR} ${LOG_DIR}/
	${CHMOD} 0700 ${CACHE_DIR}/ ${LOG_DIR}/ ${RUN_DIR}/

.include <bsd.port.post.mk>
