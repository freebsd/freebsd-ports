# New ports collection makefile for:    annextools
# Date created:         17 September 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=       annextools
PORTVERSION=	10.0
PORTREVISION=	0
CATEGORIES=     net-mgmt
MASTER_SITES=   ftp://ftp-support.baynetworks.com/pub/swcode/remacc/microannex_xl/
DISTNAME=	R10.0B-R2.3
EXTRACT_SUFX=	.tar.Z
DIST_SUBDIR=	microannex_xl

MAINTAINER=     bms@FreeBSD.org
COMMENT=	BSD tools for the MicroAnnex-XL Terminal Server

WRKSRC=		${WRKDIR}/src

EXTRACT_AFTER_ARGS= | ${TAR} -xf - src

post-extract:
	${FIND} ${WRKDIR}/src -type d -exec ${CHMOD} u+w \{\} \;

do-install:
	${MKDIR} ${PREFIX}/annex/sbin ${PREFIX}/annex/snmp ${PREFIX}/annex/examples
	${INSTALL_PROGRAM} ${WRKSRC}/erpcd/acplint ${PREFIX}/annex/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/erpcd/ch_passwd ${PREFIX}/annex/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/erpcd/erpcd ${PREFIX}/annex/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/erpcd/spy ${PREFIX}/annex/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/erpcd/tms_convert ${PREFIX}/annex/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/erpcd/tms_dbm ${PREFIX}/annex/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/na/na ${PREFIX}/annex/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/rtelnet/rtelnet ${PREFIX}/annex/sbin
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo-anx.mib ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo-callmgmt.mib ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo-modem.mib ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo-ports.mib ${PREFIX}/annex/snmp

	${INSTALL_DATA} ${WRKSRC}/snmp/xylo-protocol.mib ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo-trpobj.mib ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo-wan.mib ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo.cap ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo.smi ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/snmp/xylo.trp ${PREFIX}/annex/snmp
	${INSTALL_DATA} ${WRKSRC}/examples/misc/laser ${PREFIX}/annex/examples
	${INSTALL_DATA} ${WRKSRC}/examples/misc/lprinterface ${PREFIX}/annex/examples
	${INSTALL_DATA} ${WRKSRC}/examples/misc/macro1 ${PREFIX}/annex/examples
	${INSTALL_DATA} ${WRKSRC}/examples/misc/macro2 ${PREFIX}/annex/examples
	${INSTALL_DATA} ${WRKSRC}/examples/misc/map3270 ${PREFIX}/annex/examples
	${INSTALL_DATA} ${WRKSRC}/examples/misc/modem.configs ${PREFIX}/annex/examples
	${INSTALL_DATA} ${WRKSRC}/examples/misc/rotary ${PREFIX}/annex/examples
	${INSTALL_DATA} ${WRKSRC}/examples/misc/termcap ${PREFIX}/annex/examples

.include <bsd.port.mk>
