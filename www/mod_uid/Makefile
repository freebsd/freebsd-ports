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

USE_APACHE=	13-20

PORTDOCS=	README.html

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

.include <bsd.port.pre.mk>

.if !defined(APACHE_PORT) || ${APACHE_VERSION} == "13"
MODULENAME=	mod_uid
.else
IGNORE=		does not build with latest apache20/22
MODULENAME=	mod_uid2
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
