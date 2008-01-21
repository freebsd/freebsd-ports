# New ports collection makefile for:	msn-proxy
# Date created:			20 January 2008
# Whom:				Luiz Otavio O Souza <loos.br@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	msn-proxy
PORTVERSION=	0.5
CATEGORIES=	net-im
MASTER_SITES=	SF
#DISTNAME=	msn-proxy-${PORTVERSION}

MAINTAINER=	loos.br@gmail.com
COMMENT=	Messenger proxy/control daemon

LIB_DEPENDS=	event:${PORTSDIR}/devel/libevent

USE_MYSQL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
DOCS=		INSTALL

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.endif

.include <bsd.port.mk>
