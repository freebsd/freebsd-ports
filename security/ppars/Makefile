# New ports collection makefile for:	ppars
# Date created:		2004-06-29
# Whom:			Joe Barbish <fbsd_user@a1poweruser.com>
#
# $FreeBSD$
#

PORTNAME=	ppars
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.dshield.org/clients/
DISTNAME=	${PORTNAME}

MAINTAINER=	fbsd_user@a1poweruser.com
COMMENT=	Proactive Probing Abuse Reporting System

RUN_DEPENDS=	${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 490000
IGNORE=		"Not supported on releases prior to 4.9"
.endif

do-install:
	@${MKDIR} ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${PREFIX}/sbin
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
