# ex:ts=8
# New ports collection makefile for:	net-http
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	net-http
PORTVERSION=	0.3.1
CATEGORIES=	net
MASTER_SITES= 	http://evan.prodromou.san-francisco.ca.us/software/net-http/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A library for doing HTTP client-side programming in Guile

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	${CP} -R ${WRKSRC}/net/ ${LOCALBASE}/share/guile/1.4.1/net/

.include <bsd.port.mk>
