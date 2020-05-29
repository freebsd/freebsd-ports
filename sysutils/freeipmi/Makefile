# Created by: Dmitry Frolov <frol@nov.net>
# $FreeBSD$

PORTNAME=	freeipmi
PORTVERSION=	1.6.5
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and tools to support IPMI-capable hardware

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 powerpc64
BROKEN_aarch64=		fails to link: libfreeipmi/.libs/libfreeipmi.so: undefined reference to inb (also outb)
BROKEN_armv7=		fails to link: libfreeipmi/.libs/libfreeipmi.so: undefined reference to inb (also outb)

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libgcrypt.so:security/libgcrypt

USES=		gmake libtool localbase makeinfo shebangfix

CFLAGS+=	-D_WANT_SEMUN
CONFIGURE_ARGS=	--disable-init-scripts \
		--sysconfdir=${ETCDIR} \
		--with-ipmi-monitoring-sdr-cache-dir=${CACHE_DIR}/ipmimonitoringsdrcache \
		--with-ipmiseld-cache-dir=${CACHE_DIR}/ipmiseld \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV=	PTHREAD_LIBS=-lpthread ac_cv_path_CPP=${CPP}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		freeipmi-faq
PLIST_SUB=	CACHE_DIR=${CACHE_DIR}
PORTDOCS=	*

CACHE_DIR?=	/var/db/${PORTNAME}

SHEBANG_FILES=	contrib/ganglia/ganglia_ipmi_sensors.pl \
		contrib/nagios/nagios_ipmi_sensors.pl \
		contrib/pet/check_rmcpping \
		contrib/pet/petalert.pl

OPTIONS_DEFINE=	DEBUG DOCS IOPERM IPV6
IOPERM_DESC=	Use i386_set_ioperm

DEBUG_CONFIGURE_ON=	--enable-debug --enable-trace
DEBUG_INSTALL_TARGET=	install
DEBUG_INSTALL_TARGET_OFF=	install-strip
IOPERM_CPPFLAGS=	-DUSE_IOPERM
IPV6_CPPFLAGS=		-DIPV6

post-patch:
	@${FIND} ${WRKSRC} -name '*.man' -o -name '*.pre.in' | ${XARGS} -I % ${REINPLACE_CMD} -e '/^\.\\\"/ s|$$|"|' %
	@${REINPLACE_CMD} \
		-e '/^FREEIPMI_SYSCONFDIR/ s|/freeipmi/$$||' \
		-e '/FREEIPMI_CONFIG_FILE_DEFAULT_TMP1=/ s|freeipmi.conf|&.sample|' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\($$(LN_S) -f \)$$(sbindir)/|\1|' ${WRKSRC}/*/Makefile.in

post-install:
	${MKDIR} -m 0700 -p ${STAGEDIR}${CACHE_DIR}/ipmimonitoringsdrcache/ ${STAGEDIR}${CACHE_DIR}/ipmiseld/ ${STAGEDIR}/var/lib/freeipmi/ ${STAGEDIR}/var/run/freeipmi/

.include <bsd.port.mk>
