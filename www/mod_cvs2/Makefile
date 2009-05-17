# New ports collection makefile for:	mod_cvs2
# Date created:				6 January 2003
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_cvs
PORTVERSION=	0.5.91
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://resare.com/noa/mod_cvs/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A module that makes Apache 2 CVS aware

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0+

LATEST_LINK=	mod_cvs2

PORTDOCS=	reference.html guide.html README

do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -i -A -n ${PORTNAME:S/mod_//} ${PORTNAME}.la)
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.   for f in ${PORTDOCS:NREADME}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
