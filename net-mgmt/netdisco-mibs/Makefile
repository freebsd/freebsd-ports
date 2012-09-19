# New ports collection makefile for:	netdisco-mibs
# Date created:		2012-02-10
# Whom:			Geoffroy Desvernay <dgeo@centrale-marseille.fr>
#
# $FreeBSD$
#

PORTNAME=	netdisco-mibs
PORTVERSION=	1.0
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/netdisco/netdisco-mibs/${PORTVERSION}

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Mibs for use with ports-mgmt/netdisco (and snmp)

NO_BUILD=	yes

.include "bsd.port.netdisco.mk"

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${DATADIR})
	${INSTALL_SCRIPT} ${FILESDIR}/mkindex ${DATADIR}
.	for mibdir in ${MIBDIRS}
		(cd ${DATADIR}/${mibdir} && ${GREP} 'DEFINITIONS ::= BEGIN' *.* | ${SED} 's/\(.*\..*\):[[:space:]]*\(.*\) DEFINITIONS.*$$/\2 \1/' > .index)
.	endfor
	(cd ${DATADIR} && ${SH} ./mkindex)

.include <bsd.port.mk>
