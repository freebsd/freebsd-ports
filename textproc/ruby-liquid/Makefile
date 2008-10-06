# New ports collection makefile for:	ruby-liquid
# Date created:		6 October 2008
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	liquid
PORTVERSION=	1.9.0
CATEGORIES=	textproc ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A non evaling template engine for ruby

USE_RUBY=	yes
NO_BUILD=	yes

SADIR=		${RUBY_SITELIBDIR}

EXAMPLES=	example.rb

do-install:
	${MKDIR} ${SADIR}/liquid/tags ${SADIR}/liquid/extras
	${INSTALL_DATA} ${WRKSRC}/lib/liquid.rb ${SADIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/liquid/*.rb ${SADIR}/liquid/
	${INSTALL_DATA} ${WRKSRC}/lib/liquid/tags/*.rb ${SADIR}/liquid/tags/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	@(cd ${WRKSRC}/example/ && \
		${COPYTREE_SHARE} \* ${RUBY_MODEXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
