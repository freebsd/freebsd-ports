# New ports collection makefile for:	enet
# Date created:		2006-09-23
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	enet
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://enet.bespin.org/download/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Simple and robust communication library based on UDP

GNU_CONFIGURE=	yes
DOCS=		design.txt docs/FAQ.dox docs/design.dox docs/tutorial.dox

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
