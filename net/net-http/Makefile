# ex:ts=8
# New ports collection makefile for:	net-http
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	net-http
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES= 	http://evan.prodromou.san-francisco.ca.us/software/net-http/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

do-install:
	@${MKDIR} ${LOCALBASE}/share/guile/1.4/net
	${INSTALL_DATA} ${WRKSRC}/net/http.scm ${LOCALBASE}/share/guile/1.4/net

.include <bsd.port.mk>
