# Created by: stas
# $FreeBSD$

PORTNAME=	liquid
PORTVERSION=	2.0.0
CATEGORIES=	textproc ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A non evaling template engine for ruby

USE_RUBY=	yes
NO_BUILD=	yes

SADIR=		${RUBY_SITELIBDIR}
DOCS=		CHANGELOG README.txt History.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${SADIR}/liquid/tags ${STAGEDIR}${SADIR}/liquid/extras
	${INSTALL_DATA} ${WRKSRC}/lib/liquid.rb ${STAGEDIR}${SADIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/liquid/*.rb ${STAGEDIR}${SADIR}/liquid/
	${INSTALL_DATA} ${WRKSRC}/lib/liquid/tags/*.rb ${STAGEDIR}${SADIR}/liquid/tags/
	${INSTALL_DATA} ${WRKSRC}/lib/extras/*.rb ${STAGEDIR}${SADIR}/liquid/extras/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
