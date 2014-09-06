# Created by: andreas
# $FreeBSD$

PORTNAME=	ntp
PORTVERSION?=	4.2.6p5
PORTREVISION=	3
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ \
		ftp://ftp.archive.de.uu.net/pub/unix/ntp/ntp4/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/ntp/ntp4/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/P/p/:S/.r/-RC/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

FORBIDDEN=	CVE-2013-5211 / VU\#348126 - Please use net/ntp-devel, pending upstream stable branch update.
LATEST_LINK=	${PORTNAME}

USES=		libtool shebangfix
SHEBANG_FILES=	${WRKSRC}/scripts/ntptrace.in ${WRKSRC}/scripts/ntp-wait.in
perl_OLD_CMD=	@PATH_PERL@
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake
OPTIONS_SUB=	yes

.include "Makefile.inc"

NTPSNMPD_PLIST_FILES=	bin/ntpsnmpd
NTPSNMPD_BUILD_DEPENDS=	${LOCALBASE}/include/net-snmp/net-snmp-config.h:${PORTSDIR}/net-mgmt/net-snmp
NTPSNMPD_RUN_DEPENDS=	${LOCALBASE}/include/net-snmp/net-snmp-config.h:${PORTSDIR}/net-mgmt/net-snmp
NTPSNMPD_CONFIGURE_OFF=	--without-ntpsnmpd

SSL_USE=		OPENSSL=yes
SSL_CONFIGURE_OFF=	--without-crypto

IPV6_CONFIGURE_ENABLE=	ipv6

NTP_SIGND_CONFIGURE_ENABLE=	ntp-signd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--with-openssl-incdir=${OPENSSLINC} \
			--with-openssl-libdir=${OPENSSLLIB}
.endif

.for D in ${NTP_DRIVERS}
.if ${PORT_OPTIONS:M${D}}
CONFIGURE_ARGS+=	--enable-${D}
.endif
.endfor

AUTOTOOLSFILES=	aclocal.m4

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

.include <bsd.port.mk>
