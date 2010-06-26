# New ports collection makefile for:	tknetmon
# Date created:				2006 Nov 01
# Whom:					vfom@narod.ru
#
# $FreeBSD$
#

PORTNAME=	tknetmon
PORTVERSION=	2.0.7a
PORTREVISION=	5
CATEGORIES=	net-mgmt
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://vfom.narod.ru/download/
DISTNAME=	TkNetmon-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI for network monitoring tool "netmond" ( net-mgmt/netmond )

BUILD_DEPENDS=	tclsh8.4:${PORTSDIR}/lang/tcl84
RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84 \
		${LOCALBASE}/lib/libBLT24.so.3:${PORTSDIR}/x11-toolkits/blt \
		${LOCALBASE}/lib/Tktable2.10/libTktable2.10.so:${PORTSDIR}/x11-toolkits/tktable \
		${LOCALBASE}/lib/tcl8.4/sql1.0/libTclMySQL.so.1:${PORTSDIR}/databases/tcl-Mysql \
		${LOCALBASE}/lib/snack2.2/libsnack.so:${PORTSDIR}/audio/snack \
		${LOCALBASE}/bin/snmpget:${PORTSDIR}/net-mgmt/net-snmp \
		${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping

BROKEN=		conflicting dependencies (tcl-Mysql brings in tcl85)

DOCSDIR=	${PREFIX}/share/doc/TkNetmon
EXAMPLESDIR=	${PREFIX}/share/examples/TkNetmon

PLIST_SUB+=	PORTNAME=TkNetmon PORTVERSION=${PORTVERSION}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
