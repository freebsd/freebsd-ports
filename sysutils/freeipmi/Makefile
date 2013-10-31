# Created by: Dmitry Frolov <frol@nov.net>
# $FreeBSD$

PORTNAME=	freeipmi
PORTVERSION=	1.3.3
CATEGORIES=	sysutils
MASTER_SITES=	GNU/${PORTNAME}/ \
		http://ftp.gluster.com/pub/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and tools to support IPMI-capable hardware

LICENSE=	GPLv3

LIB_DEPENDS=	libargp.so:${PORTSDIR}/devel/argp-standalone \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

OPTIONS_DEFINE=	DEBUG DOCS IOPERM
IOPERM_DESC=	Use i386_set_ioperm

CONFIGURE_ARGS=	--disable-init-scripts \
		--localstatedir=/var \
		--sysconfdir=${ETCDIR} \
		--with-ipmi-monitoring-sdr-cache-dir=${CACHE_DIR}/ipmimonitoringsdrcache \
		--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV=	PTHREAD_LIBS=-pthread ac_cv_path_CPP=${CPP}
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	invokes i386 asm
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gmake shebangfix

INFO=		freeipmi-faq
PLIST_SUB=	CACHE_DIR=${CACHE_DIR} LOG_DIR=${LOG_DIR} RUN_DIR=${RUN_DIR}

CACHE_DIR?=	/var/db/${PORTNAME}
LOG_DIR=	/var/log/${PORTNAME}
RUN_DIR=	/var/lib/${PORTNAME}

SHEBANG_FILES=	contrib/ganglia/ganglia_ipmi_sensors.pl \
		contrib/nagios/nagios_ipmi_sensors.pl \
		contrib/pet/check_rmcpping \
		contrib/pet/petalert.pl

DEBUG_CONFIGURE_ARGS=	--enable-debug --enable-trace
DEBUG_MAKE_ENV=		INSTALL_STRIP_FLAG=""
IOPERM_CPPFLAGS=	-DUSE_IOPERM

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name '*.man' -o -name '*.pre.in' | ${XARGS} -I % ${REINPLACE_CMD} -e '/^\.\\\"/ s|$$|"|' %
	@${REINPLACE_CMD} \
		-e '/^FREEIPMI_SYSCONFDIR/ s|/freeipmi/$$||' \
		-e '/FREEIPMI_CONFIG_FILE_DEFAULT_TMP1=/ s|freeipmi.conf|&.sample|' \
			${WRKSRC}/configure
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^install-data-am:/ s|install-docDATA||' \
		${WRKSRC}/Makefile.in ${WRKSRC}/doc/Makefile.in
.endif

post-install:
	${MKDIR} -m 0700 ${CACHE_DIR}/ipmimonitoringsdrcache ${LOG_DIR}/ ${RUN_DIR}/

.include <bsd.port.mk>
