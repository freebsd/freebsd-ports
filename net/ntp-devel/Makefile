# Created by: andreas
# $FreeBSD$

PORTNAME=	ntp
PORTVERSION=	4.2.7p475
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ntp-dev/ \
		http://archive.ntp.org/ntp4/ntp-dev/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-dev-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake
AUTOMAKE_ARGS=	--add-missing
OPTIONS_SUB=	yes
USES=		pathfix shebangfix libtool
LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

NTP_SHEBANG_FILES=	sbin/ntp-wait sbin/ntptrace

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

.if ${PORT_OPTIONS:MMX4200}
BROKEN=		Fails to compile when MX4200 is enabled.
.endif
 
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}4

AUTOTOOLSFILES=	aclocal.m4

# XXX Temporary hack. Remember to remove this next commit.
post-extract:
	@/usr/bin/touch ${WRKSRC}/scripts/build/checkHtmlFileDates
	@${CHMOD} +x ${WRKSRC}/scripts/build/checkHtmlFileDates

post-patch:
	@${REINPLACE_CMD} -e 's|1.11.1|%%AUTOMAKE_APIVER%%|g' \
			  ${WRKSRC}/aclocal.m4

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/conf/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${FIND} ${WRKSRC}/html -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@cd ${WRKSRC}/html && ${FIND} . -print | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} --quiet ${STAGEDIR}${DOCSDIR}
	@cd ${STAGEDIR}${PREFIX}; \
		${ECHO_CMD} ${NTP_SHEBANG_FILES} | ${XARGS} ${SED} -i '' ${_SHEBANG_REINPLACE_ARGS}

.include <bsd.port.post.mk>
