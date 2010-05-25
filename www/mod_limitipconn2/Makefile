# New ports collection makefile for:	mod_limitipconn2
# Date created:				18 November 2003
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mod_limitipconn
PORTVERSION=	0.23
CATEGORIES=	www
MASTER_SITES=	http://dominia.org/djao/limit/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Allows you to limit the number of simultaneous connexions

MAKE_JOBS_SAFE=  yes

LATEST_LINK=	mod_limitipconn2

USE_APACHE=	2.0+
USE_BZIP2=	YES

PORTDOCS=	ChangeLog INSTALL README

do-build:
	@(cd ${WRKSRC} && ${APXS} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -i -A -n ${PORTNAME:S/mod_//} ${PORTNAME}.la)

.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
