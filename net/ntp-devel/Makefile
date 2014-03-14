# Created by: andreas
# $FreeBSD$

PORTNAME=	ntp
PORTVERSION=	4.2.7p411
CATEGORIES=	net ipv6
PKGNAMESUFFIX=	-devel
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ntp-dev/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ntp-dev/ \
		ftp://ftp.archive.de.uu.net/pub/unix/ntp/ntp4/ntp-dev/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/ntp/ntp4/ntp-dev/
DISTNAME=	${PORTNAME}-dev-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake libtool
AUTOMAKE_ARGS=	--add-missing
USES=		pathfix
LIB_DEPENDS=	libevent-2.0.so:${PORTSDIR}/devel/libevent2

.include "Makefile.inc"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl-incdir=${OPENSSLINC} \
			--with-openssl-libdir=${OPENSSLLIB}
PLIST_SUB+=		SSL=""
.else
CONFIGURE_ARGS+=	--without-crypto
PLIST_SUB+=		SSL="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MNTP_SIGND}
CONFIGURE_ARGS+=	--enable-ntp-signd
.endif

.if ${PORT_OPTIONS:MNTPSNMPD}
PLIST_FILES+=		sbin/ntpsnmpd
PLIST_SUB+=		NTPSNMPD=""
BUILD_DEPENDS+=		${LOCALBASE}/include/net-snmp/net-snmp-config.h:${PORTSDIR}/net-mgmt/net-snmp
LIB_DEPENDS=		libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS+=		${LOCALBASE}/include/net-snmp/net-snmp-config.h:${PORTSDIR}/net-mgmt/net-snmp
.else
CONFIGURE_ARGS+=	--without-ntpsnmpd
PLIST_SUB+=		NTPSNMPD="@comment "
.endif

.for D in ${NTP_DRIVERS}
.if ${PORT_OPTIONS:M${D}}
CONFIGURE_ARGS+=	--enable-${D}
.endif
.endfor

.if ${PORT_OPTIONS:MMX4200}
BROKEN=		Fails to compile when MX4200 is enabled.
.endif
 
.include <bsd.port.pre.mk>

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}4

pre-everything::
	@${ECHO}
	@${ECHO} If you wish to build this port with SNMP support, please make
	@${ECHO} sure that the net-mgmt/net-snmp port is installed before
	@${ECHO} building and installing this port.
	@${ECHO}

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

.include <bsd.port.post.mk>
