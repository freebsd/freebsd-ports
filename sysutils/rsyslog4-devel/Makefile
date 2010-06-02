# New ports collection makefile for: rsyslog4
# Date created:     29 December 2008
# Whom:             Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	rsyslog
PORTVERSION=	4.6.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://download.rsyslog.com/rsyslog/
.ifdef MNAME
PKGNAMESUFFIX?=	-${MNAME}
.endif

MAINTAINER=	cristianorolim@hotmail.com
COMMENT?=	Syslogd supporting SQL, TCP and TLS

.ifdef MNAME
RUN_DEPENDS=	rsyslog>=${PORTVERSION}:${PORTSDIR}/sysutils/rsyslog4

PLIST=		${.CURDIR}/pkg-plist
.endif

NO_LATEST_LINK=	yes

CONFLICTS=	rsyslog-[!4].[0-9]*
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=--enable-rtinst --enable-debug
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 700000
BROKEN=	does not build on 6.x
.endif

.if ${ARCH} == "i386"
CPPFLAGS+=-march=i686
.endif
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.ifndef MNAME
MAN8=	rsyslogd.8
MAN5=	rsyslog.conf.5

USE_RC_SUBR=	${PORTNAME}d
SUB_FILES=	pkg-message

CONFIGURE_ARGS+=--enable-imfile --enable-mail --enable-imtemplate --enable-testbench=no

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/lib/rsyslog/|${PREFIX}/lib/rsyslog/|'\
		${WRKSRC}/tools/syslogd.c
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${FIND} ${WRKSRC} -name '*.bak' -delete

post-install:
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/*html ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/doc/*jpg ${DOCSDIR}/
.endif
.ifndef NOPORTEXAMPLES
	@${INSTALL} -d ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/rsyslog-example.conf ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}
.endif

.ifdef MNAME

.if ${MNAME} == "gssapi" && ${OSVERSION} < 700000
IGNORE=	with gssapi module is only supported on FreeBSD 7.x or later
.endif

CONFIGURE_ARGS+=	--disable-rsyslogd --disable-klog

DESCR?=		${.CURDIR}/../rsyslog4/pkg-descr
MD5_FILE?=	${.CURDIR}/../rsyslog4/distinfo
.endif

.include <bsd.port.post.mk>
