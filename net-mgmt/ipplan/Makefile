# Ports collection makefile for:  ipplan
# Date created:			  26 Nov 2004
# Whom:				  Maxim Tuliuk <mt@primats.org.ua>
#
# $FreeBSD$
#

PORTNAME=	ipplan
PORTVERSION=	4.0.2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	iptrack
DISTNAME=	${PORTNAME}-4.02

MAINTAINER=	mt@primats.org.ua
COMMENT=	IP address management and tracking

USE_PHP=	gettext
USE_MYSQL=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
IPPLANDIR?=	share/${PORTNAME}
PLIST_SUB=	IPPLANDIR=${IPPLANDIR}

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/${IPPLANDIR}
	@${CP} -R ${WRKSRC}/* ${PREFIX}/${IPPLANDIR}
	@${FIND} ${PREFIX}/${IPPLANDIR} -name '*.orig' -delete
	@${SED} -e 's|%IPPLANDIR%|${PREFIX}/${IPPLANDIR}|g' ${PKGMESSAGE}

.include <bsd.port.mk>
