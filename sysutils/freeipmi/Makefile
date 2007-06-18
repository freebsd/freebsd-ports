# New ports collection makefile for:	freeipmi
# Date created:				20/Oct/2004
# Whom:					Dmitry Frolov <frol@nov.net>
#
# $FreeBSD$
#
# Available KNOBs:
#
# WITH_DEBUG   - Build binaries suitable for debugging with gdb(1).
#

PORTNAME=	freeipmi
PORTVERSION=	0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.zresearch.com/pub/freeipmi/${PORTVERSION}/ \
	ftp://ftp.riss-telecom.ru/pub/mirrors/ftp.zresearch.com/pub/freeipmi/${PORTVERSION}/

MAINTAINER=	frolov@riss-telecom.ru
COMMENT=	Library and tools to support IPMI-capable hardware

BUILD_DEPENDS+=	${LOCALBASE}/lib/libargp.a:${PORTSDIR}/devel/argp-standalone
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--disable-init-scripts --disable-logrotate-config
USE_LDCONFIG=	yes
NOT_FOR_ARCHS=	ia64 sparc64 alpha
PLIST_SUB+=	FREEIPMI_SHLIBVER=${FREEIPMI_SHLIBVER} \
	IPMICONSOLE_SHLIBVER=${IPMICONSOLE_SHLIBVER}
MAN5+=	ipmipower.conf.5 bmc-config.conf.5 ipmiconsole.conf.5
MAN8+=	bmc-watchdog.8 ipmipower.8 ipmi-raw.8 ipmi-sel.8 \
	ipmi-sensors.8 ipmi-locate.8 bmc-info.8 ipmiping.8 \
	rmcpping.8 bmc-autoconfig.8 bmc-config.8 ipmiconsole.8
INFO+=		freeipmi freeipmi-faq
PORTDOCS=	*

FREEIPMI_SHLIBVER=	3
IPMICONSOLE_SHLIBVER=	0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500112
BROKEN=	missing getpw*_r functions in this FreeBSD release
.endif

# Use i386_set_ioperm(2) instead of io(4) to gain access to I/O
# ports. Note: there is a bug in FreeBSD 5 before 5.5-RELEASE that
# causes SIGBUS to the process sometimes when i386_set_ioperm is used
# (PR 84842).
.if ${ARCH} == "i386" && (defined(WITH_IOPERM) || \
	${OSVERSION} < 500000 || ${OSVERSION} >= 505000)
CPPFLAGS+=	-DUSE_IOPERM
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
STRIP=	# empty
.endif

post-install:
	@${CHMOD} 0700 ${DESTDIR}${PREFIX}/var/log/freeipmi \
		${DESTDIR}${PREFIX}/var/lib/freeipmi

.include <bsd.port.post.mk>
