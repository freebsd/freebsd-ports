# New ports collection makefile for:	bing
# Version required:	1.0.4
# Date created:		28 December 1996
# Whom:			jseger@scds.com
#
# $Id$
#

DISTNAME=	bing-1.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibp.fr/pub/networking/

MAINTAINER=	jseger@scds.com

MAN8= 		bing.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/bing
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/bing
.endif

.include <bsd.port.mk>
