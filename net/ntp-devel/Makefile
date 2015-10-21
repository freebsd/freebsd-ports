# Created by: andreas
# $FreeBSD$

PORTNAME=	ntp
PORTVERSION=	4.3.76
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ntp-dev/ \
		http://archive.ntp.org/ntp4/ntp-dev/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-dev-${PORTVERSION:S/P/p/:S/r/-RC/:S/b/-beta/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

CONFLICTS=	ntp-[0-9].* ntp-rc-*

GNU_CONFIGURE=	yes
OPTIONS_SUB=	yes
USES=		cpe pathfix shebangfix libedit libtool pkgconfig
LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

SHEBANG_FILES=	scripts/ntptrace/ntptrace.in \
		scripts/ntp-wait/ntp-wait.in \
		scripts/update-leap/update-leap.in
perl_OLD_CMD=	@PATH_PERL@

.include "Makefile.inc"

PERL_UTILS_USES=	perl5

SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_OFF=	--without-crypto

IPV6_CONFIGURE_ENABLE=	ipv6

NTP_SIGND_CONFIGURE_ENABLE=	ntp-signd

NTPSNMPD_LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
NTPSNMPD_CONFIGURE_OFF=	--without-ntpsnmpd

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-openssl-incdir=${OPENSSLINC} \
			--with-openssl-libdir=${OPENSSLLIB}
.endif

.for D in ${NTP_DRIVERS}
.if ${PORT_OPTIONS:M${D}}
CONFIGURE_ARGS+=	--enable-${D}
.endif
.endfor

# XXX Temporary hack. Remember to remove this next commit.
post-extract:
	@/usr/bin/touch ${WRKSRC}/scripts/build/checkHtmlFileDates
	@${CHMOD} +x ${WRKSRC}/scripts/build/checkHtmlFileDates

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/conf/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${FIND} ${WRKSRC}/html -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@cd ${WRKSRC}/html && ${FIND} . -print | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} --quiet ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
