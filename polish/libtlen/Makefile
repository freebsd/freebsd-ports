# New ports collection makefile for:	libtlen
# Date created:		25 September 2003
# Whom:			Piotr Smyrak <smyru@heron.pl> and
#                       Maciek Korzen <eaquer@ceti.pl>
#
# $FreeBSD$
#

PORTNAME=	libtlen
PORTVERSION=	20030721
CATEGORIES=	polish net
MASTER_SITES=	http://www.libtlen.eu.org/snapshots/archive/

MAINTAINER=	smyru@heron.pl
COMMENT=	Backend for interoperability with Tlen.pl, Polish IM network

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in libtlen.html libtlen.css AUTHORS TODO
	@${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
