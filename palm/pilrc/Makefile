# New ports collection makefile for:	PilRC
# Date created:		29 Mar 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilrc
PORTVERSION=	2.9p9
PORTREVISION=	1
CATEGORIES=	palm
MASTER_SITES=	http://www.ardiri.com/download/files/palm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Resource compiler for Pilot applications

WRKSRC=		${WRKDIR}/pilrc-${PORTVERSION}

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pilrc ${WRKSRC}/pilrcui ${PREFIX}/bin

.include <bsd.port.mk>
