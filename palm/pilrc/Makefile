# New ports collection makefile for:	PilRC
# Date created:		29 Mar 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pilrc
PORTVERSION=	2.8p5
CATEGORIES=	palm
MASTER_SITES=	http://www.hig.se/~ardiri/download/palm/

MAINTAINER=	kuriyama@FreeBSD.org

WRKSRC=		${WRKDIR}/pilrc-${PORTVERSION}

USE_GTK=	yes
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pilrc ${WRKSRC}/pilrcui ${PREFIX}/bin

.include <bsd.port.mk>
