# New ports collection makefile for:	rinetd
# Date created:				23 Dec 1997
# Whom:					alexp
#
# $FreeBSD$
#

PORTNAME=	rinetd
PORTVERSION=	0.62
CATEGORIES=	net
MASTER_SITES=	http://www.boutell.com/rinetd/http/
DISTNAME=	rinetd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple TCP port redirector

WRKSRC=		${WRKDIR}/rinetd/

MAN8=		rinetd.8
PORTDOCS=	index.html README
PLIST_FILES=	sbin/rinetd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
