# New ports collection makefile for:	libtlen
# Date created:		25 September 2003
# Whom:			Piotr Smyrak <smyru@heron.pl> and
#                       Maciek Korzen <eaquer@ceti.pl>
#
# $FreeBSD$
#

PORTNAME=	libtlen
PORTVERSION=	20041113
CATEGORIES=	polish net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	smyru@heron.pl
COMMENT=	Backend for interoperability with Tlen.pl, Polish IM network

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in libtlen.html libtlen.css AUTHORS TODO
	@${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
