# New ports collection makefile for:	rspamd
# Date created:		2010-09-27
# Whom:			Vsevolod Stakhov <vsevolod@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rspamd
PORTVERSION=	0.3.8
CATEGORIES=	mail
MASTER_SITES=	http://highsecure.ru/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Fast spam filtering system

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		gmime-2.0:${PORTSDIR}/mail/gmime2 \
		event-1.4:${PORTSDIR}/devel/libevent

OPTIONS=	RSPAMD_GPERF "Enable google perf-tools profiling" off \
		RSPAMD_JUDY "Enable Judy arrays usage for performance" off \
		RSPAMD_REDIRECTOR "Install HTTP redirector" off

USE_RC_SUBR=	rspamd

LICENSE=	BSD

PLIST_SUB+=	ETCDIR=etc/rspamd \
		RSPAMDVERSION=${PORTVERSION}
CMAKE_ARGS+=	-DETC_PREFIX=${PREFIX}/etc -DPREFIX=${PREFIX} \
		-DBUILD_PORT=yes

USE_CMAKE=	yes
USE_LDCONFIG=	yes

USE_GNOME=	glib20
USE_LUA=	5.1-

MAN8=	rspamd.8
MAN1=	rspamc.1

.include <bsd.port.pre.mk>

.if defined(WITH_RSPAMD_GPERF)
 CMAKE_ARGS+=	-DENABLE_GPERF_TOOLS=ON
 LIB_DEPENDS+=	profiler.1:${PORTSDIR}/devel/google-perftools
.endif

.if defined(WITH_RSPAMD_JUDY)
 LIB_DEPENDS+=	Judy:${PORTSDIR}/devel/judy
.endif

.if defined(WITH_RSPAMD_REDIRECTOR)
 USE_PERL=	5.8+
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
	p5-Digest-SHA256>=0:${PORTSDIR}/security/p5-Digest-SHA256 \
	p5-SWF-File>=0:${PORTSDIR}/graphics/p5-SWF-File
.else
 PLIST_SUB+=		REDIRECTOR="@comment "
.endif

.include <bsd.port.post.mk>
