# Created by: Dmitry Frolov <frol@nov.net>
# $FreeBSD$

PORTNAME=	freeipmi
PORTVERSION=	1.5.7
CATEGORIES=	sysutils
MASTER_SITES=	GNU \
		http://ftp.gluster.com/pub/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and tools to support IPMI-capable hardware

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	invokes i386 asm

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libgcrypt.so:security/libgcrypt

OPTIONS_DEFINE=	DEBUG DOCS IOPERM
IOPERM_DESC=	Use i386_set_ioperm

CONFIGURE_ARGS=	--disable-init-scripts \
		--sysconfdir=${ETCDIR} \
		--with-ipmi-monitoring-sdr-cache-dir=${CACHE_DIR}/ipmimonitoringsdrcache \
		--with-ipmiseld-cache-dir=${CACHE_DIR}/ipmiseld \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV=	PTHREAD_LIBS=-lpthread ac_cv_path_CPP=${CPP}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool localbase shebangfix

INFO=		freeipmi-faq
PLIST_SUB=	CACHE_DIR=${CACHE_DIR}
PORTDOCS=	*

CACHE_DIR?=	/var/db/${PORTNAME}

SHEBANG_FILES=	contrib/ganglia/ganglia_ipmi_sensors.pl \
		contrib/nagios/nagios_ipmi_sensors.pl \
		contrib/pet/check_rmcpping \
		contrib/pet/petalert.pl

DEBUG_CONFIGURE_ARGS=	--enable-debug --enable-trace
DEBUG_INSTALL_TARGET=	install
DEBUG_INSTALL_TARGET_OFF=	install-strip
IOPERM_CPPFLAGS=	-DUSE_IOPERM

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
