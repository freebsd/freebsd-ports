# New ports collection makefile for:	libpcap
# Date created:		10 December 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpcap
PORTVERSION=	0.8.1
PORTREVISION=	352
CATEGORIES=	net
MASTER_SITES=	http://www.tcpdump.org/beta/
DISTNAME=	${PORTNAME}-${PORTVERSION}-351

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Ubiquitous network traffic capture library

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:${PORTSDIR}/devel/bison

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN3=		pcap.3

GNU_CONFIGURE=	yes

.if defined(LIBPCAP_OVERWRITE_BASE)
PREFIX=		/usr
PKGNAMESUFFIX=	-overwrite-base
MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=--mandir=${MANPREFIX}/man
PLIST_SUB+=	NOTBASE="@comment "
PLIST_SUB+=	BASE=""
EXTRA_PATCHES+=	${FILESDIR}/patchbase-Makefile.in
PKGMESSAGE=	${FILESDIR}/pkg-message-base
.else
PLIST_SUB+=	BASE="@comment "
PLIST_SUB+=	NOTBASE=""
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !defined(WITH_DAG)
CONFIGURE_ARGS+=	--without-dag
.endif

.if defined(LIBPCAP_OVERWRITE_BASE)
post-install:
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
