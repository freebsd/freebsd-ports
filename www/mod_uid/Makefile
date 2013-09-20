# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_uid
PORTVERSION=	1.1.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.lexa.ru/pub/apache-rus/contrib/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A module issuing the "correct" cookies for counting the site visitors


USE_APACHE=	22

PORTDOCS=	README.html

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} == 13
MODULENAME=	mod_uid
.else
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
