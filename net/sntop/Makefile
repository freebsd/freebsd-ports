# New ports collection makefile for:	sntop
# Date created:		05 August 2000
# Whom:			Matt Emmerton <matt@gsicomp.on.ca>
#
# $FreeBSD$
#

PORTNAME=	sntop
PORTVERSION=	1.3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sntop

MAINTAINER=	matt@gsicomp.on.ca

RUN_DEPENDS=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping

GNU_CONFIGURE=	yes

MAN1=		sntop.1
MANCOMPRESSED=	yes

post-install:
	@strip ${PREFIX}/bin/sntop
	@cat ${PKGMESSAGE}

.include <bsd.port.mk>
