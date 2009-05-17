# New ports collection makefile for:	mod_auth_useragent
# Date created:				Apr 16 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_useragent
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://download.tangent.org/ \
		http://sheepkiller.nerim.net/ports/${PORTNAME}/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows you to forbid clients based on their User-Agent

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
PORTDOCS=	README faq.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
