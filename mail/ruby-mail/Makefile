# New ports collection makefile for:	RubyMail
# Date created:		16 January 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mail
PORTVERSION=	0.4
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.lickey.com/%SUBDIR%/
MASTER_SITE_SUBDIR=	ruby${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/bin/*.rb

post-extract:
	${FIND} ${WRKSRC} -type f -name 'heaer*' -delete

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/mail
	${INSTALL_DATA} ${WRKSRC}/mail/* ${RUBY_SITELIBDIR}/mail/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${WRKSRC}/README ${RUBY_DOCDIR}/${PORTNAME}/
	${CP} -R ${WRKSRC}/doc/* ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
