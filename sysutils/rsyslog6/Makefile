# $FreeBSD$

PORTNAME=	rsyslog
PORTVERSION=	6.6.0
PORTREVISION?=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rsyslog.com/files/download/rsyslog/
.ifdef MNAME
PKGNAMESUFFIX?=	-${MNAME}
.endif

MAINTAINER=	brd@FreeBSD.org
COMMENT?=	Syslogd supporting SQL, TCP, and TLS

USE_LDCONFIG=	yes

LIB_DEPENDS+=	ee:${PORTSDIR}/devel/libee \
		estr:${PORTSDIR}/devel/libestr \
		sysinfo:${PORTSDIR}/devel/libsysinfo \
		json.0:${PORTSDIR}/devel/json-c/ \
		uuid:${PORTSDIR}/misc/e2fsprogs-libuuid

.ifdef MNAME
RUN_DEPENDS=	rsyslog>=${PORTVERSION}:${PORTSDIR}/sysutils/rsyslog6
PLIST=		${.CURDIR}/pkg-plist
LATEST_LINK=	rsyslog6-${MNAME}
.else
LATEST_LINK=	rsyslog6
.endif

PORTSCOUT=	limit:^6

.ifdef WITH_MYSQL_MICROSECONDS
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-mysql-microseconds
.endif

.ifdef WITH_SANE_HOSTNAME
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sane-hostname
.endif

CONFLICTS=	rsyslog-[57].[0-9]*
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=--enable-rtinst --enable-debug
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CPPFLAGS+=-march=i686
.endif

CONFIGURE_ENV+=	LIBESTR_CFLAGS="${CFLAGS}" LIBESTR_LIBS="${LDFLAGS} -lestr" LIBEE_CFLAGS="${CFLAGS}" LIBEE_LIBS="${LDFLAGS} -lee -lsysinfo -lkvm"
CFLAGS+=	${CPPFLAGS}

.ifndef MNAME
MAN8=	rsyslogd.8
MAN5=	rsyslog.conf.5

USE_RC_SUBR=	${PORTNAME}d
SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--enable-imfile --enable-mail --enable-imdiag --enable-impstats --enable-omstdout

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/lib/rsyslog/|${PREFIX}/lib/rsyslog/|'\
		${WRKSRC}/tools/syslogd.c
	@${GREP} -rl '/etc/rsyslog.conf' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e\
		's|/etc/rsyslog.conf|${PREFIX}/etc/rsyslog.conf|'
	@${REINPLACE_CMD} -e 's,/lib/rsyslog,${PREFIX}/lib/rsyslog,' ${WRKSRC}/tools/syslogd.c
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

CONFIGURE_ARGS+=	--disable-rsyslogd --disable-klog --disable-testbench --disable-omruleset

DESCR?=		${.CURDIR}/../rsyslog6/pkg-descr
DISTINFO_FILE?=	${.CURDIR}/../rsyslog6/distinfo
.endif

.if ${OSVERSION} < 700042
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
