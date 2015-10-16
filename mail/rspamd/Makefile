# $FreeBSD$

PORTNAME=	rspamd
PORTVERSION=	1.0.6
CATEGORIES=	mail
MASTER_SITES=	http://rspamd.com/downloads/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast spam filtering system

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libgmime-2.4.so:${PORTSDIR}/mail/gmime24 \
		libevent.so:${PORTSDIR}/devel/libevent2 \
		libluajit-5.1.so:${PORTSDIR}/lang/luajit \
		libhiredis.so:${PORTSDIR}/databases/hiredis

OPTIONS_DEFINE=	GPERF REDIRECTOR
GPERF_DESC=		google perf-tools profiling
REDIRECTOR_DESC=	Install HTTP redirector

USE_RC_SUBR=	rspamd

PLIST_SUB+=	ETCDIR=etc/rspamd \
		RSPAMDVERSION=${PORTVERSION}
CMAKE_ARGS+=	-DCONFDIR=${PREFIX}/etc/rspamd \
		-DLOGDIR=/var/log/rspamd \
		-DDBDIR=/var/db/rspamd \
		-DRUNDIR=/var/run/rspamd \
		-DMANDIR=${MANPREFIX}/man \
		-DCMAKE_INSTALL_PREFIX=${PREFIX} \
		-DBUILD_PORT=yes \
		-DFORCE_GMIME24=yes \
		-DLIBDIR=${PREFIX}/lib/rspamd \
		-DNO_SHARED=ON

USES=		cmake:outsource gettext iconv pkgconfig tar:xz perl5 \
		compiler:c11
USE_LDCONFIG=	yes
USE_PERL5=	build

USE_GNOME=	glib20
USE_OPENSSL=	yes
USE_SQLITE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPERF}
 CMAKE_ARGS+=	-DENABLE_GPERF_TOOLS=ON
 LIB_DEPENDS+=	libprofiler.so:${PORTSDIR}/devel/google-perftools
.endif

.if ${PORT_OPTIONS:MREDIRECTOR}
 USE_PERL5+=	run
 CMAKE_ARGS+=	-DENABLE_REDIRECTOR=ON
 PLIST_SUB+=	REDIRECTOR=""
 USE_RC_SUBR+=	rspamd_redirector
 RUN_DEPENDS+=	\
	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
	p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
	p5-POE-Component-Client-DNS>=0:${PORTSDIR}/dns/p5-POE-Component-Client-DNS \
	p5-POE-Component-Client-HTTP>=0:${PORTSDIR}/www/p5-POE-Component-Client-HTTP \
	p5-POE-Component-Server-HTTP>=0:${PORTSDIR}/www/p5-POE-Component-Server-HTTP \
	p5-Cache-Memcached-Fast>=0:${PORTSDIR}/databases/p5-Cache-Memcached-Fast \
	p5-Proc-PidUtil>=0:${PORTSDIR}/sysutils/p5-Proc-PidUtil \
	p5-Proc-Daemon>=0:${PORTSDIR}/devel/p5-Proc-Daemon \
	p5-SWF-File>=0:${PORTSDIR}/graphics/p5-SWF-File
.else
 PLIST_SUB+=		REDIRECTOR="@comment "
.endif

post-stage:
	${INSTALL} -d \
		${STAGEDIR}/var/log/rspamd \
		${STAGEDIR}/var/db/rspamd \
		${STAGEDIR}/var/run/rspamd
		# Linux specific
		${RM} ${STAGEDIR}/${ETCDIR}/rspamd.systemd.conf
		# No need, since rspamd.conf.sample is a same
		${RM} ${STAGEDIR}/${ETCDIR}/rspamd.sysvinit.conf

.include <bsd.port.mk>
