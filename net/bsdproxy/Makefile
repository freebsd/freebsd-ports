# New ports collection makefile for:	bsdproxy
# Date created:		2 November 2001
# Whom:			roam@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	bsdproxy
PORTVERSION=	0.03
CATEGORIES=	net
MASTER_SITES=	http://daveb.net/bsdproxy/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A TCP proxy, demonstrating use of the kevent(2)/kqueue(2) API

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12

GNU_CONFIGURE=	yes

DOCS=		README

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
