# New ports collection makefile for:    mod_uid
# Date created:				02 December 2003
# Whom:					Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_uid
PORTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.lexa.ru/pub/apache-rus/contrib/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A module issuing the "correct" cookies for counting the site visitors

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3+

PORTDOCS=	README.html

.if !defined(APACHE_PORT) || ${APACHE_PORT} == "www/apache13"
MODULENAME=	mod_uid
.else
MODULENAME=	mod_uid2
.endif

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
