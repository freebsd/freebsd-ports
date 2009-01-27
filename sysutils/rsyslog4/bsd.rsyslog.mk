PORTNAME?=	rsyslog
PORTVERSION?=	4.1.3
CATEGORIES?=	sysutils
MASTER_SITES?=	http://download.rsyslog.com/rsyslog/
MAINTAINER?=	cristianorolim@hotmail.com

CONFLICTS=	rsyslog-[2-3].[0-9]*
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.ifdef MNAME
PKGNAMESUFFIX?=	-${MNAME}
CONFIGURE_ARGS+=	--disable-rsyslogd --disable-klog
RUN_DEPENDS=	rsyslog>=4:${PORTSDIR}/sysutils/rsyslog4

DESCR?=		${.CURDIR}/../rsyslog4/pkg-descr
MD5_FILE?=	${.CURDIR}/../rsyslog4/distinfo
.endif
