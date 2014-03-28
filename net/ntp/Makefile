# Created by: andreas
# $FreeBSD$

PORTNAME=	ntp
PORTVERSION?=	4.2.6p5
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ \
		ftp://ftp.archive.de.uu.net/pub/unix/ntp/ntp4/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/ntp/ntp4/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/P/p/:S/.r/-RC/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

FORBIDDEN=	CVE-2013-5211 / VU#348126
LATEST_LINK=	${PORTNAME}

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake libtool

MAN1=		sntp.1 \
		ntpd.1 \
		ntpdc.1 \
		ntpq.1 \
		ntpsnmpd.1 \
		ntp-keygen.1 \

.include "Makefile.inc"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNTPSNMPD}
PLIST_FILES+=		bin/ntpsnmpd
BUILD_DEPENDS+=		${LOCALBASE}/include/net-snmp/net-snmp-config.h:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS+=		${LOCALBASE}/include/net-snmp/net-snmp-config.h:${PORTSDIR}/net-mgmt/net-snmp
.else
CONFIGURE_ARGS+=	--without-ntpsnmpd
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl-incdir=${OPENSSLINC} \
			--with-openssl-libdir=${OPENSSLLIB}
PLIST_SUB+=		SSL=""
.else
CONFIGURE_ARGS+=        --without-crypto
PLIST_SUB+=             SSL="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=        --enable-ipv6
.endif

.if ${PORT_OPTIONS:MNTP_SIGND}
CONFIGURE_ARGS+=        --enable-ntp-signd
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${FIND} ${WRKSRC}/html -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@cd ${WRKSRC}/html && ${FIND} . -print | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} --quiet ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
