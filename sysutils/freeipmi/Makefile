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
#                to I/O ports (i386 only). Note: there is a bug in
#                FreeBSD 5 before 5.5-RELEASE that causes SIGBUS to the
#                process sometimes when i386_set_ioperm is used (PR
#                84842).
#

PORTNAME=	freeipmi
PORTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://ftp.zresearch.com/pub/freeipmi/${PORTVERSION}/ \
	ftp://freebsd.riss-telecom.ru/pub/mirrors/ftp.zresearch.com/pub/freeipmi/${PORTVERSION}/

MAINTAINER=	frol@nov.net
COMMENT=	Library and tools to support IPMI-capable hardware

BUILD_DEPENDS+=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
	PTHREAD_LIBS=-pthread
CONFIGURE_ARGS+=	--disable-init-scripts --disable-logrotate-config \
	--disable-logdir --localstatedir=/var \
	--with-ipmi-monitoring-sdr-cache-dir=${CACHE_DIR}/ipmimonitoringsdrcache \
	--sysconfdir=${CONF_DIR}
USE_LDCONFIG=	yes
NOT_FOR_ARCHS=	ia64 sparc64 alpha
PLIST_SUB+=	FREEIPMI_SHLIBVER=${FREEIPMI_SHLIBVER} \
	IPMICONSOLE_SHLIBVER=${IPMICONSOLE_SHLIBVER} \
	IPMIDETECT_SHLIBVER=${IPMIDETECT_SHLIBVER} \
	IPMIMONITORING_SHLIBVER=${IPMIMONITORING_SHLIBVER} \
	CACHE_DIR=${CACHE_DIR} LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR}
MAN3+=	libfreeipmi.3 libipmiconsole.3 libipmidetect.3 \
	libipmimonitoring.3
MAN5+=	bmc-config.conf.5 freeipmi.conf.5 ipmiconsole.conf.5 \
	ipmidetect.conf.5 ipmidetectd.conf.5 ipmipower.conf.5
MAN7+=	freeipmi.7
MAN8+=	bmc-config.8 bmc-device.8 bmc-info.8 bmc-watchdog.8 \
	ipmi-chassis-config.8 ipmi-chassis.8 ipmi-fru.8 \
	ipmi-locate.8 ipmi-oem.8 ipmi-raw.8 ipmi-sel.8 \
	ipmi-sensors-config.8 ipmi-sensors.8 ipmiconsole.8 \
	ipmidetect.8 ipmidetectd.8 ipmimonitoring.8 ipmiping.8 \
	ipmipower.8 pef-config.8 rmcpping.8
INFO+=		freeipmi-faq

CACHE_DIR?=	/var/db/${PORTNAME}
LOG_DIR=	/var/log/${PORTNAME}
RUN_DIR=	/var/lib/${PORTNAME}
CONF_DIR?=	${PREFIX}/etc/${PORTNAME}
FREEIPMI_SHLIBVER=	7
IPMICONSOLE_SHLIBVER=	2
IPMIDETECT_SHLIBVER=	0
IPMIMONITORING_SHLIBVER=	2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITH_IOPERM)
.if ${ARCH} == "i386"
CPPFLAGS+=	-DUSE_IOPERM
.else
BROKEN=	IOPERM option is only available on i386 and You are building for ${ARCH}
.endif
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug --enable-trace
STRIP=	# empty
.endif

.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${FILESDIR}/extra-noportdocs.patch
.else
PORTDOCS=	*
.endif

post-install:
	@${MKDIR} ${LOG_DIR}
	@${CHMOD} 0700 ${CACHE_DIR} ${LOG_DIR} ${RUN_DIR}
	[ -f ${CONF_DIR}/freeipmi.conf ] || \
		${CP} -p ${CONF_DIR}/freeipmi.conf.sample ${CONF_DIR}/freeipmi.conf
	[ -f ${CONF_DIR}/ipmi_monitoring_sensors.conf ] || \
		${CP} -p ${CONF_DIR}/ipmi_monitoring_sensors.conf.sample \
			${CONF_DIR}/ipmi_monitoring_sensors.conf

.include <bsd.port.post.mk>
