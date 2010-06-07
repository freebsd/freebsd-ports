# New ports collection makefile for:	ntp
# Date created:		Di   5 Mai 1998 21:31:03 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	ntp
PORTVERSION?=	4.2.6p1.r5
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/ \
		ftp://ftp.archive.de.uu.net/pub/unix/ntp/ntp4/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/ntp/ntp4/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/P/p/:S/.r/-RC/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

LATEST_LINK=	${PORTNAME}

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:110 libtool:22

MAN1=		sntp.1 \
		ntpd.1 \
		ntpdc.1 \
		ntpq.1 \
		ntpsnmpd.1 \
		ntp-keygen.1 \

OPTIONS=	NTPSNMPD "Build and install ntpsnmpd" OFF \
		RAWDCF "Enable RAWDCF option" OFF \
		SSL "Enable SSL" ON

.include <bsd.port.pre.mk>

.if defined(WITH_RAWDCF)
CONFIGURE_ARGS+=	--enable-RAWDCF
.endif

.if !defined(WITH_SSL)
CONFIGURE_ARGS+=	--without-crypto
PLIST_SUB+=		SSL="@comment "
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl-incdir=${OPENSSLINC} \
			--with-openssl-libdir=${OPENSSLLIB}
PLIST_SUB+=		SSL=""
.endif
CONFIGURE_ARGS+=	--enable-ipv6

.if defined(WITH_NTPSNMPD)
PLIST_FILES+=		bin/ntpsnmpd
BUILD_DEPENDS+=		${LOCALBASE}/include/net-snmp/net-snmp-config.h:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS+=		${LOCALBASE}/include/net-snmp/net-snmp-config.h:${PORTSDIR}/net-mgmt/net-snmp
.else
CONFIGURE_ARGS+=	--without-ntpsnmpd
.endif

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

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
