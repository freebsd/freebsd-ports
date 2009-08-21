# New ports collection makefile for:	lanmap
# Date created:		2008-08-21
# Whom:				Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lanmap
DISTVERSION=	2006-03-07-rev81
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.parseerror.com/lanmap/rev/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lanmap sits quietly on a network and builds a picture of what it sees

RUN_DEPENDS=	twopi:${PORTSDIR}/graphics/graphviz

BROKEN=		distfile no longer available
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2009-09-21

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USE_ZIP=	yes

.include <bsd.port.pre.mk>
post-extract:
	${CHMOD} 755 ${WRKSRC}/configure
.include <bsd.port.post.mk>
