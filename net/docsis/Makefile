# New ports collection makefile for:	docsis
# Date created:				Jul 5, 2002
# Whom:					James Flemer <jflemer@acm.jhu.edu>
#
# $FreeBSD$
#

PORTNAME=	docsis
PORTVERSION=	0.7.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-RELEASE
EXTRACT_SUFX=	.tgz

MAINTAINER=	jflemer@acm.jhu.edu

LIB_DEPENDS=	snmp.4:${PORTSDIR}/net/net-snmp4

USE_OPENSSL=	yes
USE_BISON=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/docsis ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
