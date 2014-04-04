# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	amatch
PORTVERSION=	0.2.12
CATEGORIES=	textproc ruby
MASTER_SITES=	https://github.com/flori/amatch/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	ruby/amatch

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for approximate string matching and searching

OPTIONS_DEFINE=	DOCS

USES=		zip gmake
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	flori
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	v${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/ext
BUILD_WRKSRC=	${WRKSRC}/ext

PLIST_FILES=	bin/agrep.rb %%RUBY_SITELIBDIR%%/amatch/version.rb \
		%%RUBY_SITEARCHLIBDIR%%/amatch_ext.so
PLIST_DIRS=	%%RUBY_SITELIBDIR%%/amatch

AMATCH_RUBY=	install.rb
DOCSDIR=	${RUBY_MODDOCDIR}
PORTDOCS=	CHANGES README.rdoc

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/amatch \
		${STAGEDIR}${RUBY_SITEARCHLIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/agrep.rb \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/amatch/version.rb \
		${STAGEDIR}${RUBY_SITELIBDIR}/amatch/
	${INSTALL_DATA} ${WRKSRC}/ext/amatch_ext.so \
		${STAGEDIR}${RUBY_SITEARCHLIBDIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
