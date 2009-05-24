# New ports collection makefile for:	ntp
# Date created:		Di   5 Mai 1998 21:31:03 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	ntp
PORTVERSION=	4.2.5p179
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ntp-dev/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ntp-dev/ \
		ftp://ftp.archive.de.uu.net/pub/unix/ntp/ntp4/ntp-dev/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/ntp/ntp4/ntp-dev/
DISTNAME=	${PORTNAME}-dev-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

LATEST_LINK=	${PORTNAME}-dev

GNU_CONFIGURE=	yes

MAN1=		sntp.1

.if defined(ENABLE_RAWDCF)
CONFIGURE_ARGS+=	--enable-RAWDCF
.endif

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--without-crypto
PLIST_SUB+=		SSL="@comment "
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl-incdir=${OPENSSLINC} \
			--with-openssl-libdir=${OPENSSLLIB}
PLIST_SUB+=		SSL=""
.endif

.if !defined(DISABLE_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

MAN1=		ntp-keygen.1 ntpd.1 ntpdc.1 ntpq.1 sntp.1

pre-everything::
	@${ECHO}
	@${ECHO} If you wish to build this port with SNMP support, please make
	@${ECHO} sure that the net-mgmt/net-snmp port is installed before
	@${ECHO} building and installing this port.
	@${ECHO}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/net-snmp-config)
# NTP autodects net-snmp and if found builds and installs a binary that
# uses it. If detected, modify dependencies and package list.
BUILD_DEPENDS=	${LOCALBASE}/bin/net-snmp-config:${PORTSDIR}/net-mgmt/net-snmp
LIB_DEPENDS=	netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp
MAN1+=		ntpsnmpd.1
PLIST_SUB+=	NETSNMP=""
.else
PLIST_SUB+=	NETSNMP="@comment "
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/conf/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${FIND} ${WRKSRC}/html -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@cd ${WRKSRC}/html && ${FIND} . -print | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} --quiet ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
