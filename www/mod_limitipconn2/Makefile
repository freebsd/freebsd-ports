# New ports collection makefile for:	mod_limitipconn2
# Date created:				18 November 2003
# Whom:					Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mod_limitipconn
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dominia.org/djao/limit/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Allows you to limit the number of simultaneous connexions

MAKE_JOBS_SAFE=	yes

LATEST_LINK=	mod_limitipconn2

USE_APACHE=	2.0+
USE_BZIP2=	YES

AP_AST_BUILD=	yes
AP_GENPLIST=	yes

PLIST_FILES+=	${APACHEMODDIR}/${PORTNAME}.so

PORTDOCS=	ChangeLog INSTALL README

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.   endfor
.endif

.include <bsd.port.mk>
