PORTNAME?=	rsyslog
PORTVERSION?=	3.22.0
CATEGORIES?=	sysutils
MASTER_SITES?=	http://download.rsyslog.com/rsyslog/
MAINTAINER?=	miwi@FreeBSD.org

NO_LATEST_LINK=	yes
CONFLICTS=	rsyslog-2.[0-9]*
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GNOME+=	pkgconfig

.ifdef MNAME
PKGNAMESUFFIX?=	-${MNAME}
CONFIGURE_ARGS+=	--enable-${MNAME:S|gssapi|gssapi-krb5|} \
			--disable-rsyslogd --disable-klog
RUN_DEPENDS=	rsyslog>=3:${PORTSDIR}/sysutils/rsyslog3
PLIST_FILES=	${MTYPES:S|^|lib/rsyslog/|:S|$|${MNAME}.so|}
PLIST=	""
DESCR?=		${.CURDIR}/../rsyslog3/pkg-descr
MD5_FILE?=	${.CURDIR}/../rsyslog3/distinfo

PORTSCOUT=	skipv:3.21.10,3.21.9,3.21.8,3.21.7,3.21.6,3.21.5,3.21.4,3.21.3,3.21.2,3.21.1,3.21.0

do-install:
	@${INSTALL} -d ${PREFIX}/lib/rsyslog/
.for _T in ${MTYPES}
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/${_T}${MNAME}/.libs/${_T}${MNAME}.so \
		${PREFIX}/lib/rsyslog/
.endfor
	@${ECHO_CMD} '@unexec rmdir %D/lib/rsyslog 2>/dev/null || true' >> ${TMPPLIST}
.endif # def MNAME
