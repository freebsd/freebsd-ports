# Created by: andreas
# $FreeBSD$

PORTNAME=	ntp
PORTVERSION=	4.3.99
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ntp-dev/ \
		http://archive.ntp.org/ntp4/ntp-dev/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-dev-${PORTVERSION:S/P/p/:S/r/-RC/:S/b/-beta/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

FORBIDDEN=	See http://support.ntp.org/bin/view/Main/SecurityNotice#March_2020_ntp_4_2_8p14_NTP_Rele

LIB_DEPENDS=	libevent.so:devel/libevent

CONFLICTS=	ntp-[0-9].* openntpd-*

USES=		cpe pathfix shebangfix libedit libtool localbase:ldflags \
		pkgconfig gettext-runtime
USES+=		autoreconf # until rlimit_memlock changes accepted upstream


LIB_DEPENDS+=	libdns_sd.so:net/mDNSResponder

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-leap-smear --enable-trustedbsd-mac \
		--with-locfile=freebsd --with-memlock=-1

TEST_TARGET=	check

SHEBANG_FILES=	scripts/ntptrace/ntptrace.in \
		scripts/ntp-wait/ntp-wait.in \
		scripts/update-leap/update-leap.in
perl_OLD_CMD=	@PATH_PERL@

SUB_FILES=	pkg-message

.include "Makefile.inc"

OPTIONS_DEFINE+=	DEBUG NLS THREADS
OPTIONS_DEFAULT+=	THREADS
OPTIONS_SUB=		yes

IPV6_CONFIGURE_ENABLE=	ipv6

NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_OFF=	ac_cv_lib_intl_gettext=no
NLS_USES=		gettext-runtime

NTP_SIGND_CONFIGURE_ENABLE=	ntp-signd

NTPSNMPD_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
NTPSNMPD_CONFIGURE_OFF=	--without-ntpsnmpd

PERL_UTILS_USES=	perl5

SSL_CONFIGURE_ON=	--with-openssl-incdir=${OPENSSLINC} \
			--with-openssl-libdir=${OPENSSLLIB}
SSL_CONFIGURE_OFF=	--without-crypto
SSL_USES=		ssl
SSL_BROKEN_OFF=		Includes OpenSSL when deselected

DEBUG_CONFIGURE_ON=	--enable-debug

THREADS_CONFIGURE_ENABLE=	thread-support
THREADS_CONFIGURE_WITH=		threads

.for D in ${NTP_DRIVERS}
${D}_CONFIGURE_ENABLE=	${D}
.endfor

.include <bsd.port.pre.mk>

# XXX Temporary hack. Remember to remove this next commit.
post-extract:
	@${TOUCH} ${WRKSRC}/scripts/build/checkHtmlFileDates
	@${CHMOD} +x ${WRKSRC}/scripts/build/checkHtmlFileDates

post-configure:
	@${ECHO_CMD} '#define HAVE_CLOSEFROM        1' >> ${WRKSRC}/config.h

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${FIND} ${WRKSRC}/html -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@cd ${WRKSRC}/html && ${FIND} . -print | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} --quiet ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
