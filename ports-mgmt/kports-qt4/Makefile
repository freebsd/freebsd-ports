# New ports collection makefile for:	kports
# Date created:				Thu Jan 12 12:47:58 UTC 2006
# Whom:				Hannes Hauswedell <hannes.hauswedell@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	kports
PORTVERSION=	0.6.1
CATEGORIES=	ports-mgmt kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hannes.hauswedell@gmail.com
COMMENT=	Powerful KDE-Frontend to the Ports

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:15
PREFIX=		${KDE_PREFIX}

RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade
RUN_DEPENDS+=	kdehier>=0:${PORTSDIR}/misc/kdehier

OPTIONS=	PORTAUDIT "Require Portaudit" on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		doesn't compile properly on 4.x systems
.endif

.if !defined(WITHOUT_PORTAUDIT)
RUN_DEPENDS+=	portaudit:${PORTSDIR}/ports-mgmt/portaudit
.endif

.include <bsd.port.post.mk>
