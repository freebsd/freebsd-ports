# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_cvs
PORTVERSION=	0.5.91
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://resare.com/noa/mod_cvs/dist/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A module that makes Apache 2 CVS aware


LATEST_LINK=	mod_cvs2

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	reference.html guide.html README

NO_STAGE=	yes
post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.   for f in ${PORTDOCS:NREADME}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}/
.   endfor
.endif

.include <bsd.port.mk>
