# New ports collection makefile for:	sntop
# Date created:		05 August 2000
# Whom:			Matt Emmerton <matt@gsicomp.on.ca>
#
# $FreeBSD$
#

PORTNAME=	sntop
PORTVERSION=	1.4.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sntop

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor status of network nodes using fping

RUN_DEPENDS=	${LOCALBASE}/sbin/fping:${PORTSDIR}/net/fping

GNU_CONFIGURE=	yes

MAN1=		sntop.1

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/sntop
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
