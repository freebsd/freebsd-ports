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

USE_APACHE=	yes
DOCS=		README.html

.if defined(WITH_APACHE2)
MOD=		mod_uid2
.else
MOD=		mod_uid
.endif

do-build:
	@cd ${WRKSRC} && ${APXS} -c ${MOD}.c

do-install:
	${APXS} -i -A -n uid ${WRKSRC}/${MOD}.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
