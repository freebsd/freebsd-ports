# New ports collection makefile for:	entitymib
# Date created:				9 January 2004
# Whom:					Garrett Wollman <wollman@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	entitymib
PORTVERSION=	20040109
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.mibexplorer.com/export/ietf/:mibs
MASTER_SITE_SUBDIR=	wollman
DISTFILES=	entitymib entitymib.1 ENTITY-MIB.txt:mibs
EXTRACT_ONLY=

MAINTAINER=	wollman@FreeBSD.org
COMMENT=Display the Entity MIB of an SNMP agent

RUN_DEPENDS=	${SITE_PERL}/Tree/DAG_Node.pm:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		${SITE_PERL}/${PERL_ARCH}/SNMP.pm:${PORTSDIR}/net-mgmt/net-snmp

USE_PERL5_RUN=	yes
MAN1=		entitymib.1

NO_BUILD=	nope

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/entitymib ${PREFIX}/bin/entitymib
	${INSTALL_MAN} ${DISTDIR}/entitymib.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${DISTDIR}/ENTITY-MIB.txt ${PREFIX}/share/snmp/mibs

.include <bsd.port.mk>
