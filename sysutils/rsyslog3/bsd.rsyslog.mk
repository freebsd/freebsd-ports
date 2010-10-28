PORTNAME?=	rsyslog
PORTVERSION?=	3.22.2
CATEGORIES?=	sysutils
MASTER_SITES?=	http://www.rsyslog.com/files/download/rsyslog/
MAINTAINER?=	miwi@FreeBSD.org

CONFLICTS=	rsyslog-[!3].[0-9]*
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_GNOME+=	pkgconfig

.ifdef MNAME
PKGNAMESUFFIX?=	-${MNAME}
LATEST_LINK=	rsyslog3${PKGNAMESUFFIX}
CONFIGURE_ARGS+=	--enable-${MNAME:S|gssapi|gssapi-krb5|} \
			--disable-rsyslogd --disable-klog
RUN_DEPENDS=	rsyslog>=${PORTVERSION}:${PORTSDIR}/sysutils/rsyslog3
PLIST_FILES=	${MTYPES:S|^|lib/rsyslog/|:S|$|${MNAME}.so|}
PLIST=	""
DESCR?=		${.CURDIR}/../rsyslog3/pkg-descr
DISTINFO_FILE?=	${.CURDIR}/../rsyslog3/distinfo

do-install:
	@${INSTALL} -d ${PREFIX}/lib/rsyslog/
.for _T in ${MTYPES}
	@${INSTALL_PROGRAM} \
		${WRKSRC}/plugins/${_T}${MNAME}/.libs/${_T}${MNAME}.so \
		${PREFIX}/lib/rsyslog/
.endfor
	@${ECHO_CMD} '@unexec rmdir %D/lib/rsyslog 2>/dev/null || true' >> ${TMPPLIST}
.else
LATEST_LINK=	rsyslog3
.endif
