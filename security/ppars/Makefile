# Created by: Joe Barbish <fbsd_user@a1poweruser.com>
# $FreeBSD$

PORTNAME=	ppars
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.dshield.org/clients/
DISTNAME=	${PORTNAME}

MAINTAINER=	fbsd_user@a1poweruser.com
COMMENT=	Proactive Probing Abuse Reporting System

RUN_DEPENDS=	p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask

USES=		perl5

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${PREFIX}/sbin
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
